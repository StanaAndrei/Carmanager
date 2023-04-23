#ifndef __CAR_H
#define __CAR_H

#include <stdbool.h>

#define MAX_COL 100
#define MAX_MODEL 100

typedef struct {
  unsigned code: 14;
  unsigned seats: 4;
  unsigned power: 9;
  unsigned year: 11;
  char color[MAX_COL], model[MAX_MODEL];
} Car;

bool readCar(Car *car);
void printCar(const Car *const car);

#endif
