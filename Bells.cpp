//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bells.cpp - library for manipulating bells using arrays. x
//Functions to swap bells and give instructions to the     x
//ringers to ring different call changing patterns         x
//Created by Ray Houghton May 25 2018                      x
//Released into the public domain                          x
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#include "Arduino.h"
#include "Bells.h"
//============================================================
//Prints the initial order of array elements
//First parameter Array pointer, second perameter number of
//elements currently in use
//============================================================

initOrder::initOrder(int _initBells[], int _initNumBells)
{
for(int i = 0; i <= _initNumBells; i++)
    {
    Serial.print(_initBells[i]);
    Serial.print(", ");
    	
    }
    Serial.println("  Initial order ");
}
//==============================================================
//Prints the contents of the array (first perameter)
//The second perameter reflects the number of elements in use in 
//the array
//==============================================================

void initOrder::printArray(int _prBells[], int _prNumBells)
{
  for(int i = 0; i <= _prNumBells; i++)
    {
    Serial.print(_prBells[i]);
    Serial.print(", ");
    }
   Serial.println("    "); 
    
}


//==============================================================
//Writes the contents of the first array perameter into the second
//The third perameter reflects the number of elements in use in 
//the arrays
//==============================================================
void initOrder::initBells(int _inFirstArray[], int _inSecondArray[], int _inNumBells) 
{
  for(int l = 0; l <= _inNumBells; l++)  //loop to print bell order
    {
    _inSecondArray[l] = _inFirstArray[l]; //ensures arrays are equal; l++)
    }
}

//==============================================================
//swaps the array element corresponding to the third parameter
//with the next element
//the change is written to both arrays 
//==============================================================

void initOrder::swapBells(int _swFirstArr[], int _swSecondArr[], int _swIndex) 
{
  _swSecondArr[_swIndex+1] = _swFirstArr[_swIndex]; //swap routine
        _swSecondArr[_swIndex] = _swFirstArr[_swIndex+1];
        _swFirstArr[_swIndex] = _swSecondArr[_swIndex];     //writes the newly exchanged bells into the current array
        _swFirstArr[_swIndex+1] = _swSecondArr[_swIndex+1];
}

//==============================================================
//Gives instructions to all bells associated with a swap
//a is the array address of the first of the two bells in the swap
//b is the number of bells in the array
//==============================================================

void initOrder::instructions(int _insFirstArr[], int _insIndex, int _insNumBells) 
{
 if (_insIndex==0)
  {
  Serial.print(_insFirstArr[_insIndex]); 
  Serial.print(" to "); 
  Serial.print("lead");
  Serial.print(",  ");
  Serial.print(_insFirstArr[_insIndex+1]);
  Serial.print(" to "); 
  Serial.print(_insFirstArr[_insIndex]);
  Serial.print(",  ");
  Serial.print(_insFirstArr[_insIndex+2]);
  Serial.print(" to ");
  Serial.print(_insFirstArr[_insIndex+1]);
 Serial.println("  ");
  }
  else
  { 
  Serial.print(_insFirstArr[_insIndex+1]);
  Serial.print(" to "); 
  Serial.print(_insFirstArr[_insIndex]);
  Serial.print(",  "); 
  Serial.print(_insFirstArr[_insIndex]);
  Serial.print(" to ");
  Serial.print(_insFirstArr[_insIndex-1]);
  Serial.print(",  ");
  if(_insIndex == _insNumBells-1) //Routine to catch if the last two bells are changed
  {
    Serial.print(_insFirstArr[_insIndex+1]);
    Serial.print(" at the back");
    Serial.println();
  }
    else
    {
    Serial.print(_insFirstArr[_insIndex+2]);
    Serial.print(" to ");
    Serial.print(_insFirstArr[_insIndex+1]);
    Serial.println();  
    }

  }
}


//================================================================
//Function to compare two arrays
//Posted by ShadowX on Arduino forum "Thank's ShadowX"
//================================================================

boolean initOrder::array_cmp(int _acFirstArr[], int _acSecondArr[],int _acNumBells)
    {
         int n;
         // test each element to be the same. if not, return false
         for (n=0;n<_acNumBells;n++) if (_acFirstArr[n]!=_acSecondArr[n]) return false;

         //ok, if we have not returned yet, they are equal :)
         return true;
    }


