#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define R 114514
#define N 114514
ll r[N];
ll cnt[R];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	ll rma=0;
	for(int i=1;i<=n;i++) {
		cin>>r[i];
		cnt[r[i]]++;
		rma=max(r[i],rma);
	}
	ll sum=0;//下方剩多少弱者
	ll ans=0;
	for(int ir=1;ir<=rma;ir++) {
		if(cnt[ir]>=sum) {
			ans+=sum;//全被克 
			sum=0;
		}
		else {//能克多少克多少 
			ans+=cnt[ir];
			sum-=cnt[ir];
		}
		sum+=cnt[ir];
	}
	cout<<n-ans;
	return 0;
}

