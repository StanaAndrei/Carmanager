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

void swapNodesData(CarNode *node1, CarNode *node2) {
  Car aux = node1->car;
  node1->car = node2->car;
  node2->car = aux;
}
