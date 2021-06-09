#ifndef HASHFUNCTIONS_CPP
#define HASHFUNCTIONS_CPP
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
// this takes in a string and returns a 64bit hash.
unsigned long polyHash(std::string value,int a = 9)
{
	unsigned long X = 0 ;
	 int length = value.length() ;
	 int i =0 ;
	 while (i<length)
	 {
	 	char ch = value[i];
	 	X = int (ch) + a*X ;
	 	i++;
	 }
	 return X;
}

//does some bitwise operation and generates a 64bit hash.
unsigned long bitHash(std::string value)
{
	unsigned long bitHasher = 0 ;
	 int length = value.length() ;
	 int i =0 ;
	 while (i<length)
	 {
	 	 bitHasher ^= (bitHasher << 5) + (bitHasher>> 2) + int(value[i]) ;
	   	 i++;
	 }
	 return bitHasher;
}
// Size is the size of array maintained by the hashtable.
unsigned long divCompression(unsigned long hash,long size)
{
	unsigned long last_index = hash % size ;
    return last_index ;

}
#endif
// you may write your own program to test these functions.