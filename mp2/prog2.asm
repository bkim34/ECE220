;partners JAEJIN2, thomasp6
;
;
.ORIG x3000
  
;your code goes here
;Basically our algorithm was to put in inputs and push them if they were numbers, and pop if it was an operator, as the flow chart 
;told us to, using the subroutines that were given to us and code. This program seems to mess up sometimes, but is able to add, 
;divide, subtract and multiply two digits pretty well, and detect when an expression is invalid. Our success comes from 
;successfully checking the characters imputed and pushing or popping when necessary. By following the flow chart and using what 
;we learned in class we were able to get most of the MP correct, but were not able to put it all together.

 
 
 
 
 
 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R3- value to print in hexadecimal
 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R0 - character input from keyboard
;R6 - current numerical output
;
;
EVALUATE
 
;your code goes here
; reading next input
POLL   
   GETC 
   ST R0, KB_CHAR ; store R0
   OUT
   ; checking if input is "="
   AND R1,R1,#0
   LD R1, EQUAL_VALUE  ; load R1 with ascii equal
   NOT R1,R1  
   ADD R1,R1,#1
   ADD R1,R0,R1    ; check if input is equal
   BRnp CHECK_SPACE ; false on flow chart
  
   ; checking if stack has one value  
   ;LD R1, STACK_TOP
   ;ADD R1,R1,#1
   ;LD R2, STACK_START
   ;NOT R2,R2
   ;ADD R2,R2,#1
   ;ADD R1,R1,R2
   ;BRnp INVALID
   ;JSR POP
   ;ADD R5,R5,#0
   ;BRp INVALID
  
   JSR POP
   ST R0, KB_CHAR  ; store R0
   ADD R5,R5,#0   
   BRnp INVALID    ; if R5 is neg or pos, print invalid
   JSR POP
   ADD R5,R5,#0    ; if R5 is zero, print invalid
   BRz INVALID
   LD R5, KB_CHAR  ; load R0 into both R5 and R3
   LD R3, KB_CHAR
   JSR PRINT_HEX   ; jump t the printing hex function and halt the program
   BRnzp DONE
 
CHECK_SPACE
   ; checking if input is " "
   AND R1,R1,#0
   LD R1, SPACE_VALUE  ; load R1 with ascii space
   NOT R1,R1
   ADD R1,R1,#1
   ADD R1,R0,R1
   BRz POLL    ; if it is space, jump back to top
 
   AND R2,R2,#0
   AND R1,R1,#0
  
   LD R1, EXP_VALUE    ; for these I load in the negative decimal values of the operators
   ADD R2,R0,R1        ; and jump to apply opertaor if it is one of them
   BRz APPLY_OPERATOR
 
   LD R1, ASTERISK_VALUE
   ADD R2,R0,R1
   BRz APPLY_OPERATOR
  
   LD R1, DIV_VALUE
   ADD R2,R0,R1
   BRz APPLY_OPERATOR
 
   LD R1, PLUS_VALUE
   ADD R2,R0,R1
   BRz APPLY_OPERATOR
 
   LD R1, MINUS_VALUE
   ADD R2,R0,R1
   BRz APPLY_OPERATOR
 
 
   LD R1, ZERO_VALUE   ; checking whether the value is inside the range of 0-9
   ADD R2,R0,R1
   BRn INVALID
  
   LD R1, NINE_VALUE
   ADD R2,R0,R1
   BRp INVALID
   JSR PUSH
   BRnzp EVALUATE
 
