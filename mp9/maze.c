#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

//partners jaejin2 thomasp6
/*
 for this mp, we followed the directions mostly. for print maze we just traversed through and printed everything
 for destroymaze, we again foollowed the directions and traversed through the array to successfully free everything.
 for solve maze, we just followed the instructions as well. the thing was acting weird for me around the start, but i was able to fix it by setting 
 start to * and changing it backl when a solution was reached.
 unfortunately we were unable to figure out how to get createMAze, but have submitted our best attempt
*/
/*
 * createMaze -- Creates and fills a maze structure from the given file
 * INPUTS:       fileName - character array containing the name of the maze file
 * OUTPUTS:      None 
 * RETURN:       A filled maze structure that represents the contents of the input file
 * SIDE EFFECTS: None
 */


maze_t * createMaze(char * fileName)
{
  FILE* fptr;
  fptr = fopen(fileName, "r"); //open the file
  int r,column; // declare r and column for row and column
  fscanf(fptr, "%d", &r); //scan the width and height
  fscanf(fptr, "%d", &column);
  maze_t* maze = malloc(sizeof(maze_t)); //allocate memory for maze
  maze->cells = calloc(r,sizeof(char*)); //allocate memory for the cells
  int a;
  for(a=0; a<r; a++){
      maze->cells[a] = calloc(column,sizeof(char));
  }
  maze->height = r;
  maze->width = column;
  int i,j;
  char c;// traverse through maze
  for(i=0; i<r; i++){
      for(j=0; j<column; j++){
          fscanf(fptr, "%c",&c);
          maze->cells[i][j] = c;
          if(maze->cells[i][j] == START){
              maze->startRow = i;
              maze->startColumn = j;
          }
          if(maze->cells[i][j] == END){
              maze->endRow = i;
              maze->endColumn = j;
          }
      }
  }
  return maze;
}
 


 
void destroyMaze(maze_t * maze)
{
   int i;
   for(i=0; i<maze->height; i++){
       free(maze->cells[i]);
   }// frees the individual cells
   free(maze->cells); // frees the cells array
   free(maze); //frees the struct
}
 
 
 
 
void printMaze(maze_t * maze)
{
   int i,j;
   for(i=0; i<maze->height; i++){
       for(j=0; j<maze->width; j++){
           printf("%c", maze->cells[i][j]);
       }// nested loop that goes thourgh printing the 2d maze
       printf("\n"); // print new line
   }
}

int solveMazeDFS(maze_t * maze, int col, int row)
{
    if (row<0 || col<0 || col > (maze->width-1) || row > (maze->height-1))// check if out of maze bounds
    {
        return 0;
    }
    if(maze->cells[row][col]== WALL || maze->cells[row][col]== PATH || maze->cells[row][col]== VISITED)// check if empty
    {
        return 0;
    }
    if ((maze->cells[row][col])== END)// check if end of the maze
    {
        maze->cells[maze->startRow][maze->startColumn] = START; // set start back to start
        return 1;
    }

    if ( ((maze->cells[row][col])== EMPTY)|| maze->cells[row][col]== START)//my maze was acting weird around its starting point so ill just set it to a olution
    {

        maze->cells[row][col]= PATH;// mark as solution but make sure its not the start or end
    }
    

    if (solveMazeDFS(maze, col-1, row)==1)// check around the part of the maze
    {
        return 1;
    }
    if (solveMazeDFS(maze, col+1, row)==1)// check around the part of the maze
    {
        return 1;
    }
    if (solveMazeDFS(maze, col, row-1)==1)// check around the part of the maze
    {
        return 1;
    }
    if (solveMazeDFS(maze, col, row+1)==1)// check around the part of the maze
    {
        return 1;
    }
    if ( ((maze->cells[row][col])!= END) && ((maze->cells[row][col])!= START))
        maze->cells[row][col]= VISITED;// mark as visited but make sure its not the start or end
   
    return 0;
}
