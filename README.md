# BF++
An expansion on the classic programming language Brainfuck.

## Explanation

BF++ is similar to Brainfuck in the way that the memory is set up as a one dimensional array, with a pointer that can be moved to specify which piece of memory to manipulate. However, BF++ also implements a reference pointer. This means that you can set a reference pointer to one part of memory, move to a different location, and manipulate the current memory location in relation to the referenced location.

To make it a little more clear, think of it like this:
[ 1 2 3 4 5 ] <- Here we have a small scale BF++ memory system. Our current pointer is at index 0.
  ^
**Run: @>**
[ 1 2 3 4 5 ] <- We set our reference pointer to index 0, and moved our current real pointer to index 1.
  @ ^
**Run: +**
[ 1 3 3 4 5 ] <- We just added the value at the reference pointer to the value at the current pointer.
  @ ^

## Syntax

#### Compiler Functions
**quit** -> Close the program.
**clear** -> Clear the screen.
**dump** -> Print all values in memory.
**debug** -> Toggle debug mode (prints i/o of all functions in real time).
**reset** -> Reset memory, pointer, reference pointer, etc.
**info** -> Print pointer and reference location and value.

#### Functions
** > ** -> Increment the memory pointer by one.
** < ** -> Decrement the memory pointer by one.
** + ** -> Increment by one, or add the reference value (if set).
** - ** -> Decrement by one, or subtract the reference value (if set).
** * ** -> Multiply by two, or multiply by the reference value (if set).
** / ** -> Divide by two, or divide by the reference value (if set).
** = ** -> Set the current memory to the value of the reference's memory.
** ! ** -> Invert the current memory's value.
** . ** -> Print the current memory's value.
** _ ** -> Print a space character (' ').
** , ** -> Recieve a numerical piece of user input to go into the current memory space.
** @ ** -> Set the reference pointer to the current memory pointer.
** x ** -> Un-set the reference pointer.
** s ** -> Swap the reference and current memory pointers.
** q ** -> Break execution of the current entered code.

#### If/While
** (x ) ** -> IF
- If a reference pointer is set, x can be:
  - ** = ** -> Check if current memory and reference memory are equal.
  - ** > ** -> Check if current memory is greater than reference memory.
  - ** < ** -> Check if current memory is less than reference memory.
  - ** ! ** -> Check if current memory is not equal to reference memory.
- If a reference pointer is **not** set, then it continues if the current memory value is non-zero.

** {x } ** -> WHILE
- If a reference pointer is set, x can be:
  - ** = ** -> Check if current memory and reference memory are equal.
  - ** > ** -> Check if current memory is greater than reference memory.
  - ** < ** -> Check if current memory is less than reference memory.
  - ** ! ** -> Check if current memory is not equal to reference memory.
  - ** 1 ** -> While will always repeat.
  - ** 0 ** -> Check if pointer is non-zero.
- If a reference pointer is **not** set, then it continues if the current memory value is non-zero.
