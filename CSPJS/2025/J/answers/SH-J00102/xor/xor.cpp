#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int k;
	cin>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++){
			if(a[i]==1&&a[i+1]==1){
				if(k==0){
					if(i%pow(2,j)==0){
						ans++;
					}
				}	
			}
		}
	}
	cout<<ans;
	return 0;
}
