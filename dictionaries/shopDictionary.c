//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

private mapping alwaysGenerate = ([
    "weapon":([
        "dagger":({ "dagger", "dirk", "knife", "stiletto" }),
        "sword":({ "bastard-sword", "broad-sword", "claymore", "long-sword", "short-sword" }),
        "staff":({ "quarterstaff", "shield-staff", "staff", "swordstaff" }),
        "axe":({ "axe", "battle-axe", "bearded-axe", "hatchet", "broad-axe", "splitting-maul" }),
        "pole-arm":({ "bardiche", "brandistock", "glaive", "halberd", "lance", "military-fork", "pike", "pitchfork", "spear", "trident" }),
        "hammer":({ "horsemans-pick", "lucerne-hammer", "maul", "war-hammer" }),
        "mace":({ "club", "flanged-mace", "mace", "morning-star" }),
        "flail":({ "flail", "whip", "military-flail", "hinged-flail" }),
        "crossbow":({ "crossbow", "levered-crossbow", "cranequin-crossbow" }),
        "bow":({ "short-bow", "bow", "long-bow", "recurve-bow", "composite-bow"}),
        "sling":({ "kestros", "sling", "slingshot", "sling-staff" }),
        "thrown":({ "dart", "javelin", "rock", "throwing-axe", "throwing-hammer", "throwing-spear" }),
        "shield":({ "shield", "buckler", "heater-shield", "kite-shield", "spiked-shield", "pavise-shield" })
    ]),
    "armor":([
        "medium armor":({ "chainmail", "boiled-leather", "hard-leather", "lamellar-leather", "ring-mail"}),
        "light armor":({ "gambeson", "soft-leather", "leather-jacket", "padded-armor", "leather-arm-greaves", "leather-leg-greaves"}),
        "heavy armor":({ "breastplate", "brigandine", "plate-armor", "scale-armor", "splint-mail", "plate-leg-greaves", "plate-arm-greaves"}),
        "clothing":({ "cloak", "robes", "dress", "shirt", "pants", "skirt", "gown"}),
        "accessories":({ "belt", "boots", "helmet" }),
    ])
]);

