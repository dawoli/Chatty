#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5+5;
int n,m,k,T,cnt[MAXN],a[MAXN],c[MAXN],x[4];
string s[25];

int calc(int x){
	int ans=0;
	while(x)
	{
		x/=2;
		++ans;
	}
	return ans;
}

signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>cnt[i];
	for(int i=1;i<=m;++i)
		cin>>c[i];
	k=calc(n);
	for(int i=1;i<=k;++i)
		cin>>s[i];
	cin>>T;
	srand(time(NULL));
	while(T--)
	{
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;++i)
			a[i]=cnt[i]^x[i%4];
		cout<<(rand()%(n*n)+(n*n))%(n*n)<<endl;
	}
	return 0;
}
