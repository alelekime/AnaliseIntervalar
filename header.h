#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <fenv.h>

typedef union{
    int32_t i;
    float f;
    struct{
        uint32_t mantissa : 23;
        uint32_t exponent : 8;
        uint32_t sign : 1;
    } parts;
    
} Float_t;


typedef struct variable {
  struct variable* next;
  char* name;
  Float_t value;
  int number;
}variable;



typedef struct range {
  struct range* next;
  char* name;
  float min;
  float max;
    int number;
}range;

//create a list
void createNode(variable* variableList, range* variableRange, int variableNumber);

//fill node with resuslts
void fillVariable(variable* variableList, range* variableRange, int variableNumber);
void fillRange(variable* variableList, range* variableRange, int m, int n);
void findValue(char* variableName, char* var1, char* var2, range* variableRange, int operation);

//calculete operations
Float_t calculateVariable(Float_t var1, Float_t var2, int operation);

//find minimum or maximum
Float_t calculateValueMinimum(Float_t num1Min,Float_t num1Max,Float_t num2Min,Float_t num2Max, int operation);
Float_t calculateValueMaximum(Float_t num1Min,Float_t num1Max,Float_t num2Min,Float_t num2Max, int operation);

//calculate the m(x)
float minimumVariable(Float_t variable);
//calculate the M(x)
float maximumVariable(Float_t variable);

//search in list the values
float findVariableMin(char* var, range* variableRange);
float findVariableMax(char* var, range* variableRange);

//find the symbol is the operation
int findOperation(char* symbol);

// print result
void printList(range* VariableRange, int variableNumber);
void checkRange(range* variableRange, int m);
void checkInf(Float_t num);
void printNode(variable* variableList, range* variableRange,  int variableNumber, int m);
void printRange(Float_t num1, Float_t num2);
