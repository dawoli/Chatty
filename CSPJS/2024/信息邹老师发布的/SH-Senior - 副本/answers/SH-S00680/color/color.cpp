#include<bits/stdc++.h>
using namespace std;
int T;
int n,a[100002];
bool color[20];
long long ans=-1e18;
void dfs(int x){
	if(x>n){
		long long _ans=0;
		for(int i=1;i<=n;i++){
			int j=i-1;
			while(j>0&&color[j]!=color[i])
				j--;
			if(j!=0&&a[j]==a[i])
				_ans+=a[i];
		}
		ans=max(ans,_ans);
		return;
	}
	color[x]=0;
	dfs(x+1);
	color[x]=1;
	dfs(x+1);
	return;
}
void solve1(){
	dfs(1);
	cout<<ans<<endl;
}
void solve2(){
	cout<<0<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n<=15)
			solve1();
		else
			solve2();
	}
	return 0;
}
