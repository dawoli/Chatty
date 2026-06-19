#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long pos[1000009][1000009];
long long scores[1000009];
int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>scores[i];
	int xa=scores[1];
	sort(scores,scores+n*m);
	int cur=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				pos[i][j]=scores[cur];
				cur++;
				if (pos[i][j]==xa)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j++)
			{
				pos[i][j]=scores[cur];
				cur++;
				if (pos[i][j]==xa)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		} 
	}
}
