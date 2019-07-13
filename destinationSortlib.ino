//Destination sort is a sort to change one sequence of bells to another.  It does
//this by checking the final bell in the destination and finding the same bell in the 
//current order and moving the bell towards it's correct position to match the
//destination. The next to last bell is then checked and the sequence is repeated
//until all of the bells are in the correct position.
#include <Bells.h>
int bells[15] = {1, 2, 3, 4, 5, 6, 7, 8}; //array holding starting order
int   nextbells[15]; //intermediate store
int destination[15] = {1, 3, 5, 7, 2, 4, 6, 8};//array holding 
//final bell order
int a; int element;int changes; int m; int p; // element is the position of the bell check
int Bells = 8;
int numBells = Bells-1;
int*ptrBells; int*ptrNextBells; int *ptrdest;

void setup() 
{  
 Serial.begin(9600);  
}

void loop()
{ 
  ptrBells = &bells[0];
  ptrNextBells = &nextbells[0];
  ptrdest = &destination[0];
  //Set up pointers for arrays
  initOrder initOrder(ptrBells, numBells); 
 //transfer contents of "bells" to "nextbells" and print initial order. 
  changes = 0;
  while(initOrder.array_cmp(ptrBells, ptrdest, Bells) == false)
 {
  //loop that stops when all bells are in the correct order 
 for(element = numBells; element>=0; element --)
  { 
  a = 0; 
  m = element; 
 while(a != 1) //while loop to find current "destination[]" element in current "bell[]" 
 //order
 {
 
 if(bells[m]!=destination[element])//find equivalent bell
   {  
    m--;
   }
   else
    {
     a = 1;   //exit loop with "m" at the correct value 
    } 
 }
 int b = (m); //assigns equivalent bell pos'n to variable "b"
 for(int j = b; j <= (element-1); j++)
 //loop to move selected bell "element" into correct position
 {
  initOrder.swapBells(ptrBells, ptrNextBells, j);
   changes++; //counts number of changes
   initOrder.printArray(ptrBells, numBells); //prints out array
   initOrder.instructions(ptrBells, j, numBells);//prints instructions for change
 }
 }
 }
 Serial.print("changes  ");
 Serial.print(changes);
 while(p==0) // stops programme
 {}
}


