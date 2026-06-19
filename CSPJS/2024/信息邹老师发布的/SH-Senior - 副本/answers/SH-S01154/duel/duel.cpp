#include<bits/stdc++.h>
using namespace std;
int n, r, rcnt=0, cnt[100005], ans=-1, num[100005];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>r;
		if(!cnt[r]){
			rcnt++;
			num[rcnt]=r;
		}
		cnt[r]++;
	}
	for(int i=1; i<=rcnt; i++){
		ans=max(cnt[num[i]], ans);
	}
	cout<<ans;
	return 0;
}
