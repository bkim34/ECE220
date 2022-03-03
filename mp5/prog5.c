/*			
 *
 * prog5.c - source file adapted from UIUC ECE198KL Spring 2013 Program 4
 *           student code -- GOLD VERSION by Steven S. Lumetta
 */

// partners thomasp6, jaejin2
/* for this mp, i followed the insrcuctions given for most things for set_seed and start_game, i just followed what the mp said to type and was able to
do those without much of a problem. for make_guess my algorithm was to first check if the guess is valid, if it isnt valid it follows the instructions
if it was valid, we first traversered thru the guesses for perfect matches and then misplaced guesses. by using two arrays we kept track of what numbers
had been used and which had not so there would be any extra misplaced guesses. we then print the staement given with the guess number and increment the guess.
after doing that, we are done as we return the correct values and have the correct side effects.

*/
/*
 * The functions that you must write are defined in the header file.
 * Blank function prototypes with explanatory headers are provided
 * in this file to help you get started.
 */



#include <stdio.h>
#include <stdlib.h>

#include "prog5.h"


/*
 * You will need to keep track of the solution code using file scope
 * variables as well as the guess number.
 */

static int guess_number;
static int solution1;
static int solution2;
static int solution3;
static int solution4;


/*
 * set_seed -- This function sets the seed value for pseudorandom
 * number generation based on the number the user types.
 * The input entered by the user is already stored in the string seed_str by the code in main.c.
 * This function should use the function sscanf to find the integer seed value from the 
 * string seed_str, then initialize the random number generator by calling srand with the integer
 * seed value. To be valid, exactly one integer must be entered by the user, anything else is invalid. 
 * INPUTS: seed_str -- a string (array of characters) entered by the user, containing the random seed
 * OUTPUTS: none
 * RETURN VALUE: 0 if the given string is invalid (string contains anything
 *               other than a single integer), or 1 if string is valid (contains one integer)
 * SIDE EFFECTS: initializes pseudo-random number generation using the function srand. Prints "set_seed: invalid seed\n"
 *               if string is invalid. Prints nothing if it is valid.
 */
int
set_seed (const char seed_str[])
{
//    Example of how to use sscanf to read a single integer and check for anything other than the integer
//    "int seed" will contain the number typed by the user (if any) and the string "post" will contain anything after the integer
//    The user should enter only an integer, and nothing else, so we will check that only "seed" is read. 
//    We declare
//    int seed;
//    char post[2];
//    The sscanf statement below reads the integer into seed. 
//    sscanf (seed_str, "%d%1s", &seed, post)
//    If there is no integer, seed will not be set. If something else is read after the integer, it will go into "post".
//    The return value of sscanf indicates the number of items read succesfully.
//    When the user has typed in only an integer, only 1 item should be read sucessfully. 
//    Check that the return value is 1 to ensure the user enters only an integer. 
//    Feel free to uncomment these statements, modify them, or delete these comments as necessary. 
//    You may need to change the return statement below
    
	int seed;
	char post[2];
    
	if (sscanf (seed_str, "%d%1s", &seed, post)==1) //seed_str is a single intege. i did this by seeing if the size of str is 0.
	{
		srand(seed); //x is the integer inputted as the string
		return 1; // return 1 since the seed waas made
	}
	else
	{
		printf("set_seed: invalid seed\n"); //return 0 since seed was invalid and print it was invalid
		return 0;
	}
    return 0;
}


/*
 * start_game -- This function is called by main.c after set_seed but before the user makes guesses.
 *               This function creates the four solution numbers using the approach
 *               described in the wiki specification (using rand())
 *               The four solution numbers should be stored in the static variables defined above. 
 *               The values at the pointers should also be set to the solution numbers.
 *               The guess_number should be initialized to 1 (to indicate the first guess)
 * INPUTS: none
 * OUTPUTS: *one -- the first solution value (between 1 and 8)
 *          *two -- the second solution value (between 1 and 8)
 *          *three -- the third solution value (between 1 and 8)
 *          *four -- the fourth solution value (between 1 and 8)
 * RETURN VALUE: none
 * SIDE EFFECTS: records the solution in the static solution variables for use by make_guess, set guess_number
 */
void
start_game (int* one, int* two, int* three, int* four)
{
    *one = (rand()%8+1); // set the solutions
	*two = (rand()%8+1);
	*three = (rand()%8+1);
	*four = (rand()%8+1);
	guess_number =1; // set as stated in directions
	solution1= *one;
	solution2= *two;
	solution3= *three;
	solution4= *four;
    //your code here
    
}

