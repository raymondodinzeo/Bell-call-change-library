//DestinationSort module is an attempt to implement destination sort as a
//standalone function.
//Destination sort to change one sequence of bells to another.  It does
//this by checking the final bell in the destination and finding the same
//bell in the current order and moving the bell towards it's correct
//position to match the destination. The next to last bell is then checked
//and the sequence is repeated until all of the bells are in the correct position.
//* Back rounds: 543216 76543218
//* Bow bells:      13245768
//* Burdette: 213546 31247568
//* Expl Tittums: 342516 45362718
//* Hagdyke: 341256 12563478
//* Priory: 132546 13254768
//* Kings: 531246 75312468
//* Queens:135246  13572468 
//* Jacks: 145236 16745238
//* Jokers: 154326 17654328
//* Tittums:142536 15263748 
//* Whittington's: 531246 12753468 
#include <Bells.h> //Library for manipulating bell arrays
String patternName[14]={"Back rounds", "Bow bells", "Burdette", "Expl Tittums", "Hagdyke", "Rounds",
"Priory", "Kings", "Queens", "Jacks", "Jokers", "Tittums", "Whittington's"}; //Pattern name array
int patterns8[14][9] = { {/*Back Rounds*/ 7, 6, 5, 4, 3, 2, 1, 8 },
{/*Bow bells*/ 1, 3, 2, 4, 5, 7, 6, 8 }, {/*Burdette*/ 3, 1, 2, 4, 7, 5, 6, 8 },
{/*Expl' tittums*/ 4, 5, 3, 6, 2, 7, 1, 8 }, {/*Hagdyke*/ 1, 2, 5, 6, 3, 4, 7, 8 },
{/*Rounds*/ 1, 2, 3, 4, 5, 6, 7, 8 }, {/*Priory*/ 1, 3, 2, 5, 4, 7, 6, 8 },
{/*Kings*/ 7, 5, 3, 1, 2, 4, 6, 8 }, {/*Queens*/ 1, 3, 5, 7, 2, 4, 6, 8 },
{/*Jacks*/ 1, 6, 7, 4, 5, 2, 3, 8 }, {/*Jokers*/ 1, 7, 6, 5, 4, 3, 2, 8 },
{/*Tittums*/ 1, 5, 2, 6, 3, 7, 4, 8 }, {/*Whittingtons*/ 1, 2, 7, 5, 3, 4, 6, 8 }};

int patterns6[14][7] = {{/*Back Rounds*/ 5, 4, 3, 2, 1, 6}, {/*Bow bells*/ 1, 3, 2, 5, 4, 6}, 
{/*Burdette*/ 2, 1, 3, 5, 4, 6}, {/*Expl' tittums*/ 3, 4, 2, 5, 1, 6},
{/*Hagdyke*/ 3, 4, 1, 2, 5, 6}, {/*Rounds*/ 1, 2, 3, 4, 5, 6 }, {/*Priory*/ 1, 3, 2, 5, 4, 6},
{/*Kings*/ 5, 3, 1, 2, 4, 6}, {/*Queens*/1, 3, 5, 2, 4, 6},{/*Jacks*/1, 4, 5, 2, 3, 6},
{/*Jokers*/1, 5, 4, 3, 2, 6}, {/*Tittums*/1, 4, 2, 5, 3, 6},{/*Whittingtons*/5, 3, 1, 2, 4, 6}};
//Array containing bell orders for destinations

int patterns4[14][5] = { {/*Back Rounds*/ 1, 3, 2, 4},
{/*Bow bells*/ 1, 4, 3, 2 }, {/*Burdette*/ 1, 4, 2, 3 },
{/*Expl' tittums*/ 1, 3, 4, 2 }, {/*Hagdyke*/ 1, 2, 4, 3},
{/*Rounds*/ 1, 2, 3, 4 }, {/*Priory*/ 3, 1, 2, 4 },
{/*Kings*/ 3, 2, 1, 4 }, {/*Queens*/ 2, 3, 1, 4 },
{/*Jacks*/ 2, 1, 3, 4}, {/*Jokers*/ 2, 1, 4, 3 },
{/*Tittums*/ 2, 4, 1, 3 }, {/*Whittingtons*/ 4, 2, 1, 3 }};

