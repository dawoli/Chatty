#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
long long mp[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long r=0;
	cin>>r;
	for(int i=1;i<=n*m-1;i++) 
	{
		cin>>mp[i];
	}
	sort(mp+1,mp+n*m-1,cmp);
	mp[0]=0x3f3f3f3f;
	int idx;
	for(int i=1;i<=n*m-1;i++) 
	{
		if(mp[i-1]>r&&mp[i]<r)
		{
			idx=i;
			break;
		}
	}
	int x,y;
	y=(idx-1)/n;//µÚ¼¸ÁÐ 
	if(y%2==0)
	{
		x=(idx-1)%n+1;
	}
	else
	{
		x=n-idx%n+1;
	}
	cout<<y+1<<" "<<x<<endl;
	return 0;
} 
