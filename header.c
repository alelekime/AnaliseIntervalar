#include "header.h"

float minimumVariable(Float_t variable) {
  float range;
  int aux = variable.f - 1;
  range = nextafterf(variable.f, aux);
  return range;
}

float maximumVariable(Float_t variable) {
  float range;
  int aux = variable.f + 1;

  range = nextafterf(variable.f, aux);
  return range;
}

void fillVariable(variable* variableList, range* variableRange, int variableNumber) {
  char* expression = (char*)malloc(sizeof(char) * 200);
  float num1;
  Float_t num;
  char* variableName;

  for (int i = 0; i <variableNumber; i++) {
    fgets(expression, 200, stdin);

    variableList->name = strdup(strtok(expression, " "));

    variableRange->name = variableList->name;

    num.f = strtof(strtok(NULL,""), NULL);


    variableList->value = num;
    variableRange -> min = minimumVariable(variableList->value);
    variableRange -> max = maximumVariable(variableList->value);


    variableList = variableList -> next;
    variableRange = variableRange -> next;


  }
}

void fillRange(variable* variableList, range* variableRange, int m, int n){
  char* expression = (char*)malloc(sizeof(char) * 15);
  char* variableName, *var1,  *symbol,*name;
  char *var2 = (char*)malloc(sizeof(char) * 3);
  int operation;
  for (size_t i = 0; i < n; i++) {
    fgets(expression, 15, stdin);
    variableName  = strdup(strtok(expression, " "));
    var1 = strdup(strtok(NULL, " "));
    var1 = strdup(strtok(NULL, " "));

    symbol = strdup(strtok(NULL, " "));
    operation = findOperation(symbol);

    name= strdup(strtok(NULL, " "));
    strncpy(var2, name,(strlen(name)-1));
    findValue(variableName, var1, var2, variableRange, operation);
  }

}

void findValue(char* variableName, char* var1, char* var2, range* variableRange, int operation) {
  Float_t num1Min,num1Max, num2Min,num2Max;
  Float_t resul1, resul2;
  Float_t num, num1, num2, num3;

  num1Min.f = findVariableMin(var1, variableRange);
  num1Max.f = findVariableMax(var1, variableRange);
  num2Min.f = findVariableMin(var2, variableRange);
  num2Max.f = findVariableMax(var2, variableRange);

  do {
    variableRange = variableRange -> next;
  } while(variableRange -> name != NULL);

  variableRange -> name = variableName;
  switch (operation) {
    case 1:
      variableRange -> min = minimumVariable(calculateVariable(num1Min,num2Min, operation));
      variableRange -> max = maximumVariable(calculateVariable(num1Max,num2Max, operation));
      break;
    case 2:
      variableRange -> min = minimumVariable(calculateVariable(num1Min,num2Max, operation));
      variableRange -> max = maximumVariable(calculateVariable(num1Max,num2Min, operation));
      break;

    case 3:
      resul1 = calculateValueMinimum(num1Min, num1Max, num2Min,num2Max, operation);

      resul2 = calculateValueMaximum(num1Min, num1Max, num2Min,num2Max, operation);

      variableRange -> min = resul1.f;
      variableRange -> max = resul2.f;
      break;
    case 4:
      resul1 = calculateValueMinimum(num1Min, num1Max, num2Min,num2Max, operation);
      resul2 = calculateValueMaximum(num1Min, num1Max, num2Min,num2Max, operation);


      variableRange -> min = resul1.f;
      variableRange -> max = resul2.f;


      break;

  }


}

Float_t calculateValueMinimum(Float_t num1Min,Float_t num1Max,Float_t num2Min,Float_t num2Max, int operation) {
  float result1Min,result1Max, result2Min,result2Max;
  Float_t num;

  result1Min = minimumVariable(calculateVariable(num1Min,num2Min, operation));
  result1Max = minimumVariable(calculateVariable(num1Min,num2Max, operation));
  result2Min = minimumVariable(calculateVariable(num1Max,num2Min, operation));
  result2Max = minimumVariable(calculateVariable(num1Max,num2Max, operation));

  if (islessequal(result1Min, result1Max) && islessequal(result1Min, result2Min) && islessequal(result1Min, result2Max)) {
    num.f = result1Min;

  } else if (islessequal(result1Max, result1Min) && islessequal(result1Max, result2Min) && islessequal(result1Max, result2Max)) {
    num.f = result1Max;


  } else if (islessequal(result2Min, result1Min) && islessequal(result2Min, result1Max) && islessequal(result2Min, result2Max)) {
    num.f = result2Min;


  }else if (islessequal(result2Max, result1Min) && islessequal(result2Max, result1Max) && islessequal(result2Max, result2Min)) {
    num.f = result2Max;


  }else {
      if ((result1Min==result1Max) && (result2Min==result2Max)) {
        if (isgreater(result1Min, result2Max)){
          num.f = result1Min;
        }else{
          num.f = result2Max;
        }
      } else if ((result1Min==result2Min) && (result1Max==result2Max)) {
        if (isgreater(result1Min, result2Max)){
          num.f = result1Min;
        }else{
          num.f = result2Max;
        }
      }
    }
  return num;


}

