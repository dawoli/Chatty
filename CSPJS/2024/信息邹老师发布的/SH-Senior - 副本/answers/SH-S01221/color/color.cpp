#include<bits/stdc++.h>
using namespace std; 
long long int t,n,a[255555],dp[255555],ans,ra[255555],to[255555],ct[1255555],lh,cnt,ms;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
	    cin>>n;
	    lh=cnt=ans=ms=0;
	    memset(dp,0,sizeof(dp));
	    memset(a,0,sizeof(a));
	    memset(ct,0,sizeof(ct));
	    memset(to,0,sizeof(to));
	    memset(ra,0,sizeof(ra));
		for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2&&a[i]==a[i-1]){cnt+=a[i],ms++;continue;}
		to[i-ms]=ct[a[i]];
		ct[a[i]]=i-ms;
		lh++;
		ra[i-ms]=a[i];	
		}
		for(int i=1;i<=lh;i++){
			if(to[i]!=0){
				dp[i]=ra[i]+dp[to[i]+1];
			}
		dp[i]=max(dp[i],dp[i-1]);
		ans=max(ans,dp[i]);
		}
		cout<<ans+cnt<<endl;
	}
    return 0;
}
