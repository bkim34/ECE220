/*
 * countLiveNeighbor
 * Inputs:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * row: the row of the cell that needs to count alive neighbors.
 * col: the col of the cell that needs to count alive neighbors.
 * Output:
 * return the number of alive neighbors. There are at most eight neighbors.
 * Pay attention for the edge and corner cells, they have less neighbors.
 */

int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){
    int alive_neighbors = 0;
    for(int i = row-1; i<= row+1; i++) // traverse thru rows
    {
        if (i>=0 && i<boardRowSize) // make sure it is on the board
        {
            for (int j = col-1; j<= col+1; j++) // traverse through columns 
            {
                if (j>=0 && j<boardColSize) //make sure valid column
                {
                    if(i!=row || j!=col) //make sure it isnt the cell
                    {
                        if(board[boardColSize*i+j]==1) //check if dead or alive 
                        {
                            alive_neighbors++; //increment if alive
                        }
                    }
                }
            }
        }
    }
    return alive_neighbors; // return number alive
}
/*
 * Update the game board to the next step.
 * Input: 
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */
void updateBoard(int* board, int boardRowSize, int boardColSize) {
    int board_copy[boardRowSize*boardColSize]; // i realize you need an empty board otherwise you modify the neighbors while checking other neighbors
    for(int i=0; i<boardRowSize; i++)
    {
        for(int j=0; j<boardColSize; j++)
        {
            int cells_alive = countLiveNeighbor(board,boardRowSize, boardColSize,i,j);
            {
                if (cells_alive==3 || (board[i*boardColSize+j]==1 && cells_alive==2))
                {
                    board_copy[boardColSize*i+j]=1;
                }
                else
                {
                    board_copy[boardColSize*i+j]=0;
                }
            }
        }
    }
    // you now need to copy the clone into the real board
    for(int k=0; k<boardRowSize; k++)
    {
        for(int l=0; l<boardColSize; l++)
        {
            board[k*boardColSize+l]= board_copy[k*boardColSize+l];
        }
    }
}

/*
 * aliveStable
 * Checks if the alive cells stay the same for next step
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: return 1 if the alive cells for next step is exactly the same with 
 * current step or there is no alive cells at all.
 * return 0 if the alive cells change for the next step.
 */ 
int aliveStable(int* board, int boardRowSize, int boardColSize)
{
    int board_copy_two[boardRowSize*boardColSize]; // create copy array to compare the two

    for(int i=0; i<boardRowSize; i++)// traverse through arrays
    {
        for(int j=0; j<boardColSize; j++)
        {
            board_copy_two[i*boardColSize+j]= board[i*boardColSize+j]; // copy array into copy
        }
    }
    updateBoard(board,boardRowSize, boardColSize); //call the next step 
    for(int i=0; i<boardRowSize; i++) // traverse through arrays
    {
        for(int j=0; j<boardColSize; j++)
        {
            if (board_copy_two[i*boardColSize+j]!= board[i*boardColSize+j])
            {
                return 0; //return 0 since the boards aren't identical
            }
        }
    }
    return 1; //return 1 since the boards are identical
}

				
				
			

