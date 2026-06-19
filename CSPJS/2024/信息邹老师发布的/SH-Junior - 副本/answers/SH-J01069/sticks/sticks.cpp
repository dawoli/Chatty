#include <iostream>
#include <cstdio>
using namespace std;
int st[10] = {6,2,5,5,4,5,6,3,7,6};
const long long MAXN = 2e6;
int answer[51];
unsigned int now;
void dfs(int n,unsigned int num,int w)
{
	int cnt = num;
	if(n < 0)
		return;
	if(n == 0)
	{
		now = min(now,num);
		return;
	}
	for(int i = 0;i <= 9;i++)
	{ 
		num = cnt;
		if(w == 0 && i == 0)
			continue;
		num *= 10;
		num += i;
		dfs(n-st[i],num,w+1);
	}
	return;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 0;i < t;i++)
	{
		now = 1e5;
		int n;
		cin >> n;
		dfs(n,0,0);
		answer[i] = now;
		if(now == 1e5)
			answer[i] = -1;
	}
	for(int i = 0;i < t;i++)
		cout << answer[i] << endl;
		
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
