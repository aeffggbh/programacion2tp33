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

	for (int y = 0; y < actualHeight; y++)
	{
		for (int x = 0; x < actualWidth; x++)
		{
			if (imageData[currentChar] != '\0')
			{
				image[y][x] = imageData[currentChar];
				currentChar++;
			}
			else
			{
				delete imageData;
				return;
			}
		}
	}

	delete imageData;
}

void Image::Draw()
{
	clearScreen();
	drawFrame(0, 0, actualWidth + 2, actualHeight + 2);

	int currentX = 1;
	int currentY = 1;

	for (int y = 0; y < actualHeight; y++)
	{
		goToCoordinates(currentX, currentY);

		for (int x = 0; x < actualWidth; x++)
		{
			cout << image[y][x];
			currentX++;
		}
		currentY++;
		currentX = 1;
	}

	currentY += 5;
	currentX = 0;
	goToCoordinates(currentX, currentY);

	cout << description << endl << endl;
}
