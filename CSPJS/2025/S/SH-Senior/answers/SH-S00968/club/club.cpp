#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while (t--){
        long long n,ans=0;
        cin>>n;
        if(n<100000){ 
        	int l[n+2][3]={};
        	for (int i=1;i<=n;i++){
            	cin>>l[i][0]>>l[i][1]>>l[i][2];
        	}
        	int f[n+2][n+2][n+2];
        	for (int i=0;i<=n/2;i++){
            	for (int j=0;j<=n/2;j++){
                	for (int k=0;k<=n/2;k++){
                		f[i][j][k]=0; 
                    	if (i+j+k<=n){
                    	    if (i>0){
                    	        f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+l[i+j+k][0]);
                    	    }
                   	    	if (j>0){
                            	f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+l[i+j+k][1]);
                        	}
                        	if (k>0){
                            	f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+l[i+j+k][2]);
                        	}
                    	}
                    	if (i+j+k==n){
                        	ans=max(ans,f[i][j][k]);
                    	}
                	}
            	}
        	}
        	cout<<ans<<'\n';
		}
        else{        	
        	int l[n+2][3]={};
        	for (int i=1;i<=n;i++){
            	cin>>l[i][0]>>l[i][1]>>l[i][2];
        	}
        	int ls[n+2];
        	for (int i=1;i<=n;i++){
        		ls[i]=l[i][0];
			}
			sort(ls+1,ls+n);
			int ans=0;
			for (int i=1;i<=n/2;i++){
				ans+=ls[i];
			}
			cout<<ans<<'\n';
		}
    }
    return 0;
}
