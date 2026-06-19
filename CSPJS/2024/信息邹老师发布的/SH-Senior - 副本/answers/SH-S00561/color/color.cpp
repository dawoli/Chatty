#include <bits/stdc++.h>
using namespace std;
int a[200100];
int n;
int co[200010];
int ans=0;
int sum=0;
void dfs(int dep){
	if(dep==n){
		sum=0;
		for(int i=1;i<=n;i++){
			int z=i-1;
			while(z!=0&&co[z]!=co[i])z--;
			if(z!=0){
				if(a[z]==a[i])sum+=a[z];
			}
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<=1;i++){
		co[dep]=i;
		dfs(dep+1);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
