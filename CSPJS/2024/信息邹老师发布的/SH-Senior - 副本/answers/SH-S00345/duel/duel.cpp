#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],b[N];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int mn=N,mx=0;
	for(int i=1,s;i<=n;i++){
		cin>>s;
		a[s]++;b[s]++;
		mn=min(mn,s);
		mx=max(mx,s);
	}
	int l=mn,r=mn+1;
	int re=n;
	while(r<=mx){
		if(!b[r]){
			r++;continue;
		}
		if(b[r]>=a[l]){
			re-=a[l];
			a[l]=0;b[r]-=a[l];
			while(!a[l]) l++;
			while(!b[r]||l>=r) r++;
		}else{
			re-=b[r];
			a[l]-=b[r];
			b[r]=0;
			while(!b[r]||l>=r) r++;
		}
	}
	cout<<re;
	return 0;
}