APPLY_OPERATOR
   JSR POP
   ST R0, INPUT_ONE    ; pop the values from the stack
  
   JSR POP
   ST R0, INPUT_TWO
   LD R3, INPUT_TWO
   LD R4, INPUT_ONE
 
   ADD R5,R5,#0
   BRnp INVALID
  
   ; CONVERT r3 from ascii to decimal
   LD R1, ASCII_0
   LD R5, INPUT_TWO
   AND R3,R3,#0
   ADD R3,R3,#0
   ADD R0,R1,R5
   BRz R3_DONE
 
   LD R1, ASCII_1
   LD R5, INPUT_TWO
   AND R3,R3,#0
   ADD R3,R3,#1
   ADD R0,R1,R5
   BRz R3_DONE
 
   LD R1, ASCII_2
   LD R5, INPUT_TWO
   AND R3,R3,#0
   ADD R3,R3,#2
   ADD R0,R1,R5
   BRz R3_DONE
 
   LD R1, ASCII_3
   LD R5, INPUT_TWO
   AND R3,R3,#0
   ADD R3,R3,#3
   ADD R0,R1,R5
   BRz R3_DONE
 
   LD R1, ASCII_4
   LD R5, INPUT_TWO
   AND R3,R3,#0
   ADD R3,R3,#4
   ADD R0,R1,R5
   BRz R3_DONE
 
   LD R1, ASCII_5
   LD R5, INPUT_TWO
   AND R3,R3,#0
   ADD R3,R3,#5
   ADD R0,R1,R5
   BRz R3_DONE
 
   LD R1, ASCII_6
   LD R5, INPUT_TWO
   AND R3,R3,#0
   ADD R3,R3,#6
   ADD R0,R1,R5
   BRz R3_DONE
 
   LD R1, ASCII_7
   LD R5, INPUT_TWO
   AND R3,R3,#0
   ADD R3,R3,#7
   ADD R0,R1,R5
   BRz R3_DONE
 
   LD R1, ASCII_8
   LD R5, INPUT_TWO
   AND R3,R3,#0
   ADD R3,R3,#8
   ADD R0,R1,R5
   BRz R3_DONE
 
   LD R1, ASCII_9
   LD R5, INPUT_TWO
   AND R3,R3,#0
   ADD R3,R3,#9
   ADD R0,R1,R5
   BRz R3_DONE
 
   ; add rest from 0-9
R3_DONE
   LD R1, ASCII_1
   LD R5, INPUT_ONE
   AND R4,R4,#0
   ADD R4,R4,#1
   ADD R0,R1,R5
   BRz R4_DONE
 
   LD R1, ASCII_2
   LD R5, INPUT_ONE
   AND R4,R4,#0
   ADD R4,R4,#2
   ADD R0,R1,R5
   BRz R4_DONE
 
   LD R1, ASCII_3
   LD R5, INPUT_ONE
   AND R4,R4,#0
   ADD R4,R4,#3
   ADD R0,R1,R5
   BRz R4_DONE
 
   LD R1, ASCII_4
   LD R5, INPUT_ONE
   AND R4,R4,#0
   ADD R4,R4,#4
   ADD R0,R1,R5
   BRz R4_DONE
 
   LD R1, ASCII_5
   LD R5, INPUT_ONE
   AND R4,R4,#0
   ADD R4,R4,#5
   ADD R0,R1,R5
   BRz R4_DONE
 
   LD R1, ASCII_6
   LD R5, INPUT_ONE
   AND R4,R4,#0
   ADD R4,R4,#6
   ADD R0,R1,R5
   BRz R4_DONE
 
   LD R1, ASCII_7
   LD R5, INPUT_ONE
   AND R4,R4,#0
   ADD R4,R4,#7
   ADD R0,R1,R5
   BRz R4_DONE
 
   LD R1, ASCII_8
   LD R5, INPUT_ONE
   AND R4,R4,#0
   ADD R4,R4,#8
   ADD R0,R1,R5
   BRz R4_DONE
 
   LD R1, ASCII_9
   LD R5, INPUT_ONE
   AND R4,R4,#0
   ADD R4,R4,#9
   ADD R0,R1,R5
   BRz R4_DONE
 
R4_DONE
   ;AND R3,R3,#0
   ;ADD R3,R3,R0
   ;JSR POP
   ;ADD R4,R4,#0
   ;ADD R4,R4,R0
   ;LD R0, KB_CHAR
   ; possibly issue, might just need to check R5
   ;LD R2, STACK_TOP
   ;LD R1, STACK_START
   ;NOT R1,R1
   ;ADD R1,R1,#1
   ;ADD R2,R2,R1
   ;BRp INVALID
  
   LD R0, KB_CHAR
 
CHECK_EXP      
   LD R1, EXP_VALUE ; check for the specific operator
   ADD R2,R0,R1
   BRnp CHECK_MUL  ; if its not the indicated operator, move on to next operator
   JSR EXP         ; if it is the right operator, jump to the subroutine and push
   JSR PUSH
   BRnzp EVALUATE
 
