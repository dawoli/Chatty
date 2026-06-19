#include<bits/stdc++.h>
using namespace std;
int asd;
vector<vector<int>> ans;
vector<int> s;

bool cmp(int a,int b)
{
	if(a>b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<m*n;i++)
	{
		cin>>asd;
		s.push_back(asd);
	}
	int ans1=s[0];
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<m;i++)
	{
		if(i%2==0)
		{
			vector<int> l;
			for(int j=0;j<n;j++)
			{
				l.push_back(s[i*n+j]);
			}
			ans.push_back(l);
		}
		if(i%2==1)
		{
			vector<int> l;
			for(int j=n-1;j>=0;j--)
			{
				l.push_back(s[i*n+j]);
			}
			ans.push_back(l);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ans[i][j]==ans1)
			{
				cout<<i+1<<" "<<j+1;
			}
		}
	}
	return 0;
}
