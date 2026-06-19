#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans;
    cin>>n>>k;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	
	}
	for(int i=0;i<n;i++){
		if(a[i]!=k&&a[i+1]!=k){
			a[i+1]-(a[i]*a[i+1]);
			
		}
		else if(a[i]=n)ans++;
		else continue;
	
	}
	cout<<ans;
	return 0;
}
