#include <bits/stdc++.h>
using namespace std;
int a[10][2];
int num(int n,int m)
{
	if(n<2)
	{
		return -1;
	}
	for(int j=6;j>=1;j--){
		int i=a[j][0],k=a[j][1];
		if(a[j][1]==6){
			k=0;
		}
		if(n-i>0){
			int sa=num(n-i,k);
			if(sa=-1)
			{
				continue;
			}
			return k*10+m;
		}
		if(n-i==0){
			if (k==0){
				k=6;
			}
			return k;
		}
		if(n-i<0){
			 
			continue;
		}
	} 
	return -1;
}
int main()
{
	freopen("stick.in","r",stdin)
	freopen("stick.out","w",stdout) 
	int T;
	cin>>T;
	a[1][0]=2;
	a[1][1]=1;
	a[2][0]=3;
	a[2][1]=7;
	a[3][0]=4;
	a[3][1]=4;
	a[4][0]=5;
	a[4][1]=2;
	a[5][0]=6;
	a[5][1]=6;
	a[6][0]=7;
	a[6][1]=8;
	for(int i=0;i<T;i++)
	{
		int n;
		cin>>n;
		cout<<num(n,0);
	}
	
	return 0;
}
