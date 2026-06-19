#include<iostream> 
using namespace std;
void p(int num,int time)
{
	for(int i=1;i<=time;i++)
	{
		cout << num;
	} 
	cout << endl;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	int ans[31]={-1,-1,1,7,4,5,6,8,10,18,22,20,28,88,108,188,200,208,800,808,888,1088,1888,6000,6008,6088,6888,8888,10888,18888,60000}
	for(int i=1;i<=T;i++)
	{
		int n;
		cin >> n;
		if(n==1)
		{
			cout << "-1";	
			continue;
		}
		if(n<=20)
		{
			cout << ans[n];
			continue;
		}
		if(n%7==0)
		{	
			p(8,n/7);
			continue;
		}
		if(n%7==1&&n%6!=1)
		{
			cout << 10;
			p(8,(n-8)/7);
			continue;
		}
		if(n%7==2)
		{
			cout << 1;
			p(8,(n-2)/7);	
		}
		if(n%7==3)
		{
			cout << 6;
			p(0,n/6-1);
		}
		if(n%7==4)
		{
			cout << 6;
			p(0,n/6-2);
			p(8,1);
			continue;
		}
		if(n%7==5)
		{
			cout << 6;
			p(0,n/6-3);
			p(8,2);
			continue;
		}
		if(n%7==6)
		{
			cout << 6;
			p(8,(n-6)/7);
			continue;
		}
	}
}