/*
 * make_guess -- This function is called by main.c after the user types in a guess.
 *               The guess is stored in the string guess_str. 
 *               The function must calculate the number of perfect and misplaced matches
 *               for a guess, given the solution recorded earlier by start_game
 *               The guess must be valid (contain only 4 integers, within the range 1-8). If it is valid
 *               the number of correct and incorrect matches should be printed, using the following format
 *               "With guess %d, you got %d perfect matches and %d misplaced matches.\n"
 *               If valid, the guess_number should be incremented.
 *               If invalid, the error message "make_guess: invalid guess\n" should be printed and 0 returned.
 *               For an invalid guess, the guess_number is not incremented.
 * INPUTS: guess_str -- a string consisting of the guess typed by the user
 * OUTPUTS: the following are only valid if the function returns 1 (A valid guess)
 *          *one -- the first guess value (between 1 and 8)
 *          *two -- the second guess value (between 1 and 8)
 *          *three -- the third guess value (between 1 and 8)
 *          *four -- the fourth color value (between 1 and 8)
 * RETURN VALUE: 1 if the guess string is valid (the guess contains exactly four
 *               numbers between 1 and 8), or 0 if it is invalid
 * SIDE EFFECTS: prints (using printf) the number of matches found and increments guess_number(valid guess) 
 *               or an error message (invalid guess)
 *               (NOTE: the output format MUST MATCH EXACTLY, check the wiki writeup)
 */
int
make_guess (const char guess_str[], int* one, int* two, 
	    int* three, int* four)
{
	int w;
	int x;
	int y; // these are the guess vars// valid guess check
	int z;
	char post[2];
	int perfect_guess=0; // init number of perfect guesses
	int misplaced_guess=0; // init number of misplaced guesses

	 //inititalizing the needed variables
	if(sscanf (guess_str, "%d%d%d%d%1s", &w, &x, &y, &z, post)!= 4) // valid guess check
	{
		printf("make_guess: invalid guess\n");
		return 0;
	}
	*one=w;
	*two=x;
	*three=y; // insctructions say set these to the guesses
	*four=z;
	int guess_m[4]={w, x, y, z};
	int sol_m[4]={solution1, solution2, solution3, solution4};
	int paired_guess[4]={0,0,0,0};
	int paired_sol[4]={0,0,0,0};
	if(1<=w && w<=8 && 1<=x&&x<=8 &&1<=y&&y<=8 && 1<=z&&z<=8) //checking if it is between 1 and 8 for a valid guess
	{
		//because it is, we continue
		for(int i=0;i <4;i++)//step 1 of the algorithm to check perfect  matches
		{
			if (sol_m[i]==guess_m[i])
			{
				perfect_guess++; // perfect match is found
				paired_guess[i]=1; // the numbers have been used
				paired_sol[i]=1;
			}
		}
			//if there are no perfect pairings we will check for misplaced
		for (int i=0; i<4 ; i++)
		{
			for(int j =0; j<4;j++)
			{
				if ((sol_m[j]==guess_m[i])&& (paired_guess[i]==0) && (paired_sol[j]==0)) //check for misplaced guesss, but we dont want to pair it if already paired
				{
					misplaced_guess++; // increment since we have found a misplaced guess
					paired_guess[i]=1; //incerement the paired guess
					paired_sol[j]=1; // increment the paired solution
				}

			}
		}
		
		printf("With guess %d, you got %d perfect matches and %d misplaced matches.\n", guess_number, perfect_guess, misplaced_guess); // print the number of matches
		guess_number++; //increment guess
	}
	else
	{
		//because it isnt, it is invalid and we returrrn 0.
		printf("make_guess: invalid guess\n");
		return 0;
	}




//  One thing you will need to read four integers from the string guess_str, using a process
//  similar to set_seed
//  The statement, given char post[2]; and four integers w,x,y,z,
//  sscanf (guess_str, "%d%d%d%d%1s", &w, &x, &y, &z, post)
//  will read four integers from guess_str into the integers and read anything else present into post
//  The return value of sscanf indicates the number of items sucessfully read from the string.
//  You should check that exactly four integers were sucessfully read.
//  You should then check if the 4 integers are between 1-8. If so, it is a valid guess
//  Otherwise, it is invalid.  
//  Feel free to use this sscanf statement, delete these comments, and modify the return statement as needed
    return 1;
}


