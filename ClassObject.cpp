#include <iostream>
#define SIZE 2 // number of objects we have
//#include "SpriteSheet.h"
using namespace std;

class Blok {

public:

	int i;
	Blok(string str, bool col, char sym, char i) {
		nameO = str;
		colisionEnabled = col;
		symbol = sym;
		this->i = i;
	}
	void render(short wspX, short wspY);
	friend Blok getObjectBySymbol(char);// getting object by symbol

private:

	string nameO;
	bool colisionEnabled;
	char symbol;                                                 //'#' or '*'
	short heightO, widthO;                                       //height, width of Object
	short wysGen, czestGen;                                      //height, width of Generation
	short wspX, wspY;                                            //co-ordinates of object
	//SpriteSheet* sprites;

};


Blok blockTypes[] = { {"Air", false, '*', 20 }, {"ground", true, '#', 25}, }; //all types of blocks in game


Blok getObjectBySymbol(char a) {

	for (int i = 0; i < SIZE; i++) {
		if (blockTypes[i].symbol == a) {
			return blockTypes[i];
		}
	}

}


int main(void) {
	cout << getObjectBySymbol('#').i;
}