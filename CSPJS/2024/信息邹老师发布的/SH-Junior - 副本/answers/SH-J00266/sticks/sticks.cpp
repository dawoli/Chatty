#include<bits/stdc++.h>
using namespace std;
int T,n,vis[10];
int num[10]={6,2,5,5,4,5,6,3,7,6};
int minn_1,cnt,minn_x;
void dfs(int sum,int cnt,int x){
	if(sum>n||x>=minn_x||cnt>=minn_1) return;
	if(sum==n){
		minn_x=min(minn_x,x);
		minn_1=min(minn_1,cnt);
		return;
	}
	int yy_1;
	if(x==0) yy_1=1;
	else yy_1=0;
	for(int i=yy_1;i<10;i++){
		dfs(sum+num[i],cnt*10+i,x+1);
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int j=1;j<=T;j++){
		cin>>n;
		if(n==1){
			cout<<-1;
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<=(n-1)/7-1;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		minn_1=1e9;
		minn_x=n/2+1;
		dfs(0,0,0);
		if(minn_1==1e9) cout<<-1<<endl;
		else cout<<minn_1<<endl;
	}
	return 0;
}
