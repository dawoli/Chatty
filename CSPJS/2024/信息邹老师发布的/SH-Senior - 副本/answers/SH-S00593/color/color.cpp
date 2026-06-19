#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int t;
int n;
int a[N];
int c[N];
int ans;

void check(){
	int re=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(c[j]==c[i]){
				if(a[i]==a[j]) re+=a[i];
				break;
			}
		}
	}
	ans=max(ans,re);
}

void dfs(int step){
	if(step==n+1){
		check();
		return;
	}
	c[step]=0;
	dfs(step+1);
	c[step]=1;
	dfs(step+1);
}

void subtask1(){
	ans=0;
	c[0]=-100;
	dfs(1);
	cout<<ans<<endl;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		subtask1();
	}
	return 0;
}
