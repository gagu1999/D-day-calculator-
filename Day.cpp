#include "Day.h"

int dayByMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


void showMenu()
{
  int tmp;
  while(1)
  {
    cout <<"안녕하세요, 디데이계산기입니다. 원하시는 동작을 선택해주세요\n";
    cout << "1.날짜계산\n";
    cout << "2.전역일계산\n";
    cout << "3.만나이계산\n";
    cout << "4.프로그램 종료\n";
    cout << "번호입력:";
    cin >> tmp;
    while(tmp < 1 || tmp > 4)
    {
      cout <<"잘못된 입력입니다. 수를 다시 입력해주세요:";
      cin >> tmp;
    }
    switch(tmp)
    {
      case 1: //날짜계산
      {
        countDay();
        break;
      }
      case 2: //전역일계산
      {
        //countArmyDay();
        break;
      } 
      case 3: //만나이계산
      {
        //countAge();
        break;
      }
      default: // 프로그램 종료
      {
        cout <<"프로그램을 종료합니다.\n";
        cout <<"다음에 또 방문해주세요~\n";
        return;
      }
    }
  }
}

void countDay() //기준일로부터 다양한 날들까지의 날짜를 세는 함수
{
  //2020 09 12 9칸 배열을 만들어야하네 ㅋㅋ 
  char standardDay[9]; // 기준일을 입력받을 char 배열
  cout << "날짜계산은 기준일을 1일로 포함하여 계산됩니다.";
  cout<< "기준일을 입력해주세요. 예)20200912: ";
  cin >> standardDay;
  int year, month, day;
  year = month = day = 0;
  converToValidValue(standardDay, year, month, day); //입력받은 char 배열을 각각 int로 쪼개기
  /*
  여기서 해야할것.
  각 년도, 월 별로 29, 30, 31로 최대일수가 달라짐. 그래서 숫자는 잘 들어왔지만, 이것처럼
  유효하지 않은 값이 들어온경우도 다시 처리할수 있도록 디버그해줘야해!
  */

  int tmp; // 동작선택을 위한 임시변수
  cout << "원하시는 동작을 선택해주세요.\n";
  cout << "1.기준일로부터 n일째 되는날은??\n";
  cout << "2.기준일로부터 D-x 일은??\n";
  cout << "3.기준일로부터 xxxx.xx.xx까지는 며칠째??\n";
  cin >> tmp;
  while(tmp < 1 || tmp > 3)
  {
    cout <<"잘못된 입력입니다. 다시 입력해주세요:";
    cin >> tmp;
  }
  switch(tmp)
  {
    case 1:
    {
      countDay_N(year, month, day); // n일쨰 되는날 구하기
      break;
    }
    case 2:
    {
      countDay_D(year, month, day); // D-x일 구하기
      break;
    }
    default:
    {
      countDay_X(year, month, day); // xxxx.xx.xx까지는 며칠째인지 구하기
      break;
    }
  }
}

 //입력받은 char 배열을 각각 int로 쪼개서 연, 월 , 일에 넣어주는 함수
void converToValidValue(char * str, int& year, int& month, int& day)
{
  year += (str[0] - '0') * 1000;
  year += (str[1] - '0') * 100;
  year += (str[2] - '0') * 10;
  year += (str[3] - '0');
  month += (str[4] - '0') * 10;
  month += (str[5] - '0');
  day += (str[6] - '0') * 10;
  day += (str[7] - '0');
}

void countArmyDay()
{
  char standardDay[9];
  cout <<"전역일 계산기입니다.\n";
  cout <<"입대일을 입력해주세요. 예)20200309: ";
  cin >> standardDay;
  int year, month, day;
  year = month = day = 0;
  converToValidValue(standardDay, year, month, day);
  cout <<"복무형태는 육군기준입니다.\n";
  /*이게 정확한 기준이 나와있는 곳 없이 그냥 2주에 1일씩 줄어든다고만 나와서
  고냥 18개월로 계산하려고 합니다.*/
}

bool isLeapYear(int year)
{
  if(year % 4 != 0)
  {
    return false; // 윤년아님
  } else 
  {
    if(year % 100 == 0 && year % 400 != 0) //윤년아님
    {
      return false;
    }
    return true; // 윤년임.
  }
}
void countDay_N(int year, int month, int day)
{
  cout << "기준일로부터 n일째 되는날을 계산합니다.\n";
  printf("기준일은 %d년 %d월 %d일이며, 오늘은 기준일로부터 1일째 되는날입니다.\n", year, month, day);
  cout <<"n을 입력해주세요: ";
  int n;
  cin >> n;
  int copyN = n;
  int y = year;
  int m = month;
  int d = day;
  while(n > 1)
  {
    int tmp;
    if(m == 2 && isLeapYear(y)) // 윤년이라 2월이 29일까지 있을때
    {
      tmp = 29 - d + 1;
    } else 
    {
      tmp = dayByMonth[m - 1] - d + 1; // 이번달 마지막날까지 남은 날!
    }
    if(n > tmp)
    {
      n -= tmp;
      m++; // 다음달로 넘어가기
      if(m > 12) // 다음년으로 넘어가야하는 경우.
      {
        m = 1;
        y++;
      }
      d = 1;
    } else // n < tmp이므로 이제 끝났음.
    {
      d += (n - 1);
      break;
    }
  }
  printf("기준일 %d년 %d월 %d일로부터 %d일째 되는 날은 %d년 %d월 %d일입니다.\n", year, month, day, copyN, y, m, d);
}

void countDay_D(int year, int month, int day)
{

}

void countDay_X(int year, int month, int day)
{

}

/* 1900년 1월 1일이 월요일인게 팩트
윤년계산법
1. 4의 배수년은 윤년이다.
2. 근데 100의 배수는 윤년아니다.
3. 근데 400의 배수는 윤년이다.
윤년이면 2월이 29일까지 있음. 1년이 366일이야.

*/
