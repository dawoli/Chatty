#include<bits/stdc++.h>
#define N 200005
using namespace std;

long long ans;
int a[N],n;
bool vis[N],dir[2]={true,false};

void defs(int rt,long long res){
	if(rt==0){
		ans=max(ans,res);
		return;
	}
	for(int i=0;i<2;++i){
		vis[n-rt]=dir[i];
		for(int j=n-rt-1;j>=0;--j){
			if(vis[j]==vis[n-rt]&&a[n-rt]==a[j]){
				defs(rt-1,res+a[n-rt]);
				break;
			}
		}
		defs(rt-1,res);
	}
	return;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=-1e18;
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>a[i];
		defs(n,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
