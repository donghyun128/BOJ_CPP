#include <iostream>
#include <queue>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	
	queue<int> q;
	string s;
	char c[100001];
	int input;
	scanf("%d",&input);
	
	for (int i =1; i<= input; i++)
	{
		scanf("%s",c);
		s = c;
		if (s == "push")
		{
			int n;
			scanf("%d",&n);
			q.push(n);
		}
		
		else if (s == "pop")
		{
			if(!q.empty())
			{
				printf("%d\n",q.front());
				q.pop();
			}
			else printf("-1\n");
		}
		
		else if (s == "size")
		{
			printf("%d\n",q.size());
		}
		
		else if (s == "empty")
		{
			if (q.empty()) printf("1\n");
			else printf("0\n");
		}
		
		else if (s == "front")
		{
			if (!q.empty()) printf("%d\n",q.front());
			else printf("-1\n");
		}
		
		else if (s == "back")
		{
			if (!q.empty()) printf("%d\n",q.back());
			else printf("-1\n");
		}
	}
	
	return 0;
}
