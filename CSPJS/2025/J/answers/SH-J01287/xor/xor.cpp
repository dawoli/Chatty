#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool vis[500005];
int cnt;
int xr(int s,int e){
	long long ans=0;
	for(int i=s;i<=e;i++){
		ans^=a[i];
	}
	return ans;
}
int main(){
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
//			cout<<i<<' ';
			vis[i]=1;
			cnt++;
		}
	}
	for(int i=1;i<n;i++){
		if(vis[i]) continue;
		for(int j=i+1;j<=n;j++){
			if(vis[j]) break;
			long long now=xr(i,j);
			if(now==k){
				cnt++;
//				cout<<i<<' '<<j<<endl;
				i+=j-i;
				break;
			}
		}
	}
	cout<<cnt;
}
