#include <iostream>
#include <fstream>
#include "PlayerData.h"
using namespace std;

int main()
{
	// usar const es weno
	// usa rider
	//:|

	PlayerData data;

	cout << "Enter the player's name" << endl;
	cin.getline(data.name, data.MAX_NAME_SIZE);

	cout << "Enter the player's level" << endl;
	cin >> data.currentLevel;

	cout << "Enter the player's XP" << endl;
	cin >> data.xp;

	cout << "Enter the player's HP" << endl;
	cin >> data.hp;

	cout << "Enter the player's strength" << endl;
	cin >> data.strength;

	cout << "Enter the player's dexterity" << endl;
	cin >> data.dexterity;

	cout << "Enter the player's intelligence" << endl;
	cin >> data.intelligence;

	ofstream outputStream = ofstream();

	outputStream.open("Data.uwu", ios::out | ios::binary);
	if (outputStream.good())
		outputStream.write((char*)&data, sizeof(PlayerData));
	else
		cout << "fail" << endl;
	outputStream.close();

	cin.get();
}