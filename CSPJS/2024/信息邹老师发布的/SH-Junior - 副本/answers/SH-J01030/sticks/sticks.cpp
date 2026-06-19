#include<iostream>
#include<cstring>
using namespace std;
#define int long long
int n,t,c[10]={6,2,5,5,4,5,6,3,7,6};
int dfs(int n,int s,int dig,int l){
	if(n==0) return s;
	if(n<0||dig>10) return 1e18;
	int ans=1e18;
	for(int i=0;i<=9;i++){
		if(l&& !i) continue;
		ans=min(ans,dfs(n-c[i],10*s+i,dig+1,0));
	} 
	return ans;
}
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int tes=1;tes<=t;tes++){
		cin>>n;
		if(n==1) cout<<-1;
		else if(n%7==0){
			for(int i=1;i<=n/7;i++)
				cout<<8;
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<=(n-8)/7;i++) 
				cout<<8;
		}
		else if(n<=50) cout<<dfs(n,0,0,1);
		cout<<endl;
		
	}
} 
