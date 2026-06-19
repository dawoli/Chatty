#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int ans=0;
int a[500010]; 
void dfs(int st,int cnt){
	if(st>=n){
		ans=max(ans,cnt);
		return;
	}
	int tmp=a[st];
	if(tmp==k){
		dfs(st+1,cnt+1);
		return;
	}
	for(int i=st+1;i<n;i++){
		tmp=tmp^a[i];
		if(tmp==k){
			dfs(i+1,cnt+1);
			return;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
cin.tie(0);
cout.tie(0); 
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dfs(i,0);
	}
	cout<<ans;
	return 0;	
}
