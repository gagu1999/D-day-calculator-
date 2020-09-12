#include "Day.h"

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
  char standardDay[9];
  cout << "날짜계산은 기준일을 1일로 포함하여 계산됩니다."
  cout<< "기준일을 입력해주세요. 예)20200912: ";
  cin >> standardDay;
  int year, month, day;
  year = month = day = 0;
  converToValidValue(standardDay, year, month, day);
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
  swtich(tmp)
  {
    case 1:
    {
      break;
    }
    case 2:
    {
      break;
    }
    default:
    {
      break;
    }
  }

}


void converToValidValue(char * str, int& year, int& month, int& day)
{
  for(int i = 0; i < 4; i++)
  {
    year += str[i] - '0';
  }
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
  고냥 18개월로 계산하려고합니다.*/
}