Float_t calculateValueMaximum(Float_t num1Min,Float_t num1Max,Float_t num2Min,Float_t num2Max, int operation) {

  float result1Min,result1Max, result2Min,result2Max;
  Float_t num;

  result1Min = maximumVariable(calculateVariable(num1Min,num2Min, operation));
  result1Max = maximumVariable(calculateVariable(num1Min,num2Max, operation));
  result2Min = maximumVariable(calculateVariable(num1Max,num2Min, operation));
  result2Max = maximumVariable(calculateVariable(num1Max,num2Max, operation));

    if (isgreaterequal(result1Min, result1Max) && isgreaterequal(result1Min, result2Min) && isgreaterequal(result1Min, result2Max)) {
      num.f = result1Min;
    } else if (isgreaterequal(result1Max, result1Min) && isgreaterequal(result1Max, result2Min) && isgreaterequal(result1Max, result2Max)) {
      num.f = result1Max;
    } else if (isgreaterequal(result2Min, result1Min) && isgreaterequal(result2Min, result1Max) && isgreaterequal(result2Min, result2Max)) {
      num.f = result2Min;
    }else if (isgreaterequal(result2Max, result1Min) && isgreaterequal(result2Max, result1Max) && isgreaterequal(result2Max, result2Min)) {
      num.f = result2Max;
    }else {
        if ((result1Min==result1Max) && (result2Min==result2Max)) {
          if (isgreater(result1Min, result2Max)){
            num.f = result1Min;
          }else{
            num.f = result2Max;
          }
        } else if ((result1Min==result2Min) && (result1Max==result2Max)) {
          if (isgreater(result1Min, result2Max)){
            num.f = result1Min;
          }else{
            num.f = result2Max;
          }
        }
      }


  return num;
}


Float_t calculateVariable(Float_t var1, Float_t var2, int operation) {
  bool flow = false;
  Float_t num;

  switch (operation) {
    case 1:
      num.f = var1.f + var2.f;
      return num;
    case 2:
      num.f = var1.f - var2.f;
      return num;
    case 3:
      num.f = var1.f /var2.f;
      return num;

    case 4:

      num.f = var1.f * var2.f;
      return num;
  }

}

float findVariableMin(char* var, range* variableRange) {
  Float_t n;
  do {
    if (!strcmp(var, variableRange-> name)) {
      n.f = variableRange-> min;
      return n.f;
    }
    variableRange= variableRange-> next;
  } while(variableRange-> next != NULL);

  return 0;
}

float findVariableMax(char* var, range* variableRange) {
  Float_t n;
  do {
    if (!strcmp(var, variableRange-> name)) {
      n.f = variableRange-> max;

      return n.f;
    }
    variableRange= variableRange-> next;
  } while(variableRange-> next != NULL);

  return 0;
}

int findOperation(char* symbol) {

  if (!strcmp(symbol, "+")) {
    return 1;
  } else if (!strcmp(symbol, "-")) {
    return 2;
  } else if (!strcmp(symbol, "/")) {
    return 3;
  } else if (!strcmp(symbol, "*")) {
    return 4;
  } else {
    return 0;
  }

}

void createNode(variable* variableList, range* variableRange, int variableNumber) {
  for (int i = 1; i <= variableNumber; i++) {
    variable *nextList = (variable*)malloc(sizeof(variable));
    range* nextRange = (range*)malloc(sizeof(range));
    nextList -> number = i+1;
    nextRange -> number = i+1;

    variableList-> next = nextList;
    variableRange-> next = nextRange;
    variableList = variableList -> next;
    variableRange = variableRange -> next;
  }
  variableList-> next = NULL;
  variableRange-> next = NULL;
}

void printNode(variable* variableList, range* variableRange,  int variableNumber, int m) {

    printList(variableRange, variableNumber);

    checkRange(variableRange, m);

}
void checkInf(Float_t num) {
  int exp, man;
  bool expOne, manOne, manZero;


  if (num.parts.exponent - 127 == 127) {
    if ( num.parts.mantissa == 8388607) {
      if (num.parts.sign == 1) {
        printf(" -inf");
      } else {
        printf("  inf");
      }
    } else {
      if (num.parts.sign == 1) {
        printf(" -Nan");
      } else {
        printf("  Nan");
      }
    }
  }else {
      printf(" %1.8e",num.f );
    }


}

void printList(range* variableRange, int variableNumber) {
  Float_t num1, num2;
  for (int i = 0; i < variableNumber; i++) {
    num1.f = variableRange->min;
    num2.f = variableRange->max;
    printf("%s = [", variableRange -> name);
    printRange(num1, num2);
    variableRange = variableRange -> next;
  }
}

void printRange(Float_t num1, Float_t num2) {

  if (num1.parts.exponent - 127 == 127 && num1.parts.mantissa == 8388607 && num1.parts.sign == 1) {
    printf("-inf");
  } else if (num1.parts.exponent - 127 == 127 && num1.parts.mantissa == 8388607 && num1.parts.sign == 0) {
    printf(" %1.8e", num1.f);
  }else if (num2.parts.exponent - 127 == 127 && num2.parts.mantissa == 8388607 && num2.parts.sign == 0) {
    printf("inf");
  } else if (num2.parts.exponent - 127 == 127 && num2.parts.mantissa == 8388607 && num2.parts.sign == 1) {
    printf(" %1.8e", num1.f);
  }else
    checkInf(num1);
  printf(",");
  checkInf(num2);
  printf("]\n");
}


void checkRange(range* variableRange, int m) {
  Float_t num1, num2;
  bool text = false;

  printf("\nNão unitários:\n");
  do {
    num1.f = variableRange->min;
    num2.f = variableRange->max;
    if ((abs(num1.i - num2.i) - 1 > 2) ||
     ((num1.parts.sign != num2.parts.sign && variableRange-> number > m )) ||
     (variableRange-> number > m && islessequal(num1.f,num2.f))) {
       printf("%s = [", variableRange -> name);
       printRange(num1, num2);
    }
    variableRange = variableRange -> next;
  } while(variableRange-> next != NULL);
}
