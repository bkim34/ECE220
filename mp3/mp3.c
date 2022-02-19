#include <stdio.h>
#include <stdlib.h>

//the algorithm used for this mp is two for loops, one to print the desired number of digits for the row inputed in pascals triangle, and another to cortrectly calculate the digit that should be printed. because operations requiremultiplying and dividing with decimals, we want to use a unsigned long variable.

int main()
{
  int row;

  printf("Enter a row index: ");
  scanf("%d",&row);
  
  unsigned long coeff;
  for(int i=0; i<=row; i++) // to print row +1 numbers
    {
    coeff=1;
      for (float j=1; j<=i; j++)
      {
	coeff=(coeff*(row+1-j))/j;// given formula
      }
      
      printf("%lu ",coeff); // print the number we want along with a space
    }

  // Write your code here

  return 0;
}




