#include<bits/stdc++.h>
using namespace std;
int c[100005],n,ans=0;
bool w[100005];
int cal(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(w[i]==w[j]){
				if(c[i]==c[j])	cnt+=c[i];
				break;
			}
		}
	}
	return cnt;
}
void dfs(int dep){
	if(dep>n){
		ans=max(ans,cal());
		return ;
	}
	w[dep]=0;
	dfs(dep+1);
	w[dep]=1;
	dfs(dep+1);
	return ;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for(int QAQ=1;QAQ<=T;QAQ++){
		memset(c,0,sizeof(c));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) 	cin>>c[i];
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}

