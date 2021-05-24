// 15815 (천재 수학자 성필).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<int> s;

int main()
{
    string np;
    int result = 0;
    cin >> np;

    for (int i = 0; i < np.size(); i++)
    {
        if (np[i] >= '0' && np[i] <= '9')
        {
            int tmp = np[i] - '0';
            s.push(tmp);
        }

        else
        {
            int op1, op2;
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            if (np[i] == '+')
            {
                result = op1 + op2;
            }

            else if (np[i] == '-')
            {

                result = op1 - op2;
            }

            else if (np[i] == '*')
            {

                result = (op1 * op2);

            }
            else if (np[i] == '/')
            {

                result = (op1 / op2);

            }
            s.push(result);
        }
    }
    printf("%d", result);
}

