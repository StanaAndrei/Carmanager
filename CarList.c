#include "CarList.h"
#include "Car.h"
#include "CarNode.h"
#include <stddef.h>
#include <stdlib.h>

void initCarList(CarList *carList) {
  carList->first = carList->last = NULL;
}

void addToStartOfCarList(CarList *carList, CarNode *carNode) {
  if (carList->first != NULL) {
    carList->first->prev = carNode;
  }
  carNode->next = carList->first;
  carList->first = carNode;//*/
}

void printCarList(const CarList *const carList) {
  for (CarNode *it = carList->first; it; it = it->next) {
    printCar(&it->car);
  }
}

CarNode *findByCodeInCarList(CarList *carList, unsigned code) {
  for (CarNode *it = carList->first; it; it = it->next) {
    if (it->car.code == code) {
      return it;
    }
  }
  return NULL;
}

void delByCodeFromCarList(CarList *carList, unsigned code) {
  CarNode *target = findByCodeInCarList(carList, code);
  if (target == NULL) {
    return;
  }

  if (target->prev == NULL) {//is first
    carList->first = target->next;
  } else {
    target->prev->next = target->next;
  }

  if (target->next == NULL) {//is last
    carList->last = target->prev;
  } else {
    target->next->prev = target->prev;
  }
  
  free(target);
}

void freeCarList(CarList *carList) {
  CarNode *it = carList->first, *next = NULL;
  while (it) {
    next = it->next;
    free(it);
    it = next;
  }
}

void printCarListIfMatchSeats(const CarList *const carList, unsigned seats) {
  for (CarNode *it = carList->first; it; it = it->next) {
    if (it->car.seats == seats) {
      printCar(&it->car);
    }
  }
}
