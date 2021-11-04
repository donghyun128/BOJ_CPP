#include <iostream>
using namespace std;

long long int recur_multiply(int n, int count, int mod)
{
	if (count == 0)
		return 1;
	long long int half;
	half = recur_multiply(n, count / 2, mod);
	half = half * half % mod;
	if (count % 2 == 0)
		return half;
	else
		return half * n % mod;
}

int main()
{
	long long int a, b, c;
	cin >> a >> b >> c;
	cout << recur_multiply(a, b, c);

}