#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010],ans,h,l;
void dfs(int jh,int jl,int step,int s){
	if(step>n){
		ans=max(ans,s);
		return;
	}
	if(a[jh]==a[step])
		dfs(step,jl,step+1,s+a[step]);
	else
		dfs(step,jl,step+1,s);
	if(a[jl]==a[step])
		dfs(jh,step,step+1,s+a[step]);
	else
		dfs(jh,step,step+1,s);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(n<=15){
			ans=0;
			dfs(0,0,1,0);
			cout<<ans<<endl;
		}
		else{
			h=a[1];
			l=0;
			for(int i=2;i<=n;++i){
				if(a[i]==h)
					ans+=h;
				else if(a[i]==l)
					ans+=l;
				else
					l=a[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
