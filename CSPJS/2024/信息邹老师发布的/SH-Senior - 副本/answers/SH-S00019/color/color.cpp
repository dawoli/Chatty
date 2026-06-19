#include <bits/stdc++.h>
using namespace std;

long long t,n,a[200005],ans,f[200005];

void dfs(long long k){
	if(k==n){
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(f[j]==f[i]){
					if(a[j]==a[i]) sum+=a[i];
					break;
				}
			}
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=2;i++){
		f[k+1]=i;
		dfs(k+1);
	}
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		if(n<=15){
			dfs(0);
		}else{
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++){
				if(f[a[i]]) ans+=a[i];
				f[a[i]]++;
			} 
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
