#include <iostream>
#include <stdio.h>
#include <fstream>

#include <bits/stdc++.h>


using namespace std;

int n;
const int MaxN = 5000+100;
int a[MaxN];
long long ans;

bool check(int m, int sum)
{
	if(m<3)return false;
	return true;
}

void dfs()
{
	
}

bool comp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,comp);
//	for(int i = 1; i <= n; i++)
//	{
//		
//	}
	int x=a[1],y=a[2],z=a[3];
	if(n<=3)
	{
		if(x+y+z>2*max(x,max(y,z)))
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
