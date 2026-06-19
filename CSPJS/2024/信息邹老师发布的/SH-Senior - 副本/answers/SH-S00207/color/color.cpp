#include<bits/stdc++.h>
using namespace std;
const int N=200020;
int T,n,a[N],ans=0;
bool state[N];
int count(){
	int cnt=0;
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>=1;j--)
			if(state[i]==state[j]){
				if(a[i]==a[j])cnt+=a[i];
				break;
			}
	return cnt;
}
void dfs(int cur){
	if(cur==n+1){
		ans=max(ans,count());
		return;
	}
	state[cur]=1;
	dfs(cur+1);
	state[cur]=0;
	dfs(cur+1);
}
void solveBF(){
	fill(state+1,state+1+N,0);
	ans=0;
	dfs(1);
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		solveBF();
	}
	return 0;
}
