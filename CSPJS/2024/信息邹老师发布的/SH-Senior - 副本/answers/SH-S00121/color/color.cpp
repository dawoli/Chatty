#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0;
		cin>>n;
		int a[10000];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<(1<<n);i++){
			int lns=0;
			for(int j=n-1;j>=0;j--){
				for(int k=j-1;k>=0;k--){
					if(((i>>j)&1)==((i>>k)&1)){
					 	if(a[j]==a[k]) lns+=a[j];
					 	break;
					}
				}
			}
			ans=max(ans,lns);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
