#include<bits/stdc++.h>
using namespace std;
const int N=5009;
const long long M=998244353;
int a[N];
int n=0;
int mar=0;
long long ans=0;
void fan(int i,int na,int ma,int m){
	if(n+m<i+3) return;
	if(m>=3&&i==n){
		if(na>2*ma) ans++;
		ans=ans%M;
		return;
	}
	if(na>2*mar){
		long long cnt=1;
		for(int i=1;i<=n-i-1;i++){
			cnt=cnt*2;
			cnt=cnt%M;
		}
		ans=ans+cnt;
		return;
	}
	fan(i+1,na+a[i],max(ma,a[i]),m+1);
	fan(i+1,na,ma,m);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mar=max(mar,a[i]);
	}
	if(mar==1){
		long long cnt=1;
		for(int i=1;i<=n;i++){
			cnt=cnt*2;
			cnt=cnt%M;
		}
		cout<<cnt-n-(n*(n-1))%M/2-1<<endl;
		return 0;
	}
	fan(0,0,0,0);
	cout<<ans<<endl;
	return 0;
}