/////////////////////////////////////////////////////////////////////////////
public nomask string *getSellItemTypes(object user)
{
    string *ret = ({});

    object *items = deep_inventory(user) - 
        user->registeredInventoryObjects();

    if (sizeof(items))
    {
        foreach(object item in items)
        {
            if (member(ret, item->query("type")) < 0)
            {
                ret += ({ item->query("type") });
            }
        }
    }
    return ret - ({ 0 });
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int valueModifier(object user, object item, int selling)
{
    int ret = item->query("value");

    float multiplier = 0.05 + (user->charismaBonus() / 20.0);
    if (user->getSkill("bluff"))
    {
        multiplier += (user->getSkillModifier("bluff") / 100.0);
    }
    if (user->getSkill("intimidation"))
    {
        multiplier += (user->getSkillModifier("intimidation") / 100.0);
    }
    if (user->getSkill("persuasion"))
    {
        multiplier += (user->getSkillModifier("persuasion") / 100.0);
    }
    if (user->getSkill("barter"))
    {
        multiplier += (user->getSkillModifier("barter") / 25.0);
    }
    if (multiplier > 0.85)
    {
        multiplier = 0.85;
    }
    if (!selling)
    {
        multiplier = 1.6 - multiplier;
    }

    if (multiplier < 0.05)
    {
        multiplier = 0.05;
    }

    ret = to_int(ret * multiplier);
    return (!selling || (ret < 25000)) ? ret : 25000;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getSellItemDetailsForType(object user, string type, object store)
{
    mapping ret = ([]);
    int menuItem = 1;

    object *items = filter_array(deep_inventory(user) -
        user->registeredInventoryObjects(),
        (: (($1->query("type") == $2) && !$3->isModifierItem($1)) :), 
        type, user);

    object materials = load_object("/lib/dictionaries/materialsDictionary.c");
    if (sizeof(items))
    {
        foreach(object item in items)
        {
            int value = valueModifier(user, item, 1);
            string valueStr = value ?
                sprintf("[0;32mYou can sell this item for %d.[0m\n", value) :
                "[0;32mThis item has no value to the merchant.[0m\n";

            string name = item->query("name") + "    ";
            ret[to_string(menuItem)] = ([
                "name": sprintf(materials->getMaterialQualityFormatter(item),
                    ((sizeof(name) > 20) ? name[0..16] + "..." : name)),
                "identified": item->query("identified"),
                "object list": ({ item }),
                "description": item->long() + valueStr,
                "value": value
            ]);

            if (user->isEquipped(item))
            {
                ret[to_string(menuItem)]["is equipped"] = 1;
            }
            if (item->query("no sell") || !store->canPurchaseItem(item))
            {
                ret[to_string(menuItem)]["do not sell"] = 1;
            }
            if (item->query("identified") && item->query("cursed"))
            {
                ret[to_string(menuItem)]["known cursed item"] = 1;
            }
            else if(item->query("cursed"))
            {
                ret[to_string(menuItem)]["unknown cursed item"] = 1;
            }
            menuItem++;
        }

        ret[to_string(menuItem)] = ([
            "name": "Sell all" + 
                ((member(({ "armor", "weapon", "instrument" }), type) > -1) ?
                    " unequipped" : ""),
            "description": "This option will sell all of your unequipped " + type,
            "object list": filter_array(items, 
                (: (!$2->isEquipped($1) && !$1->query("cursed") &&
                   !$1->query("no sell")) :), user)
        ]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void moveNestedItemsToUser(object user, object item)
{
    object *nestedItems = all_inventory(item);
    if (sizeof(nestedItems))
    {
        foreach(object nestedItem in nestedItems)
        {
            move_object(nestedItem, user);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void sellItems(object user, object store, object *items)
{
    int money = 0;
    if (sizeof(items))
    {
        foreach(object item in items)
        {
            moveNestedItemsToUser(user, item);

            if (user->isEquipped(item))
            {
                item->unequip(item->query("name"), 1);
            }

            // If the item's still equipped, it can't be sold
            if (!user->isEquipped(item))
            {
                money += valueModifier(user, item, 1);
                tell_object(user, sprintf("[0;32mYou sell %s.[0m\n",
                    item->query("name")));
                store->storeItem(item);
                destruct(item);
            }
        }
    }
    if (money)
    {
        user->addMoney(money);
    }
    tell_object(user, sprintf("[0;37mYou received $%d for your sold items.[0m\n",
        money));
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateDefaultItems(object shop)
{
    string type = shop->shopType();
    string subType = shop->shopSubType();

    string dir = sprintf("/lib/instances/items/%s%s/", type + "s",
        ((subType != "all") ? "/" + regreplace(subType, " ", "-", 1)
            + ((subType != "thrown") ? "s" : "") : ""));

    string *defaultItems = ({});
    if (member(alwaysGenerate, type) && member(alwaysGenerate[type], subType))
    {
        defaultItems = alwaysGenerate[type][subType];
    }
    if (sizeof(defaultItems))
    {
        foreach(string itemName in defaultItems)
        {
            object item = clone_object(sprintf("%s%s.c", dir, itemName));
            item->identify();
            shop->storeItem(item, 1);
            destruct(item);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *bonusList(object item)
{
    string *bonuses = ({ "bonus strength", "bonus intelligence", "bonus dexterity",
        "bonus wisdom", "bonus constitution", "bonus charisma", "bonus armor class",
        "bonus defense class", "bonus attack", "bonus soak", "bonus defense",
        "bonus spell points", "bonus stamina points", "bonus heal hit points rate",
        "bonus heal hit points", "bonus heal spell points", "bonus hit points",
        "bonus heal spell points rate", "bonus heal stamina",
        "bonus heal stamina rate", "damage reflection",
        "bonus defense class", "bonus damage", "bonus weapon attack" });

    if (item->query("weapon type"))
    {
        bonuses += ({ item->query("weapon type") });
    }
    else if (item->query("armor type"))
    {
        bonuses += ({ item->query("armor type") });
    }
    else 
    {
        bonuses += 
            load_object("/lib/dictionaries/skillsDictionary.c")->validBonusSkills();
    }
    return bonuses;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int addEnchantment(object item)
{
    int ret = 0;

    string *enchantments = ({ "acid", "air", "chaos", "cold", "earth", "electricity",
        "energy", "fire", "magical", "poison", "water", "undead", "good", "evil" });

    string enchantType = "enchantments";
    if (item->query("armor type") ||
        (!item->query("weapon type") && random(2)))
    {
        enchantType = "resistances";
    }

    if (!item->query(enchantType))
    {
        string enchantment = enchantments[random(sizeof(enchantments))];
        item->set(enchantType, ([
            enchantment: (1 + random(5))
        ]));
        item->set("name", sprintf("%s of %s", item->query("name"), capitalize(enchantment)));
        item->set("short", sprintf("%s of %s", item->query("short"), capitalize(enchantment)));
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateRandomItems(object shop)
{
    int numItems = shop->randomItemsToGenerate();
    string dir = sprintf("/lib/instances/items/%s%s/", 
        shop->shopType() + "s", ((shop->shopSubType() != "all") ? 
            "/" + shop->shopSubType() + "s" : ""));

    string *itemBlueprints = get_dir(dir);

    if (sizeof(itemBlueprints))
    {
        object materials = load_object("/lib/dictionaries/materialsDictionary.c");

        for (int i = 0; i < numItems; i++)
        {
            object item = clone_object(sprintf("%s%s", dir,
                itemBlueprints[random(sizeof(itemBlueprints))]));

            int numEnchantments = 1 + random(5);
            item->set("material", materials->getRandomMaterial(item));

            for (int j = 0; j < numEnchantments; j++)
            {
                switch (random(3))
                {
                    case 0:
                    case 1:
                    {
                        if(addEnchantment(item))
                        {
                            break;
                        }   
                    }
                    default:
                    {
                        string *bonuses = bonusList(item);

                        item->set(bonuses[random(sizeof(bonuses))],
                            (1 + random(3)));
                    }
                }
                if (!random(4))
                {
                    item->set("craftsmanship",
                        materials->getRandomCraftsmanshipBonus(item));
                }
            }
            item->identify();
            shop->storeItem(item);
            destruct(item);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void generateRandomInventory(object shop)
{
    if (shop->shopSubType() != "all")
    {
        generateRandomItems(shop);
    }
    generateDefaultItems(shop);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getBuyItemTypes(object store)
{
    string *types = ({});
    mapping inventory = store->storeInventory();
    string *inventoryItems = m_indices(inventory);

    if (sizeof(inventoryItems))
    {
        foreach(string item in inventoryItems)
        {
            string itemType = inventory[item]["type"];
            if (member(inventory[item], "subType") &&
                inventory[item]["subType"])
            {
                itemType += "s - " + 
                    capitalize(inventory[item]["subType"]);
            }
            if (member(types, itemType) < 0)
            {
                types += ({ itemType });
            }
        }
    }
    return types;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBuyItemDetailsForType(object store, string type, string subtype)
{
    mapping inventory = store->storeInventory();
    string *itemList = m_indices(filter_mapping(inventory,
        (: (($2[$1]["type"] == $3) && 
           (($4 == "all") || ($2[$1]["subType"] == $4))) :), 
            inventory, type, subtype));
    mapping ret = ([]);
    if (sizeof(itemList))
    {
        itemList = sort_array(itemList, (: $1 > $2 :));
        int menuItem = 1;
        foreach(string item in itemList)
        {
            string valueStr = sprintf("[0;32mYou can buy this item for %d.[0m\n",
                inventory[item]["value"]);

            string qualityFormat = regreplace(inventory[item]["quality"],
                "(.*)%s(.*)", "\\1%-23s\\2", 1);
            ret[to_string(menuItem)] = ([
                "name": sprintf("%s [0;32m%8d[0m",
                    sprintf(qualityFormat, 
                    ((sizeof(inventory[item]["name"]) <= 23) ? inventory[item]["name"] :
                        inventory[item]["name"][0..19] + "...")),
                    inventory[item]["value"]),
                "description": inventory[item]["description"] + valueStr,
                "data": inventory[item]["data"],
                "value": inventory[item]["value"],
                "summary": inventory[item]["summary"],
                "blueprint": regreplace(item, "([^#]+)#.*", "/\\1.c", 1),
                "key": item
            ]);
            menuItem++;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void buyItem(object user, object store, mapping item)
{
    int money = 0;
    if (sizeof(item) && member(item, "blueprint") &&
        member(item, "value") && member(item, "data"))
    {
        if (user->Money() >= item["value"])
        {
            object itemObj = clone_object(item["blueprint"]);
            itemObj->set("all", item["data"]);
            user->addMoney(-item["value"]);
            store->buyItem(item["key"]);
            move_object(itemObj, user);
            tell_object(user, sprintf("[0;32mYou purchased %s for $%d.[0m\n",
                itemObj->query("name"), item["value"]));
        }
        else
        {
            tell_object(user, "[0;32mYou do not have the funds for that.[0m\n");
        }
    }
}