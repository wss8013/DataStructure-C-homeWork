//Shasha Wang
//wang.shas@northeastern.edu
#include<stdio.h>
int main()
{
  int a,b,c,choice;
  //Ask user for input of choice
  printf("Enter your choice\n");
  printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
  //Read user input
  scanf("%d",&choice);
  //Ask user for input of the two numbers
  printf("Enter a and b values\n");
  //Read user input
  scanf("%d %d", &a, &b);
  //Print the output according to user's choice
  switch (choice){
  case(1):
    c = a + b;
    printf("Addition\nSum = %d\n", c);
    break;
  case(2):
    c = a - b;
    printf("Subtraction\nDifference = %d\n", c);
    break;         
  case(3):
    c = a * b;
    printf("Multiplication\nProduct = %d\n",c);	
    break;
  case(4):
    c = a / b;
    printf("Division\nDividend = %d\n",c);
    break;
  //Print out the default message if user's input is invalid
  default:
    printf("Invalid input!\n");
    break; 
  }
               
  return 0;
}
