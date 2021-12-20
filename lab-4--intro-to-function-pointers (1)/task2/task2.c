#include <stdio.h>
#include <stdlib.h>

const int x = 12;
const int y = 7;

typedef int (*comparer) (int x, int y);

/* IMPLEMENT ME: Declare your functions here */
int add (int x, int y) { printf ("Adding 'x' and 'y'\n"); return x + y; }
int subtract (int x, int y) { printf ("Subtracting 'y' from 'x'\n"); return x - y; }
int multiply (int x, int y) { printf ("Multiplying 'x' and 'y'\n"); return x * y; }
int divide (int x, int y) { printf ("Dividing 'x' from 'y'\n"); return x / y; }
int exit_calculator (int x, int y) {
  printf ("Exiting program\n");
  exit(EXITTED);
    return EXITTED;
}

/*
int add (int x, int y) {
  printf("Adding x and y\n"); 
  return x + y;
}
int substract(int x, int y) {
  printf ("Subtracting y from x\n ");
  return x - y;
}
int multiply(int x, int y) {
  printf ("Multiplying y and x\n ");
  return x * y;
}
int divide(int x, int y) {
  printf ("Dividing y from x\n ");
  return x / y;
}
int exit_calculator (int x, int y) {
  printf ("Exiting program\n");
  exit(EXITTED);
    return EXITTED;
} */

int calculation_func(int x, int y, comparer compare) {
  return compare(x,y);
}
int(*calculation_options[5]) (int a, int b);


int main (void)
{
	/* IMPLEMENT ME: Insert your algorithm here */
  char user_selection;
  int answer; 
  
      calculation_options[0] = add;
      calculation_options[1] = subtract;
      calculation_options[2] = multiply;
      calculation_options[3] = divide;
      calculation_options[4] = exit_calculator;
  
  printf("x: %d | y: %d\n", x,y);
  printf("Choose your operation:\n");
  printf("(0: add | 1: subtract | 2: multiply | 3: divide | 4: exit):\n");
  
      scanf("%c", &user_selection);
      int func_index = atoi(&user_selection);
  
      answer = calculation_func(x,y, *calculation_options[func_index]);
      printf("answer = %d\n", answer);

      return EXITTED;
}

/* IMPLEMENT ME: Define your functions here */
