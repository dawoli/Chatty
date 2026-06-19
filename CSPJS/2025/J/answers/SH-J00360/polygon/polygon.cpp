#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=0;i<=(1<<n)-1;i++){
		int cnt=0,maxn=-1,sum=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				cnt++;
				maxn=max(maxn,a[j]);
				sum+=a[j];
			}
		}
		if(cnt<3)continue;
		if(sum>maxn*2){
			ans++;
			ans%=998244353;
		}
	}
	cout<<ans;
}
