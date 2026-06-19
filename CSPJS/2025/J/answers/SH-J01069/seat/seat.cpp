#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m,a[N],id[N],x,y;
bool cmp(const int &x,const int &y)
{
	return a[x]>a[y];
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		id[i]=i;
	}
	sort(id+1,id+1+n*m,cmp);
	x=(id[1]-1)/n+1;
	y=id[1]-(x-1)*n;
	if(x%2==0)y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
}

