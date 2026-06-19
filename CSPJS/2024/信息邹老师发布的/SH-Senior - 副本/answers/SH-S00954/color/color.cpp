#include <bits/stdc++.h>
using namespace std;
int val[200100]={0};
int flag[200100]={0};
int n;
int ans=0;
int Comp(){
	int ans=0;
	for(int i=1;i<n;i++){
		int tpos=i-1;
		while(tpos>=0&&flag[tpos]!=flag[i]){
			tpos--;
		}
		if(tpos>=0){
			if(val[tpos]==val[i])ans+=val[i];
		}
	}
	return ans;
}
void dfs(int pos){
	if(pos==n){
		ans=max(ans,Comp());
	}else{
		flag[pos]=0;
		dfs(pos+1);
		flag[pos]=1;
		dfs(pos+1);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		memset(flag,0,sizeof(flag));
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>val[i];
		}
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}
