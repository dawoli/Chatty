#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,r[N],vis[N],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	int cnt=1;
	for(int i=1;i<=n;i++){
		while(cnt<=n && (r[cnt]<=r[i] || vis[cnt])){
			cnt++;
		}
		if(cnt>n)	continue;
		vis[cnt]=1;
		ans++;
	}
	cout<<n-ans;
	return 0;
} 

