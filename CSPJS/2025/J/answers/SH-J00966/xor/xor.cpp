#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=0;i<n;i++){
		    if(a[i]==1&&a[i+1]==1){
		    	ans++;
		    	i++;
			}
			if(a[i]==0){
				ans++;
			}
	    }
	}
	if(k==1){
		for(int i=0;i<n;i++){
			if(a[i]==1){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
