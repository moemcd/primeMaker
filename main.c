//
//  main.c
//  hw06
//
//  Created by Morgan  McDowell on 3/30/17.
//  Copyright © 2017 Morgan  McDowell. All rights reserved.
//
#include <stdio.h>
#include <math.h>

//constants
#define SIZE  20

//function declarations
void getInput(int[]);
int checkPrime(int);
void getPrimeVec(int [], int[]);
void print(int[]);

int main()
{
    int input[SIZE];     //initiaizes input vector
    int res[SIZE] = {0}; //initializes resulting vector
    
    //statements
    getInput(input);
    getPrimeVec(input, res);
    print(res);
    
    return 0;
}

void getInput(int input[SIZE])
{
    int i;
    
    printf("Enter data now: ");
    for(i = 0; i < SIZE; i++)
        scanf("%d", &input[i]);
}

int checkPrime (int num)
{
    int i;
    
    for (i = 2; i < num; i++)
    {
        if (num % i == 0 && i != num)
            return 0;
    }
    return 1;
}

void getPrimeVec(int input[SIZE], int res[SIZE])
{
    int i;
    int num;
    
    for (i = 0; i < SIZE; i++)                       //for loop to check every integer in array
        if (checkPrime(input[i]) == 0)               //decides if the current value is prime or not
        {
            if (i == 0)
                num = (input[i] * input[i]) + 1;    //sets starting number if it is the first value in an array
            else
                num = input[i] * res[i - 1];      //sets starting value if it is any other location in array
            
            while (checkPrime(num) == 0)         //searches for next prime number
            {
                checkPrime(num);
                num ++;
            }
            res[i] = num;
        }
        else
            res[i] = input[i];
}


void print(int res[SIZE])
{
    int i;
    printf("Final prime data: ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", res[i]);
}
