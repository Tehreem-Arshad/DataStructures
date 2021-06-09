#ifndef LINEARPROBING_CPP
#define LINEARPROBING_CPP

#include "linearProbing.h"
#include "hashfunctions.cpp"

HashL::HashL()
{
    tableSize = 1000; // you cant change this
    count = 0 ;
    hashTable = new block *[tableSize] ; 
    int i = 0;
    while (i<tableSize)
    {
    	hashTable[i] = NULL ;
    	i++ ;
    }

}

HashL::~HashL()
{
    

}

unsigned long HashL :: hash(string value)
{
	unsigned long pos = bitHash(value) ;
	unsigned long Last_pos = divCompression(pos , tableSize) ;
	return Last_pos ;

}

void HashL::resizeTable()
{
	int os = tableSize ;
	tableSize = tableSize * 2 ;
	block **t = new block*[tableSize] ;
	int i= 0;
	while (i<tableSize)
	{
		t[i] = NULL ;
		i++ ;
	}
	
	for (int i = 0 ; i < os ; i++)
	{
		if (hashTable[i] != NULL)
		{
			unsigned long pos= hash(hashTable[i] -> value) ;

			while(t[pos] != NULL)
			{
				pos = (pos + 1) % tableSize ;
			}
			t[pos] = new block(pos , hashTable[i] -> value) ;
		}
	}

	
	for (int i = 0 ; i < os ; i++)
	{
		delete hashTable[i] ;
	}

	delete hashTable ;
	hashTable = t ;
	t = NULL ;
}

void HashL::insert(string value)
{
	if( (count*1.0)/tableSize > 0.5)
	{
		resizeTable() ;
	}
	unsigned long pos = hash(value) ;
	while(hashTable[pos] != NULL)
	{
		pos = (pos + 1) % tableSize ;
	}
	hashTable[pos] = new block(pos , value) ;
	count++ ;
}

void HashL::deleteWord(string value)
{
	unsigned long pos = hash(value) ;
	while(hashTable[pos] != NULL)
	{
		if(hashTable[pos] -> value == value) 
        { 
            hashTable[pos] = NULL ; 
            count-- ; 
            return ;
        } 
        pos = (pos + 1) % tableSize ;
    }

}
block* HashL::lookup(string value)
{
	unsigned long pos = hash(value) ; 
    int count1 = 0 ;       
    while(hashTable[pos] != NULL) 
    {    
        if(count1> count)  
            return NULL ;           
        if(hashTable[pos] -> value == value) 
            return hashTable[pos] ; 
        pos = (pos + 1) % tableSize ;
        count1++;
    }   
    return NULL; 
}
#endif


