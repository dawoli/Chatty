#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005],choose[100005],ANS;
int calc(){
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i-1;j>=1;j--)
			if(choose[i]==choose[j])
				if(a[i]==a[j]) ans+=a[j];
				else break;
	return ans;
}
void dfs(int x){
	if(x==n+1) {ANS=max(ANS,calc());return;}
	choose[x]=1;
	dfs(x+1);
	choose[x]=0;
	dfs(x+1); 
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		ANS=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs(1);
		cout<<ANS<<endl;
		for(int i=1;i<=n;i++) choose[i]=0;
	}
	return 0;
}
