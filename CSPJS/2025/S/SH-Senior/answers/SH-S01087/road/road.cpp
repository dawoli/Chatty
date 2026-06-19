#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[100010],v[100010],w[100010],ans=0;
int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
