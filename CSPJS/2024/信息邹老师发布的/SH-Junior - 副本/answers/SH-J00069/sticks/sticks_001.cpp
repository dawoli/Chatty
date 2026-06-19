#include<bits/stdc++.h>
using namespace std;
int t,n,minn=1e8;
string a={'6','2','5','5','4','5','6','3','7','6'};
void dfs(int gs,string zs){
	if(gs==1){
		return ;
	}
	else{
		minn=min(minn,zs-'0');
	}
	for(int i=0;i<10;i++){
		if(gs>=a[i]){
			dfs(gs-a[i],zs+a[i]);
		}
	}
} 
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		dfs(n,0);
		if(minn==1e8) cout<<"-1"<<endl;
		else cout<<minn<<endl;
	}
	return 0; 
} 
