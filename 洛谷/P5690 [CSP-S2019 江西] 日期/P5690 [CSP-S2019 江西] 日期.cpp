#include<bits/stdc++.h>
using namespace std;
int ans=0,m,d;
char just_eat;
bool flag=0;
int month[20]={31,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>m>>just_eat>>d; 
	if(m==2&&d==29)
	{
		cout<<1;
		return 0;
	}
	if(d>31)
	{
		flag=1;
		ans++;
	}
	if(m>12||m==0)ans++;
	if(d>month[m%10]&&d>month[m%10+10]&&flag==0)ans++;
	cout<<ans;
	return 0;
}