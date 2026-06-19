#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n,m,k;
const int MaxN = 1e4+10;
int w[MaxN][MaxN];
int c[MaxN];
int a[MaxN][MaxN];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	memset(w,0x3f,sizeof(w));
	for(int i = 1; i <= n; i++)
	{
		int arg1,arg2,arg3;
		scanf("%d%d%d",&arg1,&arg2,&arg3);
		w[arg1][arg2] = arg3;
		w[arg2][arg1] = arg3;
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= )
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
