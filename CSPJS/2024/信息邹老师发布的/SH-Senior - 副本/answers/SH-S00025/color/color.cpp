#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int T,n,a[N],is[N],ans;
void dfs(int id){
	if(id<=n){
		is[id]=1; dfs(id+1);
		is[id]=2; dfs(id+1);
	}else{
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=i-1;j>=1;j--){
				if(is[j]==is[i]){
					if(a[i]==a[j]) cnt+=a[i];
					else break;
				} 
			}
		ans=max(ans,cnt);
	}
}
void solveBBF(){
	ans=0;
	dfs(1);
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		solveBBF();
	}
	return 0;
}

