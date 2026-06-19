#include<bits/stdc++.h>
using namespace std;
long long n,x,a[10]={6,2,5,5,4,5,6,3,7,6},mn;
void dfs(long long k,long long now){
	if(k==0){
		mn=min(mn,now);
		return;
	}
	if(k<=1) return;
	if(k!=n&&now!=0){
		if(k>=a[0]){
			now*=10;
			k-=a[0];
			dfs(k,now);
			k+=a[0];
			now/=10;
		}
	}
	for(long long i=1;i<=9;i++){
		if(k>=a[i]){
			now=now*10+i;
			k-=a[i];
			dfs(k,now);
			k+=a[i];
			now=(now-i)/10;
		}
	}
	return;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x;
		if(x<=1){
			puts("-1");
			continue;
		}
		mn=0x3f3f3f3f;
		int ans=0;
		dfs(x,ans);
		cout<<mn<<"\n";
	}
	return 0;
}
