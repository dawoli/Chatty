#include<iostream>
using namespace std;
int vis[10]={6,2,5,5,4,5,6,3,7,6};
int t,n,st;
int dfs(int sy){
	for(int i=0;i<=9;i++){
		int n=dfs(sy-vis[i]);
		if(n!=-1){
			return 10*i+n;
		}
	}
	return -1;
}
int main(){
	freopen("sticks.in","w",stdin);
	freopen("sticks.out","r",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		int flag=true;
		cin>>st;
		int sy=st;
		if(sy<2){
			cout<<"-1"<<endl;
			continue; 
		}
		for(int i=1;i<=9;i++){
			if(sy-vis[i]==0){
				flag=false;
				cout<<i<<endl;
				break;
			}
		}
		if(flag){
			cout<<dfs(sy)<<endl;
		}
	}
	return 0;
}
