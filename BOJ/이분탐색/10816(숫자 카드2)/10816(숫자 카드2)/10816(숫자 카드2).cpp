#include <iostream>
#include <algorithm>

int card[500001];
int list[500001];

int binarySearch(int length,int k)
{
    int st, en, mid , result, index;
    st = 1; en = length; 
    result = 0;

    while (st <= en)
    {
        mid = (st + en) / 2;
        if (card[mid] < k)
        {
            st = mid + 1;

        }

        else if (card[mid] > k)
        {
            en = mid - 1;
        }
        else
        {
            result = 1;
            break;
        }
    }

    if (result != 0)
    {
        int i = 1;
        while (card[mid+i] == card[mid])
        {
            result++;
            i++;
        }
        i = 1;
        while (card[mid - i] == card[mid])
        {
            result++;
            i++;
        }
    }
    return result;
}

using namespace std;
int main()
{
    
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> card[i];
    }

    sort(card+1, card + n+1,less<int>());

    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> list[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int result = upper_bound(card + 1, card + n + 1, list[i]) - lower_bound(card + 1, card + n + 1, list[i]);
        printf("%d ", result);
    }

 
}

