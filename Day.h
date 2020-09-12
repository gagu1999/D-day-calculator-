#ifndef DAY_H
#define DAY_H


#include <iostream>
using namespace std;

void showMenu(); // 디데이계산기 메뉴를 출력하는 함수.
void countDay();
void countArmyDay();
void countAge();
void converToValidValue(char * str, int & year, int & month, int & day);
#endif