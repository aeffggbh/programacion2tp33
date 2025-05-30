#include "Image.h"
#include "AwesomeLibrary.h"

Image::Image(const char* imageData, string description, int actualWidth, int actualHeight)
{
	this->actualHeight = actualHeight;
	this->actualWidth = actualWidth;
	this->description = description;
	FillImage(imageData);
}

Image::~Image()
{

}

void Image::FillImage(const char* imageData)
{
	int currentChar = 0;

	for (int i = 0; i < actualHeight * actualWidth; i++)
	{
		if (imageData[currentChar] != '\0' && imageData[currentChar] != ' ')
		{
			image[i] = imageData[currentChar];
			currentChar++;
		}
	}
}

void Image::Draw()
{
	clearScreen();
	drawFrame(0, 0, actualWidth + 2, actualHeight + 2);

	int currentX = 1;
	int currentY = 1;

	int currentChar = 0;
	int spacesToAdd = 0;

	for (int y = 0; y < actualHeight; y++)
	{
		goToCoordinates(currentX, currentY);

		for (int x = 0; x < actualWidth; x++)
		{
			cout << image[currentChar];
			if (image[currentChar] != ' ')
				currentX++;
			goToCoordinates(currentX, currentY);
		}
		currentY++;
		currentX = 1;
	}

	currentY += 5;
	currentX = 0;
	goToCoordinates(currentX, currentY);

	cout << description << endl << endl;
}
