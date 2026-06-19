#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
int d[1002];
int v[1002];
int a[1002];
int main()
{
 	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++)
	{
	cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		if(n%2==0)
		{
			cout<<n/2+1<<n/2+1<<endl;
		}
		else
		{
			cout<<(n+1)/2<<(n+1)/2<<endl;
		}
	}
	return 0;
}
