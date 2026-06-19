#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],t,n,admax[100005],bdmax[100005],cdmax[100005],adcnt=0,bdcnt=0,cdcnt=0,cy[100005];
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		ans=0;
		adcnt=0;
		bdcnt=0;
		cdcnt=0;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			
			if(a[i]>b[i]&&a[i]>c[i]){
				cy[i]=min(a[i]-b[i],a[i]-c[i]);
				
				adcnt++;
				admax[adcnt]=i;
				ans+=(long long)a[i];
			}
			else if(b[i]>c[i]&&b[i]>=a[i]){
				cy[i]=min(b[i]-c[i],b[i]-a[i]);
				
				bdcnt++;
				bdmax[bdcnt]=i;
				ans+=(long long)b[i];
			}
			else{
				cy[i]=min(c[i]-a[i],c[i]-b[i]);
				
				cdcnt++;
				cdmax[cdcnt]=i;
				ans+=(long long)c[i];
			}
			
		}
		if(adcnt>n/2){
			
			int h=adcnt-n/2;
			
			while(h--){
				int minn=1e9,minnumber=0;
				for(int j=1;j<=adcnt;j++){
					if(cy[admax[j]]<minn){
						minn=cy[admax[j]];
						minnumber=admax[j];
					}
				}
				cy[minnumber]=1e9;
				ans-=(long long)minn;
			}
		}
		else if(bdcnt>n/2){
			int h=bdcnt-n/2;
			
			while(h--){
				int minn=1e9,minnumber=0;
				for(int j=1;j<=bdcnt;j++){
					if(cy[bdmax[j]]<minn){
						minn=cy[bdmax[j]];
						minnumber=bdmax[j];   
					}
				}
				cy[minnumber]=1e9;
				ans-=(long long)minn;
			}
		}
		else if(cdcnt>n/2){
			int h=cdcnt-n/2;
			
			while(h--){
				int minn=1e9,minnumber=0;
				for(int j=1;j<=cdcnt;j++){
					if(cy[cdmax[j]]<minn){
						minn=cy[cdmax[j]];
						minnumber=cdmax[j];
					}
				}
				cy[minnumber]=1e9;
				ans-=(long long)minn;
			}
		}   
		cout<<ans<<"\n";
	}
	
	return 0;
} 
