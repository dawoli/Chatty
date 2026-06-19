#include<bits/stdc++.h>
using namespace std;
int n,m,day;
int y,no;
int temp;
int pat[50000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>day;
	while(day!=0)
	{
		temp=day%10;
		if(temp==1) y++;
		else no++;
		day/=10;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>pat[i];
	}
	sort(pat+1,pat+n);
	return 0;
 } 
