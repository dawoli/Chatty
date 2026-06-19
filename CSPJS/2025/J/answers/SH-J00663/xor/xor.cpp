#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		int a=0,x,ans=0;
		for(int i=1;i<=n;i++){
			cin>>x;
			a+=x;
			if(a%2==1&&i<n){
				cin>>x;
				a+=x;
				i++;
				if(a%2==1){
					ans++;
				}
			}
			if(a%2==0){
				ans++;
			}
			a=0;
		}
		cout<<ans<<endl;
	}
	else if(k==1){
		int a=0,x;
		for(int i=1;i<=n;i++){
			cin>>x;
			a+=x;
		}
		cout<<a<<endl;
	}
	return 0;
}
