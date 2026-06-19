#include<bits/stdc++.h>
using namespace std;
int a[101]={};
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
    cin>>m>>n;
    for(int i=1;i<=m*n;i++)
    {
    	cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+m*n+1,cmp);
	int num=0;
	for(int i=1;i<=m*n;i++)
	{
		if(cnt==a[i]) num=i;
		
	}
	int h=0;
	if(num%m==0) h=num/m;
	else h=num/m+1;
	if(h%2)
	{
		cout<<h<<" "<<num-n*(h-1);
	}
	else if(h%2==1)
	{
		cout<<h<<" "<<m-(num-n*(h-1))+1;
	}
	return 0;
}
