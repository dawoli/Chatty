#include<bits/stdc++.h>
using namespace std;
int t,ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[n+5];
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		for(int j=0;j<n;j++){
			for(int k=j;k<n;k++){
				if(a[j]==a[k]&&k!=j){
					ans+=a[j];
				} 
			}
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
