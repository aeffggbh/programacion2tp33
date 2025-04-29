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
#include <iostream>
#include <fstream>
#include "AwesomeLibrary.h"
#include "Image.h"
using namespace std;

bool IsOver();
Image* loadImage(int actualWidth, int actualHeight, string description, string path);
char* loadImage(string path, int actualWidth, int actualHeight);

int main()
{
	do
	{
		Image* amogusImage = loadImage(27, 12, "amogus", "amogus.txt");
		Image* awesomeImage = loadImage(39, 3, "awesome", "awesome.txt");
		Image* catImage = loadImage(22, 10, "cat", "cat.txt");
		Image* heartImage = loadImage(22, 15, "heart", "heart.txt");
		Image* kuromiImage = loadImage(20, 9, "kuromi", "kuromi.txt");
		Image* OuOImage = loadImage(31, 11, "OuO", "OuO.txt");
		Image* pizzaImage = loadImage(32, 15, "pizza", "pizza.txt");
		Image* skellettonImage = loadImage(22, 14, "skelletton", "skelletton.txt");
		Image* snailImage = loadImage(30, 11, "snail", "snail.txt");
		Image* uwuImage = loadImage(30, 5, "uwu", "uwu.txt");

		delete amogusImage;
		delete awesomeImage;
		delete catImage;
		delete heartImage;
		delete kuromiImage;
		delete OuOImage;
		delete pizzaImage;
		delete skellettonImage;
		delete snailImage;
		delete uwuImage;
		//LEER 10 ARCHIVOS, CARGARLOS EN UN CHAR* 




		//IMAGENES CAMBIAN CON LA TECLA ENTER. MARCO AL REDEDOR. QUE DIGA QUE ES ABAJO	(cat, uwu)


	} while (!IsOver());
}

bool IsOver()
{
	return (getKey(false) == KEY_ESC);
}

Image* loadImage(int actualWidth, int actualHeight, string description, string path)
{
	char* imageData = loadImage(path, actualWidth, actualHeight);
	Image* image = new Image(imageData, description, actualWidth, actualHeight);

	return image;
}

char* loadImage(string path, int actualWidth, int actualHeight)
{
	char* image = new char[actualWidth * actualHeight];

	ifstream inputStream = ifstream();
	inputStream.open(path, ios::in | ios::binary);

	if (inputStream.good())
		inputStream.read(image, sizeof(image));

	if (inputStream.is_open())
		inputStream.close();

	return image;
}
