#include<bits/stdc++.h>
using namespace std;
int T;
int needsticks[]={6,2,5,5,4,5,6,3,7,6};
int result[51];
int digitnum(int x)
{
	return (int)to_string(x).length();
}
int digit(int x,int n)
{
	return to_string(x)[digitnum(x)-n]-48;
}
int f(int x)
{
	int y=0;
	for(int i=1;i<=digitnum(x);i+=1)
	{
		y+=needsticks[digit(x,i)];
	}
	return y;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i+=1)
	{
		int n;
		cin>>n;
		result[i]=-1;
		for(int j=1;j<=(int)pow(10,n/2);j+=1)
		{
			if(f(j)==n)
			{
				result[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=T;i+=1)
	{
		cout<<result[i]<<'\n';
	}
	return 0;
}
