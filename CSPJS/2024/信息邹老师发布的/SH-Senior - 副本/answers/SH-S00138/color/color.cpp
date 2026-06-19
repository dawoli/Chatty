#include<bits/stdc++.h>
using namespace std;
int n,a[214514],s[214514],f[214514],t=-1;
void dfs(int d){
	if(d==n+1){
		int x=0;
		for(int i=1;i<=n;i++){
			if(f[i]==f[s[i]])x+=a[i]; 
		}
		if(x>0)t=max(t,x);
		return;
	}
	dfs(d+1);
	f[d]=1;
	dfs(d+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int q;cin>>q;
	while(q--){
	t=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		s[i]=0;
		for(int j=i-1;j>0;j--){
			if(a[i]==a[j]){s[i]=j;break;}
		}
	}
	memset(f,0,sizeof(f));
	f[0]=114514;
	dfs(1);
	cout<<t<<endl;
	}
	return 0;
}
