//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bells.h - library for manipulating bells using arrays. x
//Functions to swap bells and give instructions to the   x
//ringers to ring different call changing patterns       x
//Created by Ray Houghton May 25 2018                    x
//Released into the public domain                        x
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#ifndef Bells_h
#define Bells_h

#include "Arduino.h"

   
class initOrder
	{
		
	public:	
	initOrder(int[], int );
	//Prints initial order
	void printArray(int[], int);
    // prints contents of array
    void initBells(int[], int[], int);
    //writes bells elements to nextbells 
    void swapBells(int[], int[], int);
    //swaps the two bells corresponding to the third argument
    void instructions(int[], int, int);
    //serial print instructions for bell swap
    boolean array_cmp(int[], int[], int);
    //compare arrays
    int index;
    private:
    //initOrder
    int _initBells;
    int _initNumBells;
    //printArray
    int _prBells;
    int _prNumBells;
    //initBells
    int _inFirstArray[];
    int _inSecondArray2[];
    int _inNumBells;
    //swapBells
    int _swFirstArr[];
    int _swSecondArr[];
    int _swIndex;
    //instructions
    int _insFirstArr[];
    int _insIndex; 
    int _insNumBells;
    //array_cmp
    int _acFirstArr[]; 
    int _acSecondArr[];
    int _acNumBells;
    };
	
	
#endif	
	
