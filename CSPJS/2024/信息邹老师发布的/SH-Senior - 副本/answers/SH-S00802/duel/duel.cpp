#include<bits/stdc++.h>
using namespace std;
int n,d[100009];
const int INF=1e9;
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n; int ans=n;
	for(int i=1;i<=n;i++) cin>>d[i]; d[n+1]=INF;
	sort(d+1,d+1+n);
	int j=1;
	for(int i=2;i<=n;i++){
		while(d[i]<=d[j]) i++;
		if(d[i]>d[j]&&d[i]!=INF) j++,ans--;
	}
	cout<<ans<<endl;
	return 0;
}
