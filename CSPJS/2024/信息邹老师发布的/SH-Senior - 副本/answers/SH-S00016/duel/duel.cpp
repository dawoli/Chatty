#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=100010;
int n,c,d;
int a[N],cnt[N];

signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			c++;
			cnt[c]=i-d;
			d=i;
		}
	}
	if(c==2){
		cout<<n-min(cnt[1],cnt[2])<<endl;
		return 0;
	}
	for(int i=2;i<=c;i++){
		if(cnt[i]>=cnt[i-1]){
			cnt[i-1]=0;
		}
		if(cnt[i]<cnt[i-1]){
			cnt[i]=cnt[i-1];
			cnt[i-1]=0;
		}
	}
	int ans=0;
	for(int i=1;i<=c;i++){
		ans+=cnt[i];
	}
	cout<<ans<<endl;
	return 0;
}
