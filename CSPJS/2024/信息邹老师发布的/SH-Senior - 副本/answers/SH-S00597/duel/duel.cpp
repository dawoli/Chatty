#include<bits/stdc++.h>
#define N ((int)(1e5)+10)
using namespace std;
typedef long long ll;
int n;
int cnt[N];
priority_queue<int,vector<int>,greater<int> > Q;
int ans;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		Q.push(x);
		cnt[x]++;
	}
	ans=n;
	for(int i=1;i<=100000;i++){
		while(cnt[i]&&Q.top()<i)Q.pop(),cnt[i]--,ans--;
	}
	printf("%d",ans);
}
