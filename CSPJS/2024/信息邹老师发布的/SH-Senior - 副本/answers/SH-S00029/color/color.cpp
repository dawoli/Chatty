#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans,cc;
bool c[200005],em=0;
void dfs(int x){
	if(x==n+1){
		cc=0;
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(c[j]==c[i]&&a[i]==a[j]){
					cc+=a[i];
					break;
				}
			}
		}
		if(cc>ans) ans=cc;
		return;
	}
	for(int i=0;i<=1;i++){
		c[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T>0){
		ans=0;
		T--;
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(em==0){
				for(int j=1;j<i;j++){
					if(a[i]==a[j]){
						em=1;
						break;
					}
				}
			}
		}
		if(em==0){
			cout<<0<<endl;
			continue;
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
