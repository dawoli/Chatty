#include<bits/stdc++.h>
using namespace std;
int n,m,l,v,ans=0;
int a[100005],u[100005],d[100005];
void solve1(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	bool f=0;
	for(int i=1;i<=n;i++){
		if(a[i]>v){
			cout<<1<<" ";
			f=1;
			ans++;
		}
	}
	if(f=1){
		cout<<ans<<" "<<m-1;
	}else{
		cout<<0<<" "<<m;
	}
}
int main(){
	int t=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>u[i]>>a[i];
		}
		if(u[1]==0){
			solve1();
		}
	}
	return 0;
}