CHECK_MUL           ; repeat for rest
   LD R1, ASTERISK_VALUE
   ADD R2,R0,R1
   BRnp CHECK_DIV
   JSR MUL
   JSR PUSH
   BRnzp EVALUATE
CHECK_DIV  
   LD R1, DIV_VALUE
   ADD R2,R0,R1
   BRnp CHECK_PLUS
   JSR DIV
   JSR PUSH
   BRnzp EVALUATE
CHECK_PLUS
   LD R1, PLUS_VALUE
   ADD R2,R0,R1
   BRnp CHECK_MIN
   ADD R0,R3,R4
   JSR PUSH
   BRnzp EVALUATE
CHECK_MIN
   LD R1, MINUS_VALUE
   ADD R2,R0,R1
   JSR MIN
   JSR PUSH
   BRnzp EVALUATE
 
INVALID
   LEA R0, PRINT_INVALID   ; prints "Invalid expression"
   PUTS
   BRnzp DONE
 
 
 
 
 
DONE
   HALT
 
 
   PRINT_INVALID .STRINGZ "Invalid expression"
   EXP_VALUE   .FILL #-94
   ASTERISK_VALUE .FILL #-42
   PLUS_VALUE  .FILL #-43
   MINUS_VALUE .FILL #-45
   DIV_VALUE   .FILL #-47
   ZERO_VALUE  .FILL #-48
   NINE_VALUE  .FILL #-57
   SPACE_VALUE .FILL x0020
   EQUAL_VALUE .FILL x003D
   KB_CHAR     .BLKW #1
   INPUT_ONE   .BLKW #1
   INPUT_TWO   .BLKW #1
 
   ASCII_0     .FILL #-48
   ASCII_1     .FILL #-49
   ASCII_2     .FILL #-50
   ASCII_3     .FILL #-51
   ASCII_4     .FILL #-52
   ASCII_5     .FILL #-53
   ASCII_6     .FILL #-54
   ASCII_7     .FILL #-55
   ASCII_8     .FILL #-56
   ASCII_9     .FILL #-57
 
 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
PLUS   
;your code goes here
ST R7, SAVE_R7
ADD R0,R3,R4
LD R7, SAVE_R7
RET
 
SAVE_R7 .BLKW #1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MIN
;your code goes here
NOT R0,R4
ADD R0,R0,#1        ; 2's complement inverse and add
ADD R0,R3,R0
RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MUL
;your code goes here
   ST R4, MUL_SAVER4
   AND R0,R0,#0    ; clear r0
MUL_LOOP
   ADD R0,R0,R3    ; add input with R0
   ADD R4,R4,#-1   ; decrement R4
   BRp MUL_LOOP    ; jump back up only if positive
   LD R4,MUL_LOOP  ; load back orig value
   RET
 
 
 
MUL_SaveR4  .BLKW #1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
DIV
;your code goes here
   ST R4,DIV_SAVER4
   ST R3,DIV_SAVER3
  
   AND R0,R0,#0    ; clear register
   NOT R4,R4
   ADD R4,R4,#1    ; inverse the value
DIV_LOOP
   ADD R3,R3,R4    ; add the inverse wth r3
   BRn DIV_END     ; if negative, jump to end
   ADD R0,R0,#1    ; increment and go through loop again
   BRnzp DIV_LOOP
 
DIV_END
   LD R4, DIV_SAVER4
   ADD R1,R3,R4   
   LD R3, DIV_SAVER3
   LD R4, DIV_SAVER4
  
RET
 
DIV_SAVER3 .BLKW #1
DIV_SAVER4 .BLKW #1
  
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
EXP
;your code goes here
   ; basically the power is how many times we mult the two together, so that is decremented each time we do multiplication. because for
; the mult function it multiplies r3 by r4, we set r4 to the base number and r3 to the multiplication sum
   ST R2, EXP_SAVER2
  ST R3, EXP_SAVER3
  ST R4, EXP_SAVER4
  ST R5, EXP_SAVER5
  AND R2, R2, #0
  ADD R2, R2, R4; r2 is the incrementer so we know how many times to multiply
  AND R5, R5, #0
  ADD R5, R5, R3;
 
    
EXPLOOPOUTER
  ADD R5, R5, R0
  ADD R2, R2, #-1
  BRp EXPDONE   
