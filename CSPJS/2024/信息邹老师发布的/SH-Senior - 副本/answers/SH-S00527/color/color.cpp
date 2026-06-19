#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;

int T,n,ans;
int a[maxn],c[maxn];
bool color[maxn];

void dfs(int now){
	if(now>n){
		int left[2]={0,0};
		for(int i=1;i<=n;i++){
			if(left[color[i]]==0)c[i]=0;
			else{
				if(a[left[color[i]]]==a[i])c[i]=a[i];
				else c[i]=0;
			}
			left[color[i]]=i;
		}
		int res=0;
		for(int i=1;i<=n;i++)res+=c[i];
		ans=max(ans,res);
		return;
	}
	color[now]=0;
	dfs(now+1);
	color[now]=1;
	dfs(now+1);
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--){
		ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
