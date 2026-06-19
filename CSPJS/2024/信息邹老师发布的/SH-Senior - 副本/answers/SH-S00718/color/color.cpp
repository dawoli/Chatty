#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	int ans=0;
	cin>>t;
	for(int k=1;k<=t;k++){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]){
				ans+=a[i-1];
			}
		}
		cout<<ans<<endl;
		ans=0;
	}	
}
