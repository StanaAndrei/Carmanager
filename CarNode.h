#ifndef __CARNODE_H
#define __CARNODE_H

#include "Car.h"

typedef struct CarNode {
  Car car;
  struct CarNode *prev, *next;
} CarNode;

CarNode *newCarNode(const Car *const car);
void swapNodesData(CarNode *node1, CarNode *node2);

#endif
