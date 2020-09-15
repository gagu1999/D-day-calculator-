#ifndef DAY_H
#define DAY_H


#include <iostream>
using namespace std;

void showMenu(); // 디데이 계산기 메뉴를 출력하는 함수.

void converToValidValue(char * str, int & year, int & month, int & day);
//입력받은 char 배열을 각각 int로 쪼개서 연, 월 , 일에 넣어주는 함수
void countDay_N(int year, int month, int day); // 기준일로부터 n일째 되는 날 구하는 함수
void countDay_D(int year, int month, int day); // 기준일로부터 D-x일 되는 날 구하는 함수
void countDay_X(int year, int month, int day); // 기준일로부터 xxxx.xx.xx까지 며칠인지 구하는 함수.
bool isLeapYear(int year); // 윤년인지 아닌지 구하는 함수
#endif