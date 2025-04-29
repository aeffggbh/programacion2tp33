#include <iostream>
#include <fstream>
#include "../programacion1tp3/PlayerData.h"

using namespace std;

PlayerData loadData(string path);
void logData(PlayerData data);

int main()
{
	PlayerData data = loadData("../programacion1tp3/Data.uwu");

	logData(data);

	cin.get();
}

PlayerData loadData(string path)
{
	PlayerData data;

	ifstream inputStream = ifstream();
	inputStream.open(path, ios::in | ios::binary);
	
	if (inputStream.good())
		inputStream.read((char*)&data, sizeof(PlayerData));

	if (inputStream.is_open())
		inputStream.close();

	return data;
}

void logData(PlayerData data)
{
	cout << "NAM: " << data.name << endl;
	cout << "LEV: " << data.currentLevel << endl;
	cout << "HP: " << data.hp << endl;
	cout << "XP: " << data.xp << endl;
	cout << "STR: " << data.strength << endl;
	cout << "DEX: " << data.dexterity << endl;
	cout << "INT: " << data.intelligence << endl;
	
}
