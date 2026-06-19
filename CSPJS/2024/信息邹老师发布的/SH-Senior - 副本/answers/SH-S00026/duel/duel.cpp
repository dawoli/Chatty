#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,cnt[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int r;
		cin>>r;
		cnt[r]++;
	}
	int ans=n,rst=0;
	for(int i=1;i<=100000;i++){
		if(cnt[i]==0) continue;
		int kl=min(cnt[i],rst);
		ans-=kl;
		(rst+=cnt[i])-=kl;
	}
	cout<<ans<<endl;
	return 0;
} 
