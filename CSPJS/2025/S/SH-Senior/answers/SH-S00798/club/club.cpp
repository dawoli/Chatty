#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
const int MAXN=1e5+5;
ll ans;int n,t;
int A1[MAXN],A2[MAXN],A3[MAXN];
int maxn;
ll dfs(int pos,ll ans,int n1,int n2,int n3){
	//cout<<pos<<" "<<ans<<endl;
	if(n1>=maxn || n2>=maxn || n3>=maxn) {
		return 0;
	}
	if(pos==n+1) return ans;
	int x = A1[pos],y=A2[pos],z=A3[pos];
	return max(max(dfs(pos+1,ans+x,n1+1,n2,n3),dfs(pos+1,ans+y,n1,n2+1,n3)),dfs(pos+1,ans+z,n1,n2,n3+1));
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		
		maxn=n/2;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>A1[i]>>A2[i]>>A3[i];
		}
		
		cout<<dfs(0,0,0,0,0);
		}
	return 0;
}
