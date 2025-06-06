#pragma once

struct PlayerData
{
	static const int MAX_NAME_SIZE = 32;
	char name[MAX_NAME_SIZE];
	int currentLevel;
	int xp;
	float hp;
	int strength;
	int dexterity;
	int intelligence;
};

