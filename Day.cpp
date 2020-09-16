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
        countArmyDay();
        break;
      } 
      case 3: //만나이계산
      {
        countAge();
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
  year = 0;
  month = 0;
  day = 0;
  year += (str[0] - '0') * 1000;
  year += (str[1] - '0') * 100;
  year += (str[2] - '0') * 10;
  year += (str[3] - '0');
  month += (str[4] - '0') * 10;
  month += (str[5] - '0');
  day += (str[6] - '0') * 10;
  day += (str[7] - '0');
}

void countAge()
{
  cout <<"만나이 계산기입니다.\n";
  char standardDay[9]; // 기준일을 입력받을 char 배열
  cout << "날짜계산은 기준일을 1일로 포함하여 계산됩니다.\n";
  cout<< "기준일을 입력해주세요. 예)20200912: \n";
  cin >> standardDay;
  int year, month, day; // 기준 년 월 일
  converToValidValue(standardDay, year, month, day); 
  int bornY, bornM, bornD; // 생일
  char tmp[9]; // 생일 입력받을 임시배열
  cout <<"생일을 입력해주세요: 예)19990928 \n";
  cin >> tmp;
  converToValidValue(tmp, bornY, bornM, bornD);
  int age = year- bornY;
  if(month * 100 + day < bornM * 100 + bornD) //생일 안 지난경우
  {
    age--;
  }
  printf("만나이는 %d세 입니다.\n", age);
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
  cout <<"복무형태는 육군기준입니다. (제작자가 육군입니다.)\n";
  int tmpY = month + 8 > 12 ? year + 2 : year + 1;
  int tmpM = month + 8 > 12 ? (month + 8) % 12 : month + 8; 
  int tmp = countDay_X2(year, month, day);
  printf("기존 복무기간은 %d일로 기존 전역일은 %d년 %d월 %d일입니다.\n",tmp,tmpY, tmpM, day);
  int x = countDay_X3(year, month, day);
  tmp -= (1 + (x / 14));
  printf("총 %d일 줄어서 줄어든 복무기간은 %d일 입니다.\n", 1 + x/14, tmp);
  countDay_N2(year, month, day, tmp);
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

void countDay_N2(int year, int month, int day, int N)
{
  int n = N;
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
  printf("전역일은 %d년 %d월 %d일입니다.\n", y, m, d);
}




void countDay_D(int year, int month, int day)
{
  cout << "기준일로부터 D-xx일 되는 날을 계산합니다.\n";
  printf("기준일은 %d년 %d월 %d일이며, 오늘은 기준일로부터 1일째 되는날입니다.\n", year, month, day);
  cout <<"x를 입력해주세요:";
  int n;
  cin >> n;
  int copyN = n; // n의 복사본
  int y = year; // 각각 year, month, day의 복사본
  int m = month;
  int d = day;
  while(n > 0)
  {
    if(d > n) // 이번달안에 있는경우
    {
      d -= n;
      break;
    } else //이전달으로 넘어가야하는경우.
    {
      n -= d;
      m--;
      if(m == 0)
      {
        m = 12;
        y--;
      }
      if(isLeapYear(y) && m == 2)
      {
        d = 29;
      } else 
      {
        d = dayByMonth[m - 1];
      }
    }
  }
  printf("기준일 %d년 %d월 %d일로부터 D-%d일째 되는 날은 %d년 %d월 %d일입니다.\n", year, month, day, copyN, y, m, d);
}

void countDay_X(int year, int month, int day)
{
  int rYear, rMonth, rDay; // 목표하는 년 월 일
  cout << "기준일로부터 xxxx년 x월 x일은 몇일인지 출력합니다.\n";
  printf("기준일은 %d년 %d월 %d일이며, 오늘은 기준일로부터 1일째 되는날입니다.\n", year, month, day);
  cout <<"몇년 몇월 몇일인지 입력해주세요 예) 20201215\n";
  char str[9];
  cin >> str;
  converToValidValue(str, rYear, rMonth, rDay);
  int y = year;
  int m = month;
  int d = day;
  int count = 0; 
  while(rYear > y) // 연도 먼저 맞추고
  {
    int tmp = 365;
    if(y + 1 == rYear) // 1년 차이날때
    {
      for(int i = 0; i < m - 1; i++)
      {
        tmp -= dayByMonth[i];
      }
      if(isLeapYear(year) && m == 2) // 윤년은 366일이니깐 2월달은 따로 봐줘야해!
      {
        tmp++;
      }
      // m이 2월달보다 클때는 366 - 29 나 365 - 28 이나 같으니깐 따로 할필요 없음 ㅎ
      tmp -= d;
      m = 1;
      d = 1;
      // 이제 연도는 같아질거니깐 1월 1일로 맞춰줘야함. 
    } else //2년 이상 차이날떄는 그냥 365일 더해주면 됨. 
    {
      if(isLeapYear(y))
      {
        tmp++;
      }
    }
    count += tmp;
    y++;
  }
  count += (dayByMonth[m - 1] - d + 1);
  if(isLeapYear(y) && m == 2)
  {
    count++;
  }
  while(rMonth - 1 > m)
  {
    count += dayByMonth[m - 1];
    if(isLeapYear(y) && m == 2)
    {
      count++;
    }
    m++;
  }
  count += rDay;
  printf("기준일로부터 %d년 %d월 %d일까지는 %d일째 입니다. \n", rYear, rMonth, rDay, count);
}


int countDay_X2(int year, int month, int day)
{
  int y = year;
  int m = month;
  int d = day;
  int day_count = 0;
  int month_count = 0; // 21이 되어야함. 
  day_count += (dayByMonth[m - 1] - d);
  if(isLeapYear(y) && m == 2)
  {
    day_count++;
  }
  m++;
  d = 1;
  month_count++;
  while(month_count < 20)
  {
    if(m > 12)
    {
      m %= 12;
      y++;
    }
    day_count+= dayByMonth[m - 1];
    if(isLeapYear(y) && m == 2)
    {
      day_count++;
    }
    m++;
    month_count++;
  }
  day_count += day;
  return day_count;
}

int countDay_X3(int rYear, int rMonth, int rDay)
{
  int y = 2017;
  int m = 1;
  int d = 3;
  int count = 0; 
  while(rYear > y) // 연도 먼저 맞추고
  {
    int tmp = 365;
    if(y + 1 == rYear) // 1년 차이날때
    {
      for(int i = 0; i < m - 1; i++)
      {
        tmp -= dayByMonth[i];
      }
      if(isLeapYear(y) && m == 2) // 윤년은 366일이니깐 2월달은 따로 봐줘야해!
      {
        tmp++;
      }
      // m이 2월달보다 클때는 366 - 29 나 365 - 28 이나 같으니깐 따로 할필요 없음 ㅎ
      tmp -= d;
      m = 1;
      d = 1;
      // 이제 연도는 같아질거니깐 1월 1일로 맞춰줘야함. 
    } else //2년 이상 차이날떄는 그냥 365일 더해주면 됨. 
    {
      if(isLeapYear(y))
      {
        tmp++;
      }
    }
    count += tmp;
    y++;
  }
  //count += (dayByMonth[m - 1] - d + 1);
  if(isLeapYear(y) && m == 2)
  {
    count++;
  }
  while(rMonth - 1 > m)
  {
    count += dayByMonth[m - 1];
    if(isLeapYear(y) && m == 2)
    {
      count++;
    }
    m++;
  }
  count += rDay;
  return count;
}
/* 1900년 1월 1일이 월요일인게 팩트
윤년계산법
1. 4의 배수년은 윤년이다.
2. 근데 100의 배수는 윤년아니다.
3. 근데 400의 배수는 윤년이다.
윤년이면 2월이 29일까지 있음. 1년이 366일이야.

*/
