#include <iostream>
#define SIZE 2 // number of objects we have
//#include "SpriteSheet.h"
using namespace std;

class Block {

public:

	Block(string str, bool col, char sym) {
		nameO = str;
		colisionEnabled = col;
		symbol = sym;
	}
	void render(short corX, short corY);
	friend Block getObjectBySymbol(char);// getting object by symbol

private:

	string nameO;
	bool colisionEnabled;
	char symbol;                                                 //'#' or '*'
	short heightO, widthO;                                       //height, width of Object
	short heightGen, freqGen;                                      //height, frequency of Generation
	short corX, corY;                                            //co-ordinates of object
	//SpriteSheet* sprites;

};


Block blockTypes[] = { {"Air", false, '*'}, {"ground", true, '#'}, }; //all types of blocks in game


Block getObjectBySymbol(char a) {

	for (int i = 0; i < SIZE; i++) {
		if (blockTypes[i].symbol == a) {
			return blockTypes[i];
		}
	}

}
