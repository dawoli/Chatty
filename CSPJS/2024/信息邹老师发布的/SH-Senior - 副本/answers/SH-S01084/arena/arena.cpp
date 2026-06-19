#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int n,m,K;
int a_[1000000];
int c[1000000];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",n,m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a_);
	}
	for(int i = 0; i < m; i++)
	{
		scanf("%d",&c);
	}
	for(K = 1; K < n/2; K++)
	{
		if(pow(2,K)>=n)
		break;
	}
	cout << K << endl;
	fclose(stdout);
	fclose(stdin);
}
