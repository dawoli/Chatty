#include <bits/stdc++.h>
#define singletest
using namespace std;
int dist[201];
int t[201][201];
int n,m;
int r_score;
class ProvedSolution
{
	public:
	void mainentry()
	{
		int i=1,j=1;
		for(int k=1;k<=n*m;)
		{
			while(j<n)
			{
				// cout<<j;
				j++,k++;
				if(dist[k]==r_score)
				{
					cout<<i<<" "<<j;
					exit(0);
				}
			}
			i++,k++;
			if(dist[k]==r_score)
			{
				cout<<i<<" "<<j;
				exit(0);
			}
			while(j>1)
			{
				j--,k++;
				if(dist[k]==r_score)
				{
					cout<<i<<" "<<j;
					exit(0);
				}
			}
			i++,k++;
			if(dist[k]==r_score)
			{
				cout<<i<<" "<<j;
				exit(0);
			}
		}
	}
};
class Solution
{
	public:
	void mainentry()
	{
		
	}
};

void init()
{
	memset(dist,0,sizeof dist);
	n=m=r_score=0;
}
void solve()
{
	init();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>dist[i];
	r_score=dist[1];
	sort(dist+1,dist+n*m+1,greater<int>());
	ProvedSolution().mainentry();
	//for(int i=1;i<=n;i++) {for(int j=1;j<=m;j++) cout<<t[i][j]<<" ";cout<<endl;} 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	#ifdef singletest
	solve();
	#else
	int n;
	cin>>n;
	while(n--) solve();
	#endif
	return 0;
}
