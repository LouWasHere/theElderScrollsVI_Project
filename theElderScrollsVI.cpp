#include<iostream>      //All the libraries I used.
#include<string>
#include<vector>
#include<cstdlib>
#include<stdlib.h>
#include <ctime>
using namespace std;

class player
{
    public:
        int characterStrength;
        int characterAgility;
        int characterIntelligence;
        int characterEndurance;
        int characterCharisma;
        int characterHealth;
        int characterStamina;
        int characterMagika;
        int characterSpeed;
        int skillSpeech;
        int skillOneHanded;
        int skillTwoHanded;
        int skillBowAccuracy;
        int skillShield;
        int skillPickpocketing;
        int skillSneak;
        int skillThrownWeapons;
        int skillStatusCondition;
        int skillAnimalHandling;
        int skillLockpicking;
        int characterLevel;
        string action;
        string characterName;
        string province;
        bool title;
};

player player;





class enemy
{
    public:
        int enemyLevel = player.characterLevel;
};

enemy enemy;

class magicEnemy : public enemy
{
    public:
        string name = "Magical Bandit";
        int skillStatusCondition = enemyLevel * 5;
        int spellDamage = enemyLevel * 5;
};

class meleeEnemy : public enemy
{
    public:
        string name = "Fisticuffs Bandit";
        int skillUnarmed = enemyLevel * 6;
        int hitDamage = enemyLevel * 4;
};

class armedEnemy : public enemy
{
    public:
        string name = "Swordsman Bandit";
        int skillOneHanded = enemyLevel * 4;
        int weaponDamage = enemyLevel * 7;
};

class wolfEnemy : public enemy
{
    public:
        string name = "Wolf";
        int skillUnarmed = enemyLevel * 8;
        int hitDamage = enemyLevel * 3;
};

magicEnemy magicEnemy;

meleeEnemy meleeEnemy;

armedEnemy armedEnemy;

wolfEnemy wolfEnemy;

void wildlandsRandomEncounter();

void travel();

void openInventory();

void openMap();

int power(int, int);      //This function is a dependency for stoint(), and is just a simpler way to calculate powers.

int stoint(string);      //This is the function I used to convert string to integer.

int menuVerification(int, string); //general function for ANY menu.

int chooseYourCharacter();

int screenSet();

int wildlandsAction();

int main()
{
    player.title = true;
    string null;
    switch(chooseYourCharacter())
    {
    case 1:
        player.characterStrength = 8;
        player.characterAgility = 3;
        player.characterIntelligence = 4;
        player.characterEndurance = 7;
        player.characterCharisma = 9;
    break;
    case 2:
        player.characterStrength = 7;
        player.characterAgility = 7;
        player.characterIntelligence = 5;
        player.characterEndurance = 6;
        player.characterCharisma = 8;
    break;
    case 3:
        player.characterStrength = 6;
        player.characterAgility = 9;
        player.characterIntelligence = 8;
        player.characterEndurance = 5;
        player.characterCharisma = 6;
    break;
    case 4:
        player.characterStrength = 5;
        player.characterAgility = 8;
        player.characterIntelligence = 9;
        player.characterEndurance = 6;
        player.characterCharisma = 7;
    break;
    case 5:
        player.characterStrength = 7;
        player.characterAgility = 8;
        player.characterIntelligence = 4;
        player.characterEndurance = 4;
        player.characterCharisma = 2;
    break;
    case 6:
        player.characterStrength = 6;
        player.characterAgility = 7;
        player.characterIntelligence = 8;
        player.characterEndurance = 6;
        player.characterCharisma = 5;
    break;
    case 7:
        player.characterStrength = 9;
        player.characterAgility = 2;
        player.characterIntelligence = 3;
        player.characterEndurance = 8;
        player.characterCharisma = 3;
    break;
    }
    screenSet();
    cout<<"What is your name, traveller?\n\n";
    getline(cin,player.characterName);
    player.characterHealth = ((player.characterEndurance + player.characterStrength)*10);
    player.characterStamina = ((player.characterStrength + player.characterAgility)*10);
    player.characterMagika = ((player.characterIntelligence + player.characterStrength)*10);
    player.characterSpeed = ((player.characterAgility + player.characterEndurance)*10);
    player.skillSneak = ((player.characterAgility)*10);
    player.skillSpeech = ((player.characterCharisma + player.characterIntelligence)*5);
    player.skillLockpicking = (((player.skillSneak/10)+player.characterAgility)*5);
    player.skillBowAccuracy = ((player.characterAgility)*10);
    player.skillOneHanded = ((player.characterAgility + player.characterStrength)*5);
    player.skillTwoHanded = ((player.characterStrength + (player.characterSpeed/20))*5);
    player.skillStatusCondition = (((player.characterMagika/20) + player.characterIntelligence)*5);
    player.skillPickpocketing = player.skillSneak;
    player.skillAnimalHandling = ((player.characterCharisma + player.characterAgility)*5);
    player.skillThrownWeapons = ((player.characterAgility + (player.characterSpeed/20))*5);
    player.skillShield = ((player.characterStrength + (player.characterStamina/20))*5);
    player.characterLevel = 1;
    player.title = false;
    player.province = "Hammerfell";
    wildlandsAction();
}

