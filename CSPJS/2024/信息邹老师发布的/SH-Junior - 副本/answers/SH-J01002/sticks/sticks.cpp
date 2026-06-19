#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int stick20(int n)
{
	if(n==1) return -1;
	if(n==2) return 1;
	if(n==3) return 7;
	if(n==4) return 4;
	if(n==5) return 2;
	if(n==6) return 6;
	if(n==9) return 18;
	if(n==10) return 22;
	if(n==11) return 20;
	if(n==12) return 28;
	if(n==13) return 68;
	if(n==16) return 188;
	if(n==17) return 228;
	if(n==18) return 208;
	if(n==19) return 288;
	if(n==20) return 688;
}

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int abc=1;abc<=t;abc++)
	{
		int n;
		cin>>n;
		int wei=ceil(n/7.0);
		if(n%7==0)
		{
			for(int i=1;i<=wei;i++)
			{
				cout<<"8";
			}
		}
		else if((n-1)%7==0 && n!=1)
		{
			cout<<"10";
			for(int i=3;i<=wei;i++)
			{
				cout<<"8";
			}
		}
		else if(n<=20)
		{
			cout<<stick20(n);
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
