; partners Thomasp6, Jaejin2
;
;
; The code given to you here implements the histogram calculation that
; we developed in class.  In programming lab, we will add code that
; prints a number in hexadecimal to the monitor.
;
; Your assignment for this program is to combine these two pieces of
; code to print the histogram to the monitor.
;
; If you finish your program,
;    ** commit a working version to your repository  **
;    ** (and make a note of the repository version)! **
 
 
    .ORIG    x3000        ; starting address is x3000
 
 
;
; Count the occurrences of each letter (A to Z) in an ASCII string
; terminated by a NUL character.  Lower case and upper case should
; be counted together, and a count also kept of all non-alphabetic
; characters (not counting the terminal NUL).
;
; The string starts at x4000.
;
; The resulting histogram (which will NOT be initialized in advance)
; should be stored starting at x3F00, with the non-alphabetic count
; at x3F00, and the count for each letter in x3F01 (A) through x3F1A (Z).
;
; table of register use in this part of the code
;    R0 holds a pointer to the histogram (x3F00)
;    R1 holds a pointer to the current position in the string
;       and as the loop count during histogram initialization
;    R2 holds the current character being counted
;       and is also used to point to the histogram entry
;    R3 holds the additive inverse of ASCII '@' (xFFC0)
;    R4 holds the difference between ASCII '@' and 'Z' (xFFE6)
;    R5 holds the difference between ASCII '@' and '`' (xFFE0)
;    R6 is used as a temporary register
;
 
    LD R0,HIST_ADDR          ; point R0 to the start of the histogram
    
    ; fill the histogram with zeroes
    AND R6,R6,#0        ; put a zero into R6
    LD R1,NUM_BINS        ; initialize loop count to 27
    ADD R2,R0,#0        ; copy start of histogram into R2
 
    ; loop to fill histogram starts here
HFLOOP    STR R6,R2,#0        ; write a zero into histogram
    ADD R2,R2,#1        ; point to next histogram entry
    ADD R1,R1,#-1        ; decrement loop count
    BRp HFLOOP        ; continue until loop count reaches zero
 
    ; initialize R1, R3, R4, and R5 from memory
    LD R3,NEG_AT        ; set R3 to additive inverse of ASCII '@'
    LD R4,AT_MIN_Z        ; set R4 to difference between ASCII '@' and 'Z'
    LD R5,AT_MIN_BQ        ; set R5 to difference between ASCII '@' and '`'
    LD R1,STR_START        ; point R1 to start of string
 
    ; the counting loop starts here
COUNTLOOP
    LDR R2,R1,#0        ; read the next character from the string
    BRz PRINT_HIST        ; found the end of the string
 
    ADD R2,R2,R3        ; subtract '@' from the character
    BRp AT_LEAST_A        ; branch if > '@', i.e., >= 'A'
NON_ALPHA
    LDR R6,R0,#0        ; load the non-alpha count
    ADD R6,R6,#1        ; add one to it
    STR R6,R0,#0        ; store the new non-alpha count
    BRnzp GET_NEXT        ; branch to end of conditional structure
AT_LEAST_A
    ADD R6,R2,R4        ; compare with 'Z'
    BRp MORE_THAN_Z         ; branch if > 'Z'
 
; note that we no longer need the current character
; so we can reuse R2 for the pointer to the correct
; histogram entry for incrementing
ALPHA    ADD R2,R2,R0        ; point to correct histogram entry
    LDR R6,R2,#0        ; load the count
    ADD R6,R6,#1        ; add one to it
    STR R6,R2,#0        ; store the new count
    BRnzp GET_NEXT        ; branch to end of conditional structure
 
; subtracting as below yields the original character minus '`'
MORE_THAN_Z
    ADD R2,R2,R5        ; subtract '`' - '@' from the character
    BRnz NON_ALPHA        ; if <= '`', i.e., < 'a', go increment non-alpha
    ADD R6,R2,R4        ; compare with 'z'
    BRnz ALPHA        ; if <= 'z', go increment alpha count
    BRnzp NON_ALPHA        ; otherwise, go increment non-alpha
 
GET_NEXT
    ADD R1,R1,#1        ; point to next character in string
    BRnzp COUNTLOOP        ; go to start of counting loop
 
 
 
PRINT_HIST
 
; you will need to insert your code to print the histogram here
 
; partners: Thomasp6, jaejin2
 
