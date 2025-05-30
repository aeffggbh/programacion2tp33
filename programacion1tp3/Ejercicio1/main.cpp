/*
Crear un programa que cargue y muestre imágenes hechas con caracteres ASCII,
siguiendo los siguientes lineamientos:
● Copiar en 10 archivos de texto (por fuera de Visual Studio) 10 imágenes hechas con
caracteres ASCII, e importar dichos archivos al proyecto.
● Hacer que el programa lea estos 10 archivos, para luego cargarlos en diferentes
cadenas de caracteres.
● Hacer que las imágenes se vayan mostrando de a una en pantalla, cambiándose a
medida que se presiona la tecla enter.
● Las imágenes deben estar contenidas dentro de un marco dentro de la consola.
● Incluir en la parte inferior una leyenda que indique el nombre de la persona,
personaje, objeto, animal o demás representado en la imagen.
● Si se llega al final del arreglo, hacer que se realice un loop.
● Se debe poder salir del programa al presionar escape.
*/
#include <fstream>
#include <string>
#include "AwesomeLibrary.h"
#include "Image.h"

bool IsOver();
Image* loadImage(int actualWidth, int actualHeight, string description, string path);
char* GetData(string path, int actualWidth, int actualHeight);
//string GetDataAsString(string path);

int main()
{
	Image* amogusImage = loadImage(30, 17, "amogus", "amogus.txt");
	Image* awesomeImage = loadImage(29, 17, "awesome", "awesome.txt");
	Image* catImage = loadImage(30, 17, "cat", "cat.txt");
	Image* heartImage = loadImage(33, 17, "heart", "heart.txt");
	Image* kuromiImage = loadImage(33, 19, "kuromi", "kuromi.txt");
	Image* OuOImage = loadImage(33, 6, "OuO", "OuO.txt");
	Image* pizzaImage = loadImage(30, 13, "pizza", "pizza.txt");
	Image* skellettonImage = loadImage(33, 17, "skelletton", "skelletton.txt");
	Image* snailImage = loadImage(33, 8, "snail", "snail.txt");
	Image* uwuImage = loadImage(30, 9, "uwu", "uwu.txt");

	const int maxImages = 10;
	Image* images[maxImages] =
	{
		amogusImage,
		awesomeImage,
		catImage,
		heartImage,
		kuromiImage,
		OuOImage,
		pizzaImage,
		skellettonImage,
		snailImage,
		uwuImage
	};

	int currentImageIndex = 0;

	do
	{
		images[currentImageIndex]->Draw();

		int key = getKey(true);

		if (key == KEY_ENTER)
		{
			currentImageIndex++;
			if (currentImageIndex == maxImages)
			{
				currentImageIndex = 0;
			}
			clearScreen();
		}

		//IMAGENES CAMBIAN CON LA TECLA ENTER. MARCO AL REDEDOR. QUE DIGA QUE ES ABAJO	(cat, uwu)

	} while (!IsOver());

	for (int i = 0; i < maxImages; i++) {
		delete images[i];
	}
}

bool IsOver()
{
	return (getKey(false) == KEY_ESC);
}

Image* loadImage(int actualWidth, int actualHeight, string description, string path)
{
	char* imageData = GetData(path, actualWidth, actualHeight);

	Image* myImage = new Image(imageData, description, actualWidth, actualHeight);

	delete[] imageData; 
	return myImage;
}

//string GetDataAsString(string path)
//{
//	ifstream inputStream(path);
//	if (!inputStream.is_open()) {
//		cerr << "Error: Could not open file " << path << endl;
//		return "";
//	}
//
//	string content;
//	string line;
//	while (getline(inputStream, line)) 
//		content += line + "\n";
//
//	inputStream.close();
//	return content;
//}

char* GetData(string path, int actualWidth, int actualHeight)
{
	int size = actualWidth * actualHeight;
	char* image = new char[size];

	ifstream inputStream = ifstream();
	inputStream.open(path);

	if (inputStream.good())
		inputStream.read(image, size);

	if (inputStream.is_open())
		inputStream.close();

	return image;
}