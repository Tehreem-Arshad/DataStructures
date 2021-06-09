#ifndef CHAINING_CPP
#define CHAINING_CPP
#include "Chaining.h"
#include "hashfunctions.cpp"

HashC::HashC(int size){
	tableSize = size ;
    hashTable = new LinkedList <string> [tableSize] ;
}
HashC::~HashC(){

}

unsigned long HashC :: hash(string input_w){

	unsigned long Output_n = bitHash(input_w);
    unsigned long posi = divCompression(Output_n , tableSize);
    return posi;
}

void HashC::insert(string word_str){

	unsigned long posi = hash(word_str);
    hashTable[posi].insertAtHead(word_str);

}

ListItem<string>* HashC :: lookup(string word_str){

	unsigned long posi = hash(word_str);
	return hashTable[posi].searchFor(word_str);
}

void HashC :: deleteWord(string word_str){

	unsigned long posi = hash(word_str);
    hashTable[posi].deleteElement(word_str);
}


#endif
