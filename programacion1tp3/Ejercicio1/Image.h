#pragma once
#include <iostream>
using namespace std;
class Image
{
private:
	static const int MAX_IMAGE_LENGTH = 700;
	int actualWidth;
	int actualHeight;
	char image[MAX_IMAGE_LENGTH];
	string description;
	void CalculateDimensions(int actualSize);

public:
	Image(const char* imageData, string description);
	~Image();
	void FillImage(const char* imageData);
	void Draw();
};

