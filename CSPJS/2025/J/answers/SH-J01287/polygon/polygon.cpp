#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n;
int a[5005],b[5005];
int dfs(int len,int sum,int big,int now){
	if(b[now]+sum<=big*2){
//		cout<<now<<' '<<sum<<endl;
		return 0;
	}
	if(len+now<3){
//		cout<<2;
		return 0;
	}
	if(now==0){
//		cout<<3;
		return 1;
	}
	return (dfs(len+1,sum+a[now],big,now-1)+dfs(len,sum,big,now-1))%N;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		if(b[i]<=a[i]*2) continue;
		ans+=dfs(1,a[i],a[i],i-1)%N;
	}
	cout<<ans;
}
