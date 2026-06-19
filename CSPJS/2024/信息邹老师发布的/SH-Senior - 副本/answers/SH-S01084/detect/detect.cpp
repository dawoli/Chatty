#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V;
struct cars{
	int d,v,a;
}car[14];
int p[14];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&L,&V);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d%d",&car[i].d,&car[i].v,&car[i].a);		
	}
	for(int i = 0; i < m; i++)
	{
		scanf("%d",&p[14]);
	}
	 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
