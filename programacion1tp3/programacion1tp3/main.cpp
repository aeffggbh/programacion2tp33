
#include <fstream>
#include <filesystem>
#include "PlayerData.h"
#include "AwesomeLibrary.h"
using namespace std;

const char* FILE_NAME = "Data.player";

void WritePlayerData()
{
	PlayerData player;

	cout << "Enter player name: ";
	cin.getline(player.name, PlayerData::MAX_NAME_SIZE);

	cout << "Enter level: ";
	cin >> player.currentLevel;

	cout << "Enter XP: ";
	cin >> player.xp;

	cout << "Enter HP: ";
	cin >> player.hp;

	cout << "Enter strength: ";
	cin >> player.strength;

	cout << "Enter dexterity: ";
	cin >> player.dexterity;

	cout << "Enter intelligence: ";
	cin >> player.intelligence;

	ofstream outFile(FILE_NAME, ios::binary);
	if (outFile)
		outFile.write(reinterpret_cast<char*>(&player), sizeof(PlayerData));

	outFile.close();
}

void ReadPlayerData()
{
	PlayerData data;

	ifstream inputStream = ifstream();
	inputStream.open(FILE_NAME, ios::in | ios::binary);

	if (inputStream.good())
		inputStream.read((char*)&data, sizeof(PlayerData));

	if (inputStream.is_open())
		inputStream.close();

	cout << "--- Character Sheet ---" << endl;
	cout << "Name: " << data.name << endl;
	cout << "Level: " << data.currentLevel << endl;
	cout << "XP: " << data.xp << endl;
	cout << "HP: " << data.hp << endl;
	cout << "Strength: " << data.strength << endl;
	cout << "Dexterity: " << data.dexterity << endl;
	cout << "Intelligence: " << data.intelligence << endl;
}

void CreateDefault()
{
	if (!filesystem::exists(FILE_NAME))
	{
		PlayerData defaultPlayer;
		strncpy_s(defaultPlayer.name, "Default Hero", PlayerData::MAX_NAME_SIZE);
		defaultPlayer.currentLevel = 1;
		defaultPlayer.xp = 0;
		defaultPlayer.hp = 100.0f;
		defaultPlayer.strength = 10;
		defaultPlayer.dexterity = 10;
		defaultPlayer.intelligence = 10;

		ofstream outFile(FILE_NAME, ios::binary);
		outFile.write(reinterpret_cast<char*>(&defaultPlayer), sizeof(PlayerData));
		outFile.close();
	}
}

int main()
{
	CreateDefault();

	bool exit = false;

	do
	{
		clearScreen();
		char choice;
		cout << "Do you want to read (r) or write (w) the character sheet? (enter 'e' to exit) ";
		cin >> choice;

		if (choice == 'r' || choice == 'R')
			ReadPlayerData();
		else if (choice == 'w' || choice == 'W')
			WritePlayerData();
		else if (choice == 'e' || choice == 'E')
		{
			cout << "Exiting the program." << endl;
			exit = true;
		}
		else
			cout << "Invalid choice." << endl;

		system("pause");

	} while (!exit);

	return 0;
}
