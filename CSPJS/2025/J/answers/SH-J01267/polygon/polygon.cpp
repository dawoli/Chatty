#include<bits/stdc++.h>
using namespace std;
int n,ans,sum=0,a[1009],t,m;
void dfs(int x){
	for(int i=1;i<=x;i++){
		cout<<"   ";
	}
	cout<<"dfs("<<x<<"),ans="<<ans<<",a[x]="<<a[x]<<",sum="<<sum<<"     +     "<<endl;
	sum+=a[x];
	if(x!=n){
		dfs(x+1);
	}
	for(int i=1;i<=x;i++){
		cout<<"   ";
	}
	cout<<"dfs("<<x<<"),ans="<<ans<<",a[x]="<<a[x]<<",sum="<<sum<<"     -      "<<endl;
	if(sum>2*a[x] and x>=3) ans++;
	sum-=a[x];
	if(x!=n){
		dfs(x+1);
	}
	return; 
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3) cout<<"0"<<endl;
	else if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]) cout<<1<<endl;
		else cout<<0<<endl;
	}
	else{
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
