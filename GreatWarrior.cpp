#ifndef _GreatWarrior_
#define _GreatWarrior_

#include "GreatWarrior.h"
#include "main.cpp"
#include <iostream>
#include <ctime>

//////////////////////////////////
/*          <Ramal_Seyidli>         */
/*          <150180901>           */
//////////////////////////////////


//////////////////////////
//	Land members
/////////////////////////

//Constructor of Land class
Land::Land(string name, string holding)
{
	strcpy(this->name,name);	//assign input name to the object's name
	strcpy(this->holding,holding);	//assign input holding to the object's holding
	this->next = NULL;
}


//Copy Constructor of Land class
Land::Land(Land& obj_in)
{
	strcpy(name,obj_in.name);
	strcpy(holding,obj_in.holding);
	this->next = obj_in.next;
}

Land::~Land()
{
	delete next;
}


//////////////////////////
//	Character members
/////////////////////////


//Constructor of Character class
Character::Character(string name, int manpower, int gold, int numOfLands)
{
	this->name = name;
	this->manpower = manpower;
	this->gold = gold;
	this->numOfLands = numOfLands;
	this->lands = NULL;
}

//Constructor for general

Character::Character(string name)
{
	this->name = name;
}

//Destructor of Character class
Character::~Character()
{
	delete lands;
}


//addLand function of Character

Character::addLand(Land& land)
{
	if (numOfLands == 0)	//for the first node
	{
		lands = &land;
		lands->nextGetter = NULL;
	}
	else            //for other nodes
	{
		Land* iter = lands;
		for (int i = 0; i < numOfLands; i++)
		{
			iter = iter->nextGetter();
		}
		iter->nextGetter = &land;
		iter = iter->nextGetter;
		iter->nextGetter = NULL;
	}
}

void Character::removeLand(Land& land)	//to remove lands
{
	if (rebellion)
	{
		srand((unsigned)time(NULL));
		int random = (rand() % (6 - 4)) + 4;

		Land* iter = lands;

		if (random != 1)
		{
			for (int i = 0; i < random - 1; i++) {
				iter = iter->nextGetter();
			}
			iter->nextGetter() = iter->nextGetter()->nextGetter();
		}
		else
		{
			lands = lands->nextGetter();
		}
	}
	else
	{
		//i will write here after game loop 3
	}
}

void Character::getTaxes(Character& obj)
{
	Land* iter = obj.lands;	//write getter func, returns this->lands, obj.getter()

	for (int i = 0; i < numOfLands; i++)
	{
		if (iter->holdingGetter() == "village")	//do the same with holding obj.getholding()
		{
			obj.goldSetter(obj.goldGetter() + 5);
		}
		else if (iter->holdingGetter() == "castle")
		{
			obj.goldSetter(obj.goldGetter() + 7);
		}
		else if (iter->holdingGetter() == "city")
		{
			obj.goldSetter(obj.goldGetter() + 10);
		}
		iter = iter->nextGetter(); //nextGetter(), which returns Land
	}
}





//////////////////////////
//	CharacterList members
/////////////////////////



//Constructor of CharacterList
CharacterList::CharacterList()
{
	size = 0;
	characters = NULL;
}

//Destructor of CharacterList
CharacterList::~CharacterList()
{
	delete[] characters;
}

void CharacterList::addCharacter(Character& character)
{
	size++;
	if (size == 1) {
		characters = new Character[size];
		characters[0] = &character;
	}
	else {
		Character* temp = characters;
		characters = new Characters * [size];
		for (int i = 0; i < size - 1; i++) {
			characters[i] = temp[i];
		}
		characters[size - 1] = &character;
		delete[] temp;
	}
}

void CharacterList::delCharacter(string &charName)
{
	int foundIndex = -1;
	for (int i = 0; i < size; i++) {
		if (characters[i]->nameGetter().compare(charName) == 0) 
		{
			foundIndex = i;
		}
		if (foundIndex == -1) {
			// did not find character
			return;
		}

		Character* temp = characters;
		characters = new Characters * [size - 1];
		for (int i = 0, j = 0; j < size; i++, j++) {
			if (j == foundIndex) {
				characters[i] = temp[++j];
			}
			else {
				characters[i] = temp[j];
			}
		}
		delete temp;
	}
}


string CharacterList::getLandOwner(string& charName)
{
	for (int i = 0; i < size; i++)
	{
		Land* iter = characters[i]->landsGetter();
		for (int j = 0; j < characters[i]->numOfLandsGetter(); j++)
		{
			if (iter->nameGetter().compare(charName) == 0)
			{
				return iter->nameGetter();
			}
			else
			{
				iter = iter->nextGetter();
			}
		}
	}
}




#endif