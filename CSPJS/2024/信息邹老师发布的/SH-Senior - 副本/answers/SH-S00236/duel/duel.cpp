#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef pair<int,int> pii;
int n,m,x,y,a[200010]; 
int cnt[200010];
signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	rep(i,1,n) cin>>a[i],cnt[a[i]]++;
	int ncnt=0,ans=0;
	rep(i,1,100000)
	{
		if(cnt[i]>=ncnt)
		{
			ans+=ncnt;
			ncnt=0;
		}
		else
		{
			ans+=cnt[i];
			ncnt-=cnt[i];
		}
		ncnt+=cnt[i];
	}
	cout<<n-ans<<endl;
} 
