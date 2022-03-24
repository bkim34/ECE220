#include "sudoku.h"

// partners jaejin2 thomasp6
//This program has 5 major functions: is_val_in_row, is_val_in_col, is_val_in_3x3_zone, is_val_valid, all_cells_assigned, and solve_sudoku
//is_val_row and is_val_col find whether val is in the certain row and column, and is_val_in_3x3_zone checks if val is in the 3x3 zone
//is val_valid uses all the 3 previous function to determine if val can be used. The private function all_cells_assigned checks whether if all the cells have numbers assigned
//solve_sudoku uses the 2 previous function and it is the core function of the game.
//-------------------------------------------------------------------------------------------------
// Start here to work on your MP7
//-------------------------------------------------------------------------------------------------
 
// You are free to declare any private functions if needed.
 
// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {
 
 assert(i>=0 && i<9);
 
 // BEG TODO
 for(int c = 0; c<9; c++){
   if(val == sudoku[i][c]){
     return 1; //the for loop will go through every column in the row until val is found
   }
 }
 return 0;
 // END TODO
}
 
// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {
 
 assert(j>=0 && j<9);
 
 // BEG TODO
 for(int r = 0; r<9; r++){
   if(val == sudoku[r][j]){
     return 1; //the for loop will go though every row in the column until val is found
   }
 }
 return 0;
 // END TODO
}
 
// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {
 
 assert(i>=0 && i<9);
  // BEG TODO
 int correct_row = int(i/3)*3; //the correct row will be either 0,3,6 and is set according to i
 int correct_col = int(j/3)*3; //the correct column will be either 0,3,6 and is set according to j
 for(int r=correct_row; r<correct_row+3; r++){
   for(int c=correct_col; c<correct_col+3; c++){
     if(val == sudoku[r][c]){
       return 1; //the nested for loop will go through the 3x3 until val is found
     }
   }
 }
 return 0;
 // END TODO
}
 
// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {
 
 assert(i>=0 && i<9 && j>=0 && j<9);
 
 // BEG TODO
 if(is_val_in_3x3_zone(val,i,j,sudoku) || is_val_in_col(val,j,sudoku) || is_val_in_row(val,i,sudoku)){
   return 0; //if any of the conditions are true, val is not valid
 }
 return 1; //if none of those are true, val is valid
 // END TODO
}
 
//private helper function that will check if all cells are assigned by numbers
int all_cells_assigned(int sudoku[9][9]){
 for(int r=0; r<9; r++){
   for(int c=0; c<9; c++){
     if(sudoku[r][c] == 0){
       return 0; //if a cell is not assigned, the function will return zero
     }
   }
 }
 return 1; //return one if all cells are assigned by numbers
}
 
// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {
 
 // BEG TODO.
 int i = -1;
 int j = -1;
 if(all_cells_assigned(sudoku)){
   return 1; // return true if all cells are assigned
 }
 else{
   for(int r=0; r<9; r++){
     for(int c=0; c<9; c++){
       if(sudoku[r][c] == 0){
         i = r; //the nested loop will find a nonfilled cell
         j = c; //and set i and j with the row and col of that cell
         break; //break the inner loop
       }
     }
     if(i != -1 || j != -1){
       break; //break the outer loop
     }
   }
 }
 for(int num =1; num<=9; num++){
   if(is_val_valid(num,i,j,sudoku)){
     sudoku[i][j] = num;
     if(solve_sudoku(sudoku)){
       return 1;
     }
     sudoku[i][j] = 0;
   }
 }
 return 0;
 // END TODO.
}
 
// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
 int i, j;
 for(i=0; i<9; i++) {
   for(j=0; j<9; j++) {
     printf("%2d", sudoku[i][j]);
   }
   printf("\n");
 }
}
 
// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
 FILE *reader = fopen(fpath, "r");
 assert(reader != NULL);
 int i, j;
 for(i=0; i<9; i++) {
   for(j=0; j<9; j++) {
     fscanf(reader, "%d", &sudoku[i][j]);
   }
 }
 fclose(reader);
}
 
 
