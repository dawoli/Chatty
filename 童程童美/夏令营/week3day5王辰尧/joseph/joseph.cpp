#include<iostream>
using namespace std;
bool mp[1001];
void joseph(int n, int m)
{
	int cnt1=0;
	int cnt2=0;
	int j=0;
	while(cnt1<n)
	{
		j++;
		if(j>n)j=1;
		if(!mp[j])
		{
			cnt2++;
			if(cnt2==m)
			{
				mp[j]=1;
				cout<<j<<" ";
				cnt1++;
				cnt2=0;
			}
		}
	}
}
int main()
{
	freopen("joseph.in","r",stdin);
	freopen("joseph.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	joseph(n,m);
	return 0;
}
