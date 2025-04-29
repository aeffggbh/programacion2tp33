#pragma once
#include <iostream>
using namespace std;
class Image
{
private:
	static const int MAX_IMAGE_LENGTH = 200;
	int actualWidth;
	int actualHeight;
	char image[MAX_IMAGE_LENGTH][MAX_IMAGE_LENGTH];
	string description;

public:
	Image(char* imageData, string description, int actualWidth, int actualHeight);
	~Image();
	void FillImage(char* imageData);
	void Draw();
};

