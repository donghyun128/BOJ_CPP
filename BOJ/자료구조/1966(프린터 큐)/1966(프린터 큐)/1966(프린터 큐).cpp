// 1966(프린터 큐).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp()
{}


int main()
{
    priority_queue<pair<int,int>> pq;
    int t_num;
    int d_num, dest;
    

    cin >> t_num;
    for (int i = 0; i < t_num; i++)
    {
        cin >> d_num >> dest;
        for (int i = 0; i < d_num; i++)
        {
            int tmp;
            cin >> tmp;
            pq.push({ tmp,i }); // tmp: 중요도 , i : index
       }
        int result = 0;
        while (!pq.empty())
        {
            result++;
            if (pq.top().second == dest)
            {
                cout << result << endl;
            }
            pq.pop();
        }

    }
    return 0;
}

