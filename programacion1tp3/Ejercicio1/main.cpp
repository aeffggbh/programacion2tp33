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
Image* loadImage(string description, string path);
string GetData(string path);

int main()
{
	Image* amogusImage = loadImage("amogus", "amogus.txt");
	Image* awesomeImage = loadImage("awesome", "awesome.txt");
	Image* catImage = loadImage("cat", "cat.txt");
	Image* heartImage = loadImage("heart", "heart.txt");
	Image* kuromiImage = loadImage("kuromi", "kuromi.txt");
	Image* OuOImage = loadImage("OuO", "OuO.txt");
	Image* pizzaImage = loadImage("pizza", "pizza.txt");
	Image* skellettonImage = loadImage("skelletton", "skelletton.txt");
	Image* snailImage = loadImage("snail", "snail.txt");
	Image* uwuImage = loadImage("uwu", "uwu.txt");

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
				currentImageIndex = 0;
		}

	} while (!IsOver());

	for (int i = 0; i < maxImages; i++) {
		delete images[i];
	}

}

bool IsOver()
{
	return (getKey(false) == KEY_ESC);
}

Image* loadImage(string description, string path)
{
	string imageData = GetData(path);

	Image* myImage = new Image(imageData.c_str(), description);

	return myImage;
}

string GetData(string path)
{
	string text;

	ifstream inputStream = ifstream();

	try
	{
		inputStream.open(path);

		if (!inputStream.is_open())
			throw ifstream::failure("the file could not be opened");

		while (!inputStream.eof())
		{
			string addText;

			inputStream >> addText;

			text += addText + " ";
		}

		if (inputStream.fail())
			throw ifstream::failure("file could not be read");

		inputStream.close();
	}
	catch (ifstream::failure& error)
	{
		cerr << "Error loading text: " << error.what() << endl;

		if (inputStream.is_open())
			inputStream.close();
	}

	return text;
}