#include<bits/stdc++.h>
using namespace std;

#define ll long long
constexpr int N=1e5+7;

ll n,a[N],cnt[N],ans;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cnt[a[i]]++;
		ans=max(ans,cnt[a[i]]);
	}
	cout<<ans;
	return 0;
}
//Hughpig(Luogu646208)
