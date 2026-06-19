#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,maxn=5010;
int n,a[maxn],b[maxn],cnt=0,ans;
void DFS(int u){
	if(u==0){
		int ma=0,sum=0;
		for(int i=1;i<=cnt;i++){
			ma=max(ma,a[b[i]]);
			sum+=a[b[i]];
		}
		ans+=2*ma<sum;
	}
	else{
		for(int i=b[cnt]+1;i<=n;i++){
			b[++cnt]=i;
			DFS(u-1);
			cnt--;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	for(int k=3;k<=n;k++){
		DFS(k);
	}
	cout<<ans;
	return 0;
}
