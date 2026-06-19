#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const long long mod=998244353;
int n,a[N],ans,carry;

void bfs(int tot,int l,int index,int maxn,int len){
	if(l==len){
		if(tot>2*maxn){
			ans++;ans%=mod;
		}
		return;
	}
	for(int i=index+1;i<=n-len+l+1;i++){
		if(l==len-1){
			if(tot+a[i]<=2*max(maxn,a[i])) break;
		}
		bfs(tot+a[i],l+1,i,max(maxn,a[i]),len);
	}
}

int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int len=3;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			bfs(a[i],1,i,a[i],len);
		}
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
