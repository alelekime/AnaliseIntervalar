#include "header.h"


int main(int argc, char const *argv[]) {
  int m, n;
  variable *variableList = (variable*)malloc(sizeof(variable));
  range* variableRange = (range*)malloc(sizeof(range));
  scanf("%d%d\n", &m,&n);

  createNode(variableList, variableRange, m+n);
  fillVariable(variableList, variableRange, m);

  fillRange(variableList, variableRange, m,n);
  printNode(variableList, variableRange, m+n, m);

  return 0;
}
