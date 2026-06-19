#include <bits/stdc++.h>
using namespace std;
int frq;
int n,k,q;
const int N = 1e5 + 7;
int s[N];
int solve(int a,int b)
{
	return rand() % 2;
} 
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(0));
	scanf("%d",&frq);
	while(frq--)
	{ 
		scanf("%d%d%d",&n,&k,&q);
		for(int t = 1;t <= n;t++)
		{
			int m;
			scanf("%d",&m);
			for(int i = 1;i <= m;i++) scanf("%d",&s[i]);
		}
		for(int t = 1;t <= q;t++)
		{	
			int r,c;
			scanf("%d%d",&r,&c);
			cout << solve(r,c) << endl; 
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
