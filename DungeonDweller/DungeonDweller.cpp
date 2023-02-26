#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>

using namespace std;

//Player Int
int player_health = 100;
int player_attack = 10;
int player_gold = 0;

//Player Int 2 (For adding new health and gold)
int player_new_health;
int new_gold;	

//Strings
string player_name;
string input;
map<string, int > player_inventory;
map<string, int> player_weapons;

//String removing the file extension
string playerNameWithoutExt = player_name.substr(0, player_name.find_last_of("."));

//Char
char currentLocation = 'H'; // starting location of the dungeon
char direction;
char restart;

//Voids (Functions)
void mainMenu();
void startMenu();
void exploreDungeon();
void showInstructions();
void showAbout();
void fightMonsterA();
void fightMonsterC();
void showInventory();
void showPlayerInfo();
void showMap();

//Room Functions
void roomB();
void roomD();

//Quit Function
void quit();

//The start of everything
int main()
{
	cout << "-----------------------------\n";
	cout << "Welcome to Dungeon Dweller!!! \n";
	cout << "-----------------------------\n";

	cout << "Before we begin, please enter your name \n";
	cin >> player_name;

	//This will create a text file witht the player's name 
	//player_name += ".txt";

	ofstream outfile;
	outfile.open(player_name);

	mainMenu();

	return 0;
}


void mainMenu() 
{
	int choice;
	bool shouldQuit = false;

	while (!shouldQuit)
	{
		cout << "-----------------------------\n";
		cout << "Welcome " << player_name << "!\n";
		cout << "What would you like to do fist?\n";
		cout << "1) Explore Dungeon\n";
		cout << "2) Show Inventory\n";
		cout << "3) Show Player Info\n";
		cout << "4) Show Map\n";
		cout << "5) Quit\n";
		cout << "-----------------------------\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			exploreDungeon();
			break;

		case 2:
			showInventory();
			break;

		case 3:
			showPlayerInfo();
			break;

		case 4:
			showMap();
			break;

		case 5:
			shouldQuit = true;
			quit();
			break;

		deafult:
			cout << "Invalid Choice\n";
			break;
		}
	}
}

void startMenu() 
{
	int choice;
	bool shouldQuit = false;

	while (!shouldQuit)
	{
		cout << "-----------------------------\n";
		cout << "Welcome " << player_name << "to Dungeon Dweller!\n";
		cout << "What would you like to do fist?\n";
		cout << "1) Start Game\n";
		cout << "2) Instructions\n";
		cout << "3) About\n";
		cout << "4) Quit\n";
		cout << "-----------------------------\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			exploreDungeon();
			break;

		case 2:
			showInventory();
			break;

		case 3:
			showPlayerInfo();
			break;

		case 4:
			showMap();
			break;

		case 5:
			shouldQuit = true;
			quit();
			break;

		deafult:
			cout << "Invalid Choice\n";
			break;
		}
	}
}

void showInstructions()
{

}

void showAbout() 
{

}

void exploreDungeon()
{
	system("cls");

	int direction;
	bool shouldQuit = false;
	while (!shouldQuit)
	{
		cout << "-----------------------------\n";
		cout << "     +----+     +----+" << endl;
		cout << "     | A  |-----| B  |" << endl;
		cout << "     +----+     +----+" << endl;
		cout << "               |         " << endl;
		cout << "          +----+----+  " << endl;
		cout << "          |    H    |  " << endl;
		cout << "          +----+----+  " << endl;
		cout << "               |       " << endl;
		cout << "     +----+     +----+" << endl;
		cout << "     | C  |-----| D  |" << endl;
		cout << "     +----+     +----+" << endl;
		cout << "You are now exploring the dungeon!\n";
		cout << "1) Move to Room B\n";
		cout << "2) Move to Room D\n";
		cout << "3) Quit exploring\n";
		cout << "-----------------------------\n";
		cin >> direction;

		switch (direction)
		{
		case 1:
			roomB();
			break;

		case 2:
			roomD();
			break;

		case 3:
			mainMenu();
			break;

		deafult:
			cout << "Invalid Choice\n";
			break;

		}

	}

}