; The basic algorithm for this project is locating the histogram and printing the contents.
; First you load the address of the histogram into a register and increment it after every cycle so that you
; can obtain the values for each ascii letter. As stated in lab1, you have to create a loop with digits and
; bits in order to output the correct values that are obtained from the histogram. By loading 27 into a
; register, you can keep track of how many new lines to print, and stop once the regitser hits zero.
; By repeating the cycle of printing the ascii labels and printing the values until the bin counter hits zero,
; the program will eventually halt.
 
 
;R0 is the digit
;R1 is digit counter
;R2 is bit counter
;R3 stores value to print
;R4 holds histogram address
;R5 is bin counter
;R6 holds temp values
 
 
LD R4, HIST_ADDR ; R4 is the first address of histogram
AND R5,R5,#0 ; clear and set R5 to -1
ADD R5,R5,#-1
BIN_LOOP
    
    ADD R5,R5,#1 ; increment R5
    ADD R3,R4,R5 ; load R3 with current address of histogram
    LDR R3,R3,#0 ; load R3 with contents of R3
    AND R1,R1, #0
    ADD R1,R1, #4 ; digit counter set to 4
    LD R0, GET_AT ; load R0 with ascii value of @
    ADD R0, R0, R5 ; add R5 to R0
    OUT                ; print ascii labels
        
 
    LD R0, GET_SPACE ; print space
    OUT
 
TOP_LOOP
    AND R0,R0,#0
    ADD R1,R1, #0
    BRnz DONE ; if digit counter is zero, halt program
    ADD R0,R0, #0 ; init digit
    ADD R2,R2, #4 ; init bit counter to 4
 
INNER_LOOP
    
    ADD R2,R2, #0
    BRnz OUTER_LOOP ; if bit counter is <4 branch to outerloop
    ADD R0,R0,R0    ; left shift digit
    ADD R3,R3,#0    ;
    BRzp LEFT_SHIFT    ; if R3 < 0 add 0
    ADD R0,R0, #1    ; if not, add 1
 
LEFT_SHIFT
    ADD R3,R3,R3 ; left shift R3
    ADD R2,R2, #-1 ; decrement bit counter
    BRnzp INNER_LOOP ; jump back to inner loop
 
OUTER_LOOP
    ADD R6,R0, #-9 ; check if digit is <= 9
    BRp ADD_A    ; if true, add 0
    LD R6, GET_ZERO
    ADD R0,R6,R0
    BRnzp OUT_TRAP    
 
ADD_A
    LD R6, GET_A ; add A - 10
    ADD R6,R6,#-10
    ADD R0,R0,R6
 
OUT_TRAP
    ADD R1,R1,#-1 ; decrement digit counter
    OUT
    BRnzp TOP_LOOP
; do not forget to write a brief description of the approach/algorithm
; for your implementation, list registers used in this part of the code,
; and provide sufficient comments
DONE
LD R0, GET_NEWLINE ; print new line
OUT
LD R6, NUM_BINS ; load r6 with 27
NOT R6,R6    
ADD R6,R6,#2 ; subtract R6
ADD R6,R6,R5 ; add bin counter to R6
 
BRn BIN_LOOP
    
    HALT            ; done
 
 
; the data needed by the program
NUM_BINS    .FILL #27    ; 27 loop iterations
NEG_AT        .FILL xFFC0    ; the additive inverse of ASCII '@'
AT_MIN_Z    .FILL xFFE6    ; the difference between ASCII '@' and 'Z'
AT_MIN_BQ    .FILL xFFE0    ; the difference between ASCII '@' and '`'
HIST_ADDR    .FILL x3F00     ; histogram starting address
STR_START    .FILL x4000    ; string starting address
GET_ZERO     .FILL X0030 ; ASCII zero hex value
GET_A       .FILL x0041 ; ASCII A hex value
GET_AT         .FILL x0040 ; ASCII @ hex value
GET_SPACE     .FILL x0020 ; ASCII space hex value
GET_NEWLINE .FILL x000A ; new line character
; for testing, you can use the lines below to include the string in this
; program...
; STR_START    .FILL STRING    ; string starting address
; STRING        .STRINGZ "This is a test of the counting frequency code.  AbCd...WxYz."
 
 
 
    ; the directive below tells the assembler that the program is done
    ; (so do not write any code below it!)
 
    .END


