#include<iostream>
#include<algorithm>
using namespace std;
int mylist[110];
int n,m;
bool cmp(int a, int b)
{
	return a>b;
}
int main()
{
	cin>>n>>m;
	cin>>mylist[1];
	int t=mylist[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>mylist[i];
	}
	sort(mylist+1,mylist+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(mylist[i]==t)
		{
			int temp=i/n;
			int Temp=i%n;
			if(Temp==0)
			{
				int now=temp%2;
				switch(now){
					case 0:
						cout<<temp<<" "<<1;
						break;
					case 1:
						cout<<temp<<" "<<m;
						break;
				}
			} else {
				int now=(temp+1)%2;
				switch(now){
					case 0:
						cout<<temp+1<<" "<<m-Temp+1;
						break;
					case 1:
						cout<<temp+1<<" "<<Temp;
						break;
				}
			}
			break;
		}
	}
	return 0;
} 
