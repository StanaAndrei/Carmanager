#include "CarNode.h"
#include <stdlib.h>
#include <stdio.h>

CarNode *newCarNode(const Car *const car) {
  CarNode *carNode = (CarNode*)malloc(sizeof(CarNode));
  if (carNode == NULL) {
    perror("");
    exit(EXIT_FAILURE);
  }
  carNode->car = *car;
  carNode->prev = carNode->next = NULL;
  return carNode;
}
