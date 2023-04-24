#include "Car.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool readCar(Car *car) {
  unsigned code, seats, power, year;
  bool ok = true;
  printf("code: ");
  ok &= scanf("%u", &code);
  printf("seats: ");
  ok &= scanf("%u", &seats);
  printf("power: ");
  ok &= scanf("%u", &power);
  printf("year: ");
  ok &= scanf("%u", &year);

  *car = (Car) {
    .code = code,
    .seats = seats,
    .power = power,
    .year = year
  };
  
  printf("color: ");
  getchar();
  ok &= (fgets(car->color, MAX_COL, stdin) != NULL);  
  printf("mark: ");
  ok &= (fgets(car->mark, MAX_MARK, stdin) != NULL);

  car->color[strlen(car->color) - 1] = 0;
  car->mark[strlen(car->mark) - 1] = 0;
  
  return ok;
}

void printCar(const Car *const car) {
  printf("{ ");
  printf("code: %u, ", car->code);
  printf("seats: %u, ", car->seats);
  printf("power: %u, ", car->power);
  printf("year: %u, ", car->year);
  printf("color: %s, ", car->color);
  printf("mark: %s", car->mark);
  printf(" }\n");
}