void fightMonsterA()
{
	system("cls");
	int direction;
	bool shouldQuit = false;
	while (!shouldQuit)
	{
		cout << "-----------------------------\n";
		cout << "     +----+     +----+" << endl;
		cout << "     | H  |-----| B  |" << endl;
		cout << "     +----+     +----+" << endl;
		cout << "               |         " << endl;
		cout << "          +----+----+  " << endl;
		cout << "          |         |  " << endl;
		cout << "          +----+----+  " << endl;
		cout << "               |       " << endl;
		cout << "     +----+     +----+" << endl;
		cout << "     | C  |-----| D  |" << endl;
		cout << "     +----+     +----+" << endl;
		cout << "-----------------------------\n";
		cout << "You are now fighting a monster!" << endl;
		cout << "-----------------------------\n";
		//String for weapon
		vector<string> weapons = { "sword", "axe", "bow", "wand" };

		//Weapon code
		int weapon_index = rand() % weapons.size();
		string weapon = weapons[weapon_index];

		// Player attacks and kills the monster
		cout << "You deal fatal damage to the monster." << endl;

		// Random monster attack damages player's health
		int monster_damage = rand() % 10 + 1;
		player_health -= monster_damage;
		cout << "The monster attacks and deals " << monster_damage << " damage to you." << endl;
		cout << "Your current health is: " << player_health << endl;

		// Player earns coins
		cout << "You earned 10 gold and " << weapon << " from the fight." << endl;
		player_gold += 10;

		player_inventory[player_name] += 10;
		player_weapons[weapon] += 1;

		// Open the file in append mode
		ofstream player_update;
		player_update.open(player_name);

		// Write the updated value to the file
		player_update << "Gold: " << player_inventory[player_name] << endl;
		player_update << "Health: " << player_health << endl;
		player_update << "Weapons: " << weapon << endl;

		// Close the file
		player_update.close();

		// Check if player is still alive
		if (player_health <= 0) {
			cout << "You died!" << endl;
			quit();
		}
		cout << "-----------------------------\n";
		cout << "1) Go back\n";
		cout << "-----------------------------\n";
		cin >> direction;

		switch (direction)
		{
		case 1:
			roomB();
			break;

		default:
			cout << "Invalid Choice\n";
		}

	}

}

void fightMonsterC()
{
	system("cls");
	int direction;
	bool shouldQuit = false;
	while (!shouldQuit)
	{
		cout << "-----------------------------\n";
		cout << "     +----+     +----+" << endl;
		cout << "     | H  |-----| B  |" << endl;
		cout << "     +----+     +----+" << endl;
		cout << "               |         " << endl;
		cout << "          +----+----+  " << endl;
		cout << "          |         |  " << endl;
		cout << "          +----+----+  " << endl;
		cout << "               |       " << endl;
		cout << "     +----+     +----+" << endl;
		cout << "     | C  |-----| D  |" << endl;
		cout << "     +----+     +----+" << endl;
		cout << "-----------------------------\n";
		cout << "You are now fighting a monster!" << endl;
		cout << "-----------------------------\n";

		//String for weapon
		vector<string> weapons = { "sword", "axe", "bow", "wand" };

		//Weapon code
		int weapon_index = rand() % weapons.size();
		string weapon = weapons[weapon_index];

		// Player attacks and kills the monster
		cout << "You deal fatal damage to the monster." << endl;

		// Random monster attack damages player's health
		int monster_damage = rand() % 10 + 1;
		player_health -= monster_damage;
		cout << "The monster attacks and deals " << monster_damage << " damage to you." << endl;
		cout << "Your current health is: " << player_health << endl;

		// Player earns coins
		cout << "You earned 10 gold and " << weapon << " from the fight." << endl;
		player_gold += 10;

		player_inventory[player_name] += 10;
		player_weapons[weapon] += 1;

		// Open the file in append mode
		ofstream player_update;
		player_update.open(player_name);

		// Write the updated value to the file
		player_update << "Gold: " << player_inventory[player_name] << endl;
		player_update << "Health: " << player_health << endl;
		player_update << "Weapons: " << weapon << endl;

		// Close the file
		player_update.close();

		// Check if player is still alive
		if (player_health <= 0) {
			cout << "You died!" << endl;
			quit();
		}
		cout << "-----------------------------\n";
		cout << "1) Go back\n";
		cout << "-----------------------------\n";
		cin >> direction;

		switch (direction)
		{
		case 1:
			roomD();
			break;

		default:
			cout << "Invalid Choice\n";
		}

	}

}


