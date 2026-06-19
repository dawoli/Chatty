#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[5050]={0},w[5050];
ll ans=0,idx=0,n,x; 
bool IsVaild(void){
	if(idx==0){
		return false;
	}
	ll sum=0,maxx=-1;
	for(int i=1;i<=idx;i++){
		sum+=a[i];
		maxx=max(a[i],maxx);
	}
	return sum>2*maxx;
}
void prt(void){
	ll sum=0,maxx=-1;
	cout<<"Sol:";
	for(int i=1;i<=idx;i++){
		sum+=a[i];
		maxx=max(a[i],maxx);
		cout<<a[i]<<" ";
	}
	cout<<"\t,sum\t"<<sum<<"max\t"<<maxx<<"\n";
}
void dfs(int x,int maxn){
	if(x>maxn){
		if(IsVaild()){
			ans++;
			//prt();
		}
		return;
	}
	a[++idx]=w[x];
	dfs(x+1,maxn);
	idx--;
	dfs(x+1,maxn); 
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	dfs(1,n);
	cout<<ans;
}
