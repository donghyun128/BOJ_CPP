// 9012(스택).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st[50];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int en = 0;
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            
            if (s[j] == '(')
                st->push(s[j]);

            else if (s[j] == ')')
            {
                if (st->empty()) {
                    en = 1;
                }
                else st->pop();
            }

        }
        if (en == 1)
        {
            cout << "NO" << endl;
        }
        else if (!st->empty())
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        while (!st->empty()) // 처음에 알아차리지 못한 것. stack을 사용하고는 꼭 다시 비워주어야 한다!
            st->pop();
    }
}


