#include<bits/stdc++.h>
using namespace std;
int t,ans;
int cost[7]={6,2,5,4,6,3,7};
void dfs(int wei,int num){
	if(wei==m+1 && cnt==n){
		ans=num;
		return;
	}
	else if(wei==m+1) dfs(wei-1,num/10); 
	else{
		for(int i=0;i<=6;i++){
			cnt+=cost[i];
			dfs(wei+1,num*10+i); 
		}
	}
}
int main(){
	//freopen("sticks.in","r",stdin);
	//freopen("sticks.out","w",stdout);
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		if(n==1) cout<<-1;
		else{
			int m=n/7;
			if(m%7) m+=1;
			int cnt=0;
			dfs(1,0);
			cout<<ans; 
		}
	}
	return 0;
}