void showInventory()
{
	system("cls");
	int choice;
	bool shouldQuit = false;

	while (!shouldQuit)
	{
		cout << "-----------------------------\n";
		cout << "Inventory: " << player_inventory[player_name]<< " Gold\n";
		cout << "-----------------------------\n";
		cout << "1) Explore Dungeon\n";
		cout << "2) Show Inventory\n";
		cout << "3) Show Player Info\n";
		cout << "4) Quit\n";
		cout << "-----------------------------\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			exploreDungeon();
			break;

		case 2:
			showInventory();
			break;

		case 3:
			showPlayerInfo();
			break;

		case 4:
			shouldQuit = true;
			quit();
			break;

		default:
			cout << "Invalid Choice\n";
			break;

		}

	}

}

void showPlayerInfo()
{
	system("cls");
	int choice;
	bool shouldQuit = false;

	while (!shouldQuit)
	{
		cout << "-----------------------------\n";
		cout << "Name: " << player_name << "\n";
		cout << "Health: " << player_health << "\n"; //Will show the player health
		cout << "-----------------------------\n";
		cout << "1) Explore Dungeon\n";
		cout << "2) Show Inventory\n";
		cout << "3) Show Player Info\n";
		cout << "4) Quit\n";
		cout << "-----------------------------\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			exploreDungeon();
			break;

		case 2:
			showInventory();
			break;

		case 3:
			showPlayerInfo();
			break;

		case 4:
			shouldQuit = true;
			quit();
			break;

		default:
			cout << "Invalid Choice\n";
			break;

		}

	}
}

void showMap()
{
		system("cls");
		int choice;
		bool shouldQuit = false;

		while (!shouldQuit)
		{
		cout << "-----------------------------\n";
		cout << "     +----+     +----+" << endl;
		cout << "     | A  |-----| B  |" << endl;
		cout << "     +----+     +----+" << endl;
		cout << "               |         " << endl;
		cout << "          +----+----+  " << endl;
		cout << "          |    H    |  " << endl;
		cout << "          +----+----+  " << endl;
		cout << "               |       " << endl;
		cout << "     +----+     +----+" << endl;
		cout << "     | C  |-----| D  |" << endl;
		cout << "     +----+     +----+" << endl;
		cout << "-----------------------------\n";
		cout << "1) Explore Dungeon\n";
		cout << "2) Show Inventory\n";
		cout << "3) Show Player Info\n";
		cout << "4) Quit\n";
		cout << "-----------------------------\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			exploreDungeon();
			break;

		case 2:
			showInventory();
			break;

		case 3:
			showPlayerInfo();
			break;

		case 4:
			shouldQuit = true;
			quit();
			break;

		default:
			cout << "Invalid Choice\n";
			break;

		}

	}

}

void roomB() 
{
	system("cls");
	int choice;
	bool shouldQuit = false;

	while (!shouldQuit)
	{
		cout << "-----------------------------\n";
		cout << "     +----+     +----+" << endl;
		cout << "     | A  |-----| H  |" << endl;
		cout << "     +----+     +----+" << endl;
		cout << "               |         " << endl;
		cout << "          +----+----+  " << endl;
		cout << "          |         |  " << endl;
		cout << "          +----+----+  " << endl;
		cout << "               |       " << endl;
		cout << "     +----+     +----+" << endl;
		cout << "     | C  |-----| D  |" << endl;
		cout << "     +----+     +----+" << endl;
		cout << "-----------------------------\n";
		cout << "1) Go to room A\n";
		cout << "2) Go Back\n";
		cout << "-----------------------------\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			fightMonsterA();
			break;

		case 2:
			exploreDungeon();
			break;

		deafult:
			cout << "Invalid Choice\n";
			break;

		}
	}

}

void roomD()
{
	system("cls");
	int choice;
	bool shouldQuit = false;
	cout << "-----------------------------\n";
	cout << "     +----+     +----+" << endl;
	cout << "     | A  |-----| B  |" << endl;
	cout << "     +----+     +----+" << endl;
	cout << "               |         " << endl;
	cout << "          +----+----+  " << endl;
	cout << "          |         |  " << endl;
	cout << "          +----+----+  " << endl;
	cout << "               |       " << endl;
	cout << "     +----+     +----+" << endl;
	cout << "     | C  |-----| H  |" << endl;
	cout << "     +----+     +----+" << endl;
	cout << "-----------------------------\n";
	cout << "1) Go to room C\n";
	cout << "2) Go Back\n";
	cout << "-----------------------------\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		fightMonsterC();
		break;

	case 2:
		exploreDungeon();
		break;

	deafult:
		cout << "Invalid Choice\n";
		break;

	}
}


void quit()
{
	cout << "Exiting game..." << endl; 
	exit(0); //will quit the game :)
}
