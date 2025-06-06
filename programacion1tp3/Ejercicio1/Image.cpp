#include "Image.h"
#include "AwesomeLibrary.h"

Image::Image(const char* imageData, string description)
{
	this->description = description;
	FillImage(imageData);
}

Image::~Image()
{

}

void Image::FillImage(const char* imageData)
{
	int actualFinish = 1;
	int currentChar = 0;

	bool finished = false;

	do
	{
		if (imageData[currentChar] == '\0')
		{
			finished = true;
		}
		if (!finished)
		{
			image[currentChar] = imageData[currentChar];
			//cout << image[i];
			actualFinish++;
			currentChar++;
		}
	} while (!finished);

	for (int i = actualFinish; i < MAX_IMAGE_LENGTH; i++)
	{
		image[i] = 'X';
	}

	CalculateDimensions(actualFinish);

}

void Image::CalculateDimensions(int actualSize)
{
	int width = 0;
	int height = 0;

	bool widthDefined = false;

	for (int i = 0; i < actualSize; i++)
	{
		if (image[i] == '\0')
			break;

		if (!widthDefined)
			width++;

		if (image[i] == ' ')
		{
			if (!widthDefined)
			{
				actualWidth = width;
				widthDefined = true;
			}

			height++;
		}
		else if (image[i] == 'X')
		{
			break;
		}
	}

	actualHeight = height;
	if (!widthDefined)
		actualWidth = width;
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
