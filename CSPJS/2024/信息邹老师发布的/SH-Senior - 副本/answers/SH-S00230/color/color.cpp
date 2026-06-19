#include <bits/stdc++.h>
using namespace std;
int t[1000005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		long long ans=0;
		int maxn=0;
		for(int i=1;i<=n;i++){
			int a; cin>>a;
	//	cout<<ans<<'\n';
			maxn=max(a,maxn);
			if(t[a]){
				ans+=a;
				t[a]=0;
			}else{
				t[a]=1;
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=maxn;i++){
			t[i]=0;
		}
	}
	return 0;
}
