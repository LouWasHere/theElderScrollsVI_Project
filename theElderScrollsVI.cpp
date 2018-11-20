#include<iostream>      //All the libraries I used.
#include<string>
#include<vector>
#include<cstdlib>
#include<stdlib.h>
using namespace std;

int power(int, int)      //This function is a dependency for stoint(), and is just a simpler way to calculate powers.

int stoint(string)       //This is the function I used to convert string to integer.

int menuVerification(int, string) //general function for ANY menu.

int chooseYourCharacter()

int screenSet()

int main()
{
    int characterStrength;
    int characterAgility;
    int characterIntelligence;
    int characterEndurance;
    int characterCharisma;
    int characterHealth;
    int characterStamina;
    int characterMagika;
    int characterSpeech;
    int characterSpeed;
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
    bool title = true;
    string characterName;
    string skillTree;
    vector<string>skills;
    switch(chooseYourCharacter())
    {
    case 1:
        characterStrength = 8;
        characterAgility = 3;
        characterIntelligence = 4;
        characterEndurance = 7;
        characterCharisma = 9;
    break;
    case 2:
        characterStrength = 7;
        characterAgility = 7;
        characterIntelligence = 5;
        characterEndurance = 6;
        characterCharisma = 8;
    break;
    case 3:
        characterStrength = 6;
        characterAgility = 9;
        characterIntelligence = 8;
        characterEndurance = 5;
        characterCharisma = 6;
    break;
    case 4:
        characterStrength = 5;
        characterAgility = 8;
        characterIntelligence = 9;
        characterEndurance = 6;
        characterCharisma = 7;
    break;
    case 5:
        characterStrength = 7;
        characterAgility = 8;
        characterIntelligence = 4;
        characterEndurance = 4;
        characterCharisma = 2;
    break;
    case 6:
        characterStrength = 6;
        characterAgility = 7;
        characterIntelligence = 8;
        characterEndurance = 6;
        characterCharisma = 5;
    break;
    case 7:
        characterStrength = 9;
        characterAgility = 2;
        characterIntelligence = 3;
        characterEndurance = 8;
        characterCharisma = 3;
    break;
    }
    screenSet(title, characterName, characterStrength, characterAgility, characterIntelligence, characterEndurance, characterCharisma);
    cout<<"What is your name, traveller?\n\n";
    getline(cin,characterName);
    title = false;
    screenSet(title, characterName, characterStrength, characterAgility, characterIntelligence, characterEndurance, characterCharisma);
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
    P

    if(title = true)
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
        cout<<"------------------------     "<<characterName<<"     ------------------------\n";
        cout<<"------------------------------------------------------------------------------\n";
    }
}
