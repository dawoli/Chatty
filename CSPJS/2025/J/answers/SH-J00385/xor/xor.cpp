#include<bits/stdc++.h>
using namespace std;
int a[10010];
int n,k,t,p=1,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){ 
		for(int j=p;j<=i;j++){
			if(j==p)t=a[p];
	    	else t=t^a[j];
		   	if(t==k){
		    	i=j+1;
			    p=j+1;
	    		ans++;
		    	break;
    		}
	    }
	}
	cout<<ans;
	return 0;
}
