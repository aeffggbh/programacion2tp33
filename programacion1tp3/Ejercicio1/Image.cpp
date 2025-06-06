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
	int actualFinish = actualHeight * actualWidth;

	for (int i = 0; i < actualHeight * actualWidth; i++)
	{
		if (imageData[i] == '\0')
		{
			actualFinish = i;
			break;
		}
		image[i] = imageData[i];
		//cout << image[i];
	}

	for (int i = actualFinish; i < MAX_IMAGE_LENGTH; i++)
	{
		image[i] = 'X';
	}

	//system("pause");
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
		for (int i = 0; i < actualWidth; i++)
		{
			if (image[currentChar] != 'X')
			{
				goToCoordinates(currentX, currentY);
				cout << image[currentChar];
				currentX++;
				currentChar++;

				if (image[currentChar] == ' ')
				{
					currentY++;
					currentX = 1;
				}
			}
			else
				break;
		}

		if (image[currentChar] == 'X')
			break;
	}

	currentY += 5;
	currentX = 0;
	goToCoordinates(currentX, currentY);

	cout << description << endl << endl;
}
