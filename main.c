#include <stdio.h>
#include <stdlib.h>
#include "Car.h"
#include "CarList.h"
#include "CarNode.h"
#define EVER ;;

void printMenu() {
  puts("1.Add");
  puts("2.Delete");
  puts("3.Print all");
  puts("4.Print by seats");
  puts("5.Sort by year");
  puts("6.Exit");
  printf(">> ");
}

int main(void) {
  CarList carList;
  initCarList(&carList);

  {//push cars for test
    Car c1 = {(unsigned)1, (unsigned char)5, (unsigned)300, (unsigned)2000, "blue", "bmw"};
    Car c2 = {(unsigned)2, (unsigned char)4, (unsigned)300, (unsigned)2010, "black", "dacia"};
    Car c3 = {(unsigned)3, (unsigned char)1, (unsigned)300, (unsigned)2006, "yellow", "renault"};
    addToStartOfCarList(&carList, newCarNode(&c3));
    addToStartOfCarList(&carList, newCarNode(&c2));
    addToStartOfCarList(&carList, newCarNode(&c1));
  }

  
  for (EVER) {
    printMenu();
    short opt;
    scanf("%hd", &opt);
    switch (opt) {
    case 1:
      {
	Car car;
	readCar(&car);
	addToStartOfCarList(&carList, newCarNode(&car));
      }
      break;
    case 2:
      {
	unsigned code;
	printf("code: ");
	scanf("%u", &code);
	delByCodeFromCarList(&carList, code);
      }
      break;
    case 3:
      printCarList(&carList);
      break;
    case 4:
      {
	unsigned seats;
	printf("seats: ");
	scanf("%u", &seats);
	printCarListIfMatchSeats(&carList, seats);
      }
      break;
    case 5:
      sortCarListByYear(&carList);
      printCarList(&carList);
      break;
    case 6:
      freeCarList(&carList);
      exit(EXIT_SUCCESS);
    default:
      puts("Invalid option!");
    }
    puts("");
  }
  return 0;
}
