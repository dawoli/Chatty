#include<bits/stdc++.h>
using namespace std;
int T,n;
const int N=2e5+5;
int a[N]; 
int maxn;
void dfs(int pos,int sum,int red,int blue){//0Ϊred 1Ϊblue 
	if(pos==n+1){
		maxn=max(maxn,sum);
		return ;
	}
	if(red==a[pos]){
		dfs(pos+1,sum+red,a[pos],blue);
	}else{
		dfs(pos+1,sum,a[pos],blue);
	}
	if(blue==a[pos]){
		dfs(pos+1,sum+blue,red,a[pos]);
	}else{
		dfs(pos+1,sum,red,a[pos]);
	}
	
	return ;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int l=1;l<=T;l++){
		maxn=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1,0,0,0);	
		cout<<maxn<<endl;
	}
	
}

