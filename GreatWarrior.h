#ifndef _GreatWarrior_
#define _GreatWarrior_
#include <string>

//////////////////////////////////
/*          <Ramal_Seyidli>         */
/*          <150180901>           */
//////////////////////////////////

using namespace std;

class Land	//class for Lands
{
public:
	Land(string, string);	//Contructor
	Land(Land&);	//Copy Constructor
	~Land();
	Land *nextGetter()	//added to get private attribute next
	{
		return next;	
	}
	string nameGetter()		//added to get private attribute name
	{
		return name;
	}
	string holdingGetter()		//added to get private attribute holding
	{
		return holding;
	}

	
private:
	string name;	//name attribute
	string holding;	//holding attribute
	Land* next;		//next pointer for lands linked list
};


class Character
{
public:
	Character(string, int, int, int);	//Constructor
	Character(string);	//the second constructor for general
	~Character();	//Destructor
	void getTaxes();	//function to increase gold by collecting taxes
	void addLand(Land &);		// adds Land to the linked list
	void removeLand(Land &);		//removes the land from the linked list
	string nameGetter()	//added to use private data name
	{
		return name;
	};
	int numOfLandsGetter() {
		return numOfLands;
	}
	Land* landsGetter(){
		return lands;
	}
	int manpowerGetter()
	{
		return manpower;
	}
	void manpowerSetter(int &number)
	{
		manpower = number;
	}
	int goldGetter()
	{
		return gold;
	}
	void goldSetter(int &n)
	{
		gold = n;
	}


private:
	string name;
	int manpower;
	int gold;
	int numOfLands;
	Land* lands;
};



class CharacterList
{
public:
	CharacterList(int, Character);
	~CharacterList();
	void addCharacter(Character &); //array ile hoqqa ver
	void delCharacter(string &);
	Character *getPlayer; 
	void getLandOwner();
	friend void listCharacters(CharacterList &);
	friend void listLands(CharacterList &);
	int sizeGetter()
	{
		return size;
	}
	Character charactersGetter()
	{
		return characters;
	}

private:
	int size;
	Character* characters;
};
	


#endif 

