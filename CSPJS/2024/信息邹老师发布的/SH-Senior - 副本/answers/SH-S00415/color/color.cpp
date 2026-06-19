#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int col[maxn][2];
int n,a[maxn],vis[maxn];
int j[2];
int dfs(int i,bool x){
	if(i==n){
		return 0;
	}
	if(!vis[x]){//无数与他同色 
		vis[x]=true;
		return max(dfs(i+1,0),dfs(i+1,1))+0; 
	} 
	else{
		if(a[i]==col[j[x]][x]){
			j[x]++;
			col[j[x]][x]=a[i];
			return max(dfs(i+1,0),dfs(i+1,1))+a[i];
		}
		else{
			j[x]++;
			col[j[x]][x]=a[i];
			return max(dfs(i+1,0),dfs(i+1,1));
		}
	}
} 
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];	
		}
		col[0][0]=a[0];
		cout<<dfs(0,0)<<endl;
		j[0]=0;
		j[1]=0;
	}
} 
