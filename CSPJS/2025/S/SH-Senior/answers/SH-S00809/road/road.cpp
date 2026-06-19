#include <bits/stdc++.h>
using namespace std;
int cst[1000005];
int n,m,k,u,v,w;
long long tol=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=0;i<m;i++)
		{
			cin>>u>>v>>w;
			cst[i]=w;
			tol+=w;
		}
		sort(cst,cst+m,greater<int>());
		int t=m+1-n;
		for(int i=0;i<t;i++)
		{
			tol-=cst[i];
		}
		cout<<tol;
	}
	return 0; 
}
