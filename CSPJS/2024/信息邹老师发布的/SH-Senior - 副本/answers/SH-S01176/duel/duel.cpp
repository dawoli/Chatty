#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,r[100005],cnt[100005],maxcnt;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
    	cin>>r[i];
    	cnt[r[i]]++;
	}
	for(ll i=1;i<=100000;i++){
		maxcnt=max(maxcnt,cnt[i]);
	}
	cout<<maxcnt;
    return 0;
}

