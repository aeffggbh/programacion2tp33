#include "Image.h"
#include "AwesomeLibrary.h"

Image::Image(char* imageData, string description, int actualWidth, int actualHeight)
{
	FillImage(imageData);
	this->description = description;
	this->actualHeight = actualHeight;
	this->actualWidth = actualWidth;
}

Image::~Image()
{

}

void Image::FillImage(char* imageData)
{
	int currentChar = 0;

	for (int y = 0; y < MAX_IMAGE_LENGTH; y++)
	{
		for (int x = 0; x < MAX_IMAGE_LENGTH; x++)
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
	}

	currentY += 3;
	currentX = 0;

	cout << description << endl << endl;
}
