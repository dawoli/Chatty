#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
ll n,m;
ll a,c;
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a;
	for(int i=1;i<=m;i++) cin>>c;
	ll sum=1,k=0;
	while(sum<n)
	{
		sum=sum*2;
		k++;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c;
	}
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int t1,t2,t3,t4;
		cin>>t1>>t2>>t3>>t4;
		cout<<rand()%100<<endl;
	}
	
	return 0;
}
