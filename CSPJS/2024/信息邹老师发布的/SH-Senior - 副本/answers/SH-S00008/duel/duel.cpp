#include <bits/stdc++.h>
using namespace std;
int n, res[101000], att[101000];
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &res[i]);
	}
	sort(res+1, res+1+n);
	for(int i = 1; i <= n; i ++)
	{
		att[i] = res[i];
	}
	int pos=1;
	for(int i = 1; i <= n; i++)
	{
		if(res[pos] < att[i]) pos++;
	}
	
	printf("%d", n-pos+1);
	return 0;
} 
