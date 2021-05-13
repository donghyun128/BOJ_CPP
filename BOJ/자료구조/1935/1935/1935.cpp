// 1935.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<double> st[27];


int main()
{
    int n;
    string str;
    double val[27];
    cin >> n;
    cin >> str;

    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < str.size(); i++)
    {
        double a;
        double b;

        if ('A' <= str[i] && str[i] <= 'Z')
        {
            st->push(val[str[i] - 'A']);  // 모자랐던 것: 아스키 코드에 맞춰 숫자 배열 인덱싱 하기. 굳이 char 배열과 double 배열을 같이 만들 필요가 없었다!
        }
        else {
            b = st->top();
            st->pop();
            a = st->top();
            st->pop();
            switch (str[i])
            {
            case '+':
                st->push(a + b); break;
            case '-':
                st->push(a - b); break;
            case '*':
                st->push(a * b); break;
            case '/':
                st->push(a / b); break;
            }
        }

    }
    printf("%.2f", st->top());

}