int power(int base, int index)      //This function is a dependency for stoint(), and is just a simpler way to calculate powers.
{
    int output = 1;
    for(int i = 0; i < index; i++)
    {
        output = output*base;
    }
    return output;
}

int stoint(string number)       //This is the function I used to convert string to integer.
{
    int output = 0;
    for(int i = number.size() - 1; i>=0; i--)
    {
        if(number.substr(i, 1) == "0")      //Uses Substring to isolate a single character in the string.
        {
            output = output + 0 * power(10, number.size() - i - 1);     //Sets the character to the appropriate power of the output depending on its position in the string.
        }
        if(number.substr(i, 1) == "1")
        {
            output = output + 1 * power(10, number.size() - i - 1);
        }
        if(number.substr(i, 1) == "2")
        {
            output = output + 2 * power(10, number.size() - i - 1);
        }
        if(number.substr(i, 1) == "3")
        {
            output = output + 3 * power(10, number.size() - i - 1);
        }
        if(number.substr(i, 1) == "4")
        {
            output = output + 4 * power(10, number.size() - i - 1);
        }
        if(number.substr(i, 1) == "5")
        {
            output = output + 5 * power(10, number.size() - i - 1);
        }
        if(number.substr(i, 1) == "6")
        {
            output = output + 6 * power(10, number.size() - i - 1);
        }
        if(number.substr(i, 1) == "7")
        {
            output = output + 7 * power(10, number.size() - i - 1);
        }
        if(number.substr(i, 1) == "8")
        {
            output = output + 8 * power(10, number.size() - i - 1);
        }
        if(number.substr(i, 1) == "9")
        {
            output = output + 9 * power(10, number.size() - i - 1);
        }
    }
    return output;      //Return the Output.
}

int menuVerification(int maxValue, string menuInput) //general function for ANY menu.
{
    int menuInputInt = stoint(menuInput);       //Convert the menu input to an integer.
    if(menuInputInt > maxValue || menuInputInt < 1)     //See if the input is within the boundaries.
    {
        cout<<"\nSorry, that was invalid. Please enter a number from 1 to "<<maxValue<<".\n";
        getline(cin, menuInput);
        menuVerification(maxValue, menuInput);      //Input another attempt.
    }
    else
    {
        return menuInputInt;        //Return the value in case it changed. Also returns as integer to be used in a Switch statement.
    }
}

int chooseYourCharacter()
{
    string race;
    cout<<"Welcome to the world of Tamriel, and the many provinces it contains.\n\n";
    cout<<"Please select a Race.\n\n";
    cout<<"1:Nord \n\n2:Redguard \n\n3:Wood Elf \n\n4:High Elf \n\n5:Dark Elf/Dwemer \n\n6:Kajhit \n\n7:Orc\n";
    getline(cin,race);
    return menuVerification(7, race);
}

int screenSet()
{
    if(player.title == true)
    {
        system("CLS");
        cout<<"------------------------------------------------------------------------------\n";
        cout<<"------------------------     THE ELDER SCROLLS VI     ------------------------\n";
        cout<<"------------------------------------------------------------------------------\n";
    }
    else
    {
        system("CLS");
        cout<<"------------------------------------------------------------------------------\n";
        cout<<"------------ HP: "<<player.characterHealth<<" ------------   "<<player.characterName<<"   ------------ Mk: "<<player.characterMagika<<" -----------\n";
        cout<<"------------------------------------------------------------------------------\n";
        cout<<"------ Strength: "<<player.characterStrength<<" Endurance: "<<player.characterEndurance<<" Charisma: "<<player.characterCharisma<<" Intelligence: "<<player.characterIntelligence<<" Agility: "<<player.characterAgility<<" -------\n\n\n";
    }
}

int wildlandsAction()
{
    screenSet();
    cout<<"You are in the wildlands of the province of "<<player.province<<". \n\n";
    cout<<"You can:\n\n1. Look for something to fight.\n\n2. Travel\n\n3. Check Inventory\n\n4. Check Map\n\n";
    getline(cin, player.action);
    switch(menuVerification(4, player.action))
    {
    case 1:
        wildlandsRandomEncounter();
    break;
    case 2:
        travel();
    break;
    case 3:
        openInventory();
    break;
    case 4:
        openMap();
    break;
    }
}

void wildlandsRandomEncounter()
{
    screenSet();
    srand(time(0));
    cout<<(rand()%5)+1;

}

void travel()
{
    screenSet();
    cout<<"Would you like to travel:\n\n1. Nearest Town\n\n2. Cross Border\n\n";
    getline(cin,player.action);
    switch(menuVerification(2,player.action));
    {
    case 1:
        if(player.province = "Hammerfell")
        {
            dragonstone();
        }
        if(player.province = "Skryim")
        {
            winterhold();
        }
        if(player.province = "Morrowind")
        {

        }
        if(player.province = "Summerset")
        {

        }
    break;
    case 2:

    break;
    }
}

void openInventory()
{
    screenSet();

}

void openMap()
{
    screenSet();

}
