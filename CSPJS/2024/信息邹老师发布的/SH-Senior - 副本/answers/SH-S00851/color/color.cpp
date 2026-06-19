#include<bits/stdc++.h>
using namespace std;
int n,a[200015];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=0;i<1<<n;i++){
			int tmp=0;
			for(int j=0;j<n;j++){
				for(int k=j-1;k>=0;k--){
					if((i>>j&1)==(i>>k&1)){
						if(a[j]==a[k])tmp+=a[k];
						break;
					}
				}
			}
			ans=max(ans,tmp);
		}
		cout<<ans<<endl;
	}
	return 0;
}