int patterns5[14][6] = { {/*Back Rounds*/ 1, 2, 5, 4, 3},
{/*Bow bells*/ 1, 4, 2, 3, 5 }, {/*Burdette*/ 1, 4, 2, 5, 3 },
{/*Expl' tittums*/ 1, 4, 5, 2, 3 }, {/*Hagdyke*/ 1, 3, 4, 2, 5},
{/*Rounds*/ 1, 2, 3, 4, 5 }, {/*Priory*/ 1, 5, 2, 4, 3 },
{/*Kings*/ 2, 1, 5, 4, 3 }, {/*Queens*/ 2, 4, 3, 5, 1 },
{/*Jacks*/ 3, 4, 1, 5, 2}, {/*Jokers*/ 3, 1, 5, 2, 4 },
{/*Tittums*/ 5, 3, 1, 2, 4 }, {/*Whittingtons*/ 5, 1, 4, 2, 3 }};



int patternSelect[24] = {0, 5, 1, 5, 2, 5, 3, 5, 4, 5, 6, 5, 7, 5, 8, 5, 9, 5, 10, 5, 11,
5, 12, 5}; //Sequence to select patterns

int bells[9] = {1, 2, 3, 4, 5, 6, 7, 8}; //array holding starting order
int   nextbells[9]; //intermediate store
int destination[9];//array holding 
//final bell order
int a; int element;int changes; int m; int i; int r;// element is the position of the bell check
int Bells = 8;//number of bells in use, can be 8, 6, 5, or 4 
int numBells = Bells-1;
int y;
void destinationSort(int [], int [], int [], int);
int*ptrBells; int*ptrNextBells; int *ptrDestination;

void setup() 
{
  Serial.begin(9600);
  delay(1000);
}

void loop()
{
  for(y = 0; y <= 24; y++)  //reads through pattern select list which indexes the pattern array
  {

for(i = 0; i <= Bells; i++) //counts through bell positions to load into destination array 
{
  if(Bells == 8)  
  {
   destination[i] = patterns8[patternSelect[y]][i]; //load individual bell positions into destination array
  }
  else if(Bells == 6)  
  {
   destination[i] = patterns6[patternSelect[y]][i]; //load individual bell positions into destination array
  }
  else if(Bells == 5)  
  {
   destination[i] = patterns5[patternSelect[y]][i]; //load individual bell positions into destination array
  }
  else
   {
    destination[i] = patterns4[patternSelect[y]][i]; //load destination array from last half of patterns
    }
}
Serial.print("Destination ");
Serial.println(patternName[patternSelect[y]]);
ptrBells = &bells[0]; //assign pointers to array addresses
ptrNextBells = &nextbells[0];
ptrDestination = &destination[0];
destinationSort(ptrBells, ptrNextBells, ptrDestination, numBells);  
  }
}

void destinationSort(int ptrBells[], int ptrNextBells[], int ptrDestination[], int ds_Numbells)
{
    //Set up pointers for arrays
  initOrder initOrder(ptrBells, numBells); 
//   for(int repeats = 0; repeats <= 2; repeats++) //number of repeats
{
delay(1000); //delay between peals


 //transfer contents of "bells" to "nextbells" and print initial order. 
  changes = 0;
  while(initOrder.array_cmp(ptrBells, ptrDestination, Bells) == false)
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
   initOrder.instructions(ptrBells, j, numBells);//prints instructions for change
   initOrder.printArray(ptrBells, numBells); //prints out array
   delay(1000);
 }
 }
 }
 Serial.println(patternName[patternSelect[y]]);
 Serial.print("changes  ");
 Serial.println(changes);
 for(int k = 0; k <= Bells; k++)
 {
  bells[k] = destination[k];
 }
} 
}
