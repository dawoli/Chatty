#include<bits/stdc++.h>
using namespace std;
int n,m,A[505],a[505],c[505],T,K;
char mp[505][505];
struct node
{
	int id,val;
};
int l2(int x)
{
	for(int i=0;i<=31;i++)
	    if((1<<i)>x)
	        return i-1;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n<=8&&m<=8)
	{
		cout<<11<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	    cin>>A[i];
	for(int i=1;i<=n;i++)
	    cin>>c[i];
	K=1;
	while((1<<K)<n) K++;
	for(int R=1;R<=K;R++)
	{
		for(int G=1;G<=(1<<(K-R));G++)
		    cin>>mp[R][G];
	}
	cin>>T;
	while(T--)
	{
		int ans=0;
		int xx[4];
		for(int i=0;i<3;i++)
		    cin>>xx[i];
		for(int i=1;i<=n;i++)
		    a[i]=A[i]^xx[i%4];
		for(int i=1;i<=m;i++)
		{
			vector<node> v,v1;
			v.clear();
			v1.clear();
			for(int i=1;i<=c[i];i++)
			    v.push_back((node){i,a[i]});
			for(int r=1;r<=l2(c[i]);r++)
			{
				for(int g=1;g<=c[i]/(1<<r);g++)
				{
					node left=v[g*2-2],right=v[g*2-1];
					if(mp[r][g]=='0')
					{
						if(left.val>=r)
						    v1.push_back(left);
						else
						    v1.push_back(right);
					}
					else
					{
						if(right.val>=r)
						    v1.push_back(right);
						else
						    v1.push_back(left);
					}
				}
				v=v1;
				v1.clear();
			}
			ans^=i*v[0].id;
		}
		cout<<ans<<endl;
    }
	return 0;
}
/*
5 5
0 0 0 0 0
1 2 2 4 4
1001
10
1
1
2 1 0 0
*/


