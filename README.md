# Push_swap
A sorting algorithm with specific movements



A sorting algorithm with specific moves

push swap performs the ordering from lowest to highest according to the moves below and between two stacks, "a & b"

instruction
description
sa
Swap A - swap the first 2 elements at the top of stack A.
sb
Swap B - swap the first 2 elements at the top of stack B.
pa
Push A - take the first element at the top of B and put it at the top of A.
pb
Push B - take the first element at the top of A and put it at the top of B.
ra
Rotate A - shift up all elements of stack a by 1. The first element becomes the last one.
rb
Rotate B - shift up all elements of stack a by 1. The first element becomes the last one.
rra
Reverse rotate A - shift down all elements of stack a by 1. The last element becomes the first one.
rrb
Reverse rotate B - shift down all elements of stack a by 1. The last element becomes the first one.+


he performs around 800 moves with 100 numbers and around 8500 with 500 numbers


to run just do:

-make
./push <random numbers>

just replace "random numbers" with the amount of numbers you want,
