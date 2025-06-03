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
	for (int i = 0; i < actualHeight * actualWidth; i++)
	{
		image[i] = imageData[i];
		cout << image[i];
	}

	system("pause");
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
		for (int x = 0; x < actualWidth; x++)
		{
			goToCoordinates(currentX, currentY);
			cout << image[currentChar];
			if (image[currentChar] != ' ')
				currentX++;
			currentChar++;
		}
		currentY++;
		currentX = 1;
	}

	currentY += 5;
	currentX = 0;
	goToCoordinates(currentX, currentY);

	cout << description << endl << endl;
}
