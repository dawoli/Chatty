#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt,sum,maxn;
void dfs(int k){
	sum+=a[k];
	if(k+1==n) return;
	if(sum>a[k+1]){
		cnt++;
		cout<<a[k]<<" ";
		return;
	}
	for(int i=k+1;i<n;i++){
		dfs(i);
		dfs(i+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[0]+a[1]>a[2]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		dfs(i);
	}
	cout<<endl<<(cnt%998244353);
	return 0;
}
