#include<bits/stdc++.h>
using namespace std;
int n,a[1001000];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int ans=0;
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j];  
		}
	    for(int j=n-1;j>=0;j--){
	    	for(int k=j-1;k>=0;k--){
	    		if(a[j]==a[k]){
	    			ans=ans+a[j];
	    			break;
				}
			}
		}
		cout<<ans<<endl;	
	}
}
