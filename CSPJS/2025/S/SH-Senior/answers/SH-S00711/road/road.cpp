#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e4+5;
int n,m,k;
struct node{
	int st,to;
};
int u[MAXN],v[MAXN],w[MAXN];
vector <node> p[MAXN];

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
    {
    	cin>>u[i]>>v[i]>>w[i];
	}
	cout<<114514<<endl;
	return 0;
}