EXPLOOPINNER
  ADD R0, R0, R3
  ADD R5, R5, #-1
  BRp EXPLOOPINNER
  BRnzp EXPLOOPOUTER
 
EXPDONE
  LD R2, EXP_SAVER2
  LD R3, EXP_SAVER3
  LD R4, EXP_SAVER4
  LD R5, EXP_SAVER5
RET
EXP_SAVER2 .BLKW #1
EXP_SAVER3 .BLKW #1
EXP_SAVER4 .BLKW #1
EXP_SAVER5 .BLKW #1
 
;IN:R0, OUT:R5 (0-success, 1-fail/overflow)
;R3: STACK_END R4: STACK_TOP
;
PUSH   
   ST R3, PUSH_SaveR3  ;save R3
   ST R4, PUSH_SaveR4  ;save R4
   AND R5, R5, #0      ;
   LD R3, STACK_END    ;
   LD R4, STACk_TOP    ;
   ADD R3, R3, #-1     ;
   NOT R3, R3      ;
   ADD R3, R3, #1      ;
   ADD R3, R3, R4      ;
   BRz OVERFLOW        ;stack is full
   STR R0, R4, #0      ;no overflow, store value in the stack
   ADD R4, R4, #-1     ;move top of the stack
   ST R4, STACK_TOP    ;store top of stack pointer
   BRnzp DONE_PUSH     ;
OVERFLOW
   ADD R5, R5, #1      ;
DONE_PUSH
   LD R3, PUSH_SaveR3  ;
   LD R4, PUSH_SaveR4  ;
   RET
 
 
PUSH_SaveR3 .BLKW #1    ;
PUSH_SaveR4 .BLKW #1    ;
 
 
;OUT: R0, OUT R5 (0-success, 1-fail/underflow)
;R3 STACK_START R4 STACK_TOP
;
POP
   ST R3, POP_SaveR3   ;save R3
   ST R4, POP_SaveR4   ;save R3
   AND R5, R5, #0      ;clear R5
   LD R3, STACK_START  ;
   LD R4, STACK_TOP    ;
   NOT R3, R3      ;
   ADD R3, R3, #1      ;
   ADD R3, R3, R4      ;
   BRz UNDERFLOW       ;
   ADD R4, R4, #1      ;
   LDR R0, R4, #0      ;
   ST R4, STACK_TOP    ;
   BRnzp DONE_POP      ;
UNDERFLOW
   ADD R5, R5, #1      ;
DONE_POP
   LD R3, POP_SaveR3   ;
   LD R4, POP_SaveR4   ;
   RET
 
 
POP_SaveR3  .BLKW #1    ;
POP_SaveR4  .BLKW #1    ;
STACK_END   .FILL x3FF0 ;
STACK_START .FILL x4000 ;
STACK_TOP   .FILL x4000 ;
 
 
 
 
 
 
 
 
PRINT_HEX  
 
 
AND R1,R1, #0
ADD R1,R1, #4 ; digit counter set to 4
 
 
TOP_LOOP
   AND R0,R0,#0
   ADD R1,R1, #0
   BRnz DONE ; if digit counter is zero, halt program
   ADD R0,R0, #0 ; init digit
   ADD R2,R2, #4 ; init bit counter to 4
 
INNER_LOOP
  
   ADD R2,R2, #0
   BRnz OUTER_LOOP ; if bit counter
   ADD R0,R0,R0
   ADD R3,R3,#0
   BRzp LEFT_SHIFT
   ADD R0,R0, #1
 
LEFT_SHIFT
   ADD R3,R3,R3
   ADD R2,R2, #-1
   BRnzp INNER_LOOP
 
OUTER_LOOP
   ADD R6,R0, #-9
   BRp ADD_SEVEN
   LD R6, GET_ZERO
   ADD R0,R6,R0
   BRnzp OUT_TRAP 
 
ADD_SEVEN
   LD R6, GET_A
   ADD R6,R6,#-10
   ADD R0,R0,R6
 
OUT_TRAP
   OUT
   ADD R1,R1,#-1
   BRnzp TOP_LOOP
 
 
GET_ZERO    .FILL x0030 ; ASCII zero hex value
GET_A       .FILL x0041 ; ASCII A hex value
 
 
 
 
 
 
.END
 

