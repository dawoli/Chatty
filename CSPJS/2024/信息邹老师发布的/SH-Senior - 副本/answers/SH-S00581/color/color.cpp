#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j>=n;j++){
				if(a[i]==a[j]&&i!=j){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
