#ifndef __CARLIST_H
#define __CARLIST_H

#include "CarNode.h"

typedef struct {
  CarNode *first;
  CarNode *last;
} CarList;

void initCarList(CarList *carList);
void addToStartOfCarList(CarList *carList, CarNode *carNode);
void delByCodeFromCarList(CarList *carList, unsigned code);
void printCarList(const CarList *const carList);
void printCarListIfMatchSeats(const CarList *const carList, unsigned seats);
void sortCarListByYear(CarList *carList);
void freeCarList(CarList *carList);

#endif
