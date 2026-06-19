#include <bits/stdc++.h>
using namespace std;

int n,a[500005],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool isA=true;
	bool isB=true;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			isA=false;
		}
		if(a[i]!=0&&a[i]!=1){
			isA=false;
			isB=false;
		}
	}
	if(isA&&k==0){
		cout<<n/2<<endl;
		return 0;
	}
	int ans=0;
	if(isB){
		if(k==0){
			for(int i=0;i<n;i++){
				if(a[i]==a[i+1]&&i+1<n){
					ans++;
					i++;
				}
			}
			cout<<ans<<endl;
		} else if(k==1){
			for(int i=0;i<n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
