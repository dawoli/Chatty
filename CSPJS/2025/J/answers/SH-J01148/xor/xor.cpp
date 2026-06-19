#include<bits/stdc++.h>
using namespace std;
long long a[2000005],b[2000005],c[2000005],ans=-2000000;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++){
		if(a[i]==0){
			b[i]++;
			c[i]=c[i-1];
		}
		else if(a[i]==1){
			c[i]++;
			b[i]=b[i-1];
		}
	}
	if(k==1){
		for(long long l=1;l<=n;l++){
			for(long long r=l+1;r<=n;r++){
				long long ls=b[r]-b[l]+1;
				long long ys=c[r]-c[l]+1;
				bool ll=0,yy=0;
				if(ls%2==0){
					ll=0;
				}
				else if(ls%2==1){
					ll=1;
				}
				if(ys%2==0){
					yy=0;
				}
				else if(ys%2==1){
					yy=1;
				}
				if(ll!=yy){
					ans=max(ans,r-l+1);
				}
			}
		}
	}
	else{
		for(long long l=1;l<=n;l++){
			for(long long r=l+1;r<=n;r++){
				long long ls=b[r]-b[l]+1;
				long long ys=c[r]-c[l]+1;
				bool ll=0,yy=0;
				if(ls%2==0){
					ll=0;
				}
				else if(ls%2==1){
					ll=1;
				}
				if(ys%2==0){
					yy=0;
				}
				else if(ys%2==1){
					yy=1;
				}
				if(ll==yy){
					ans=max(ans,r-l+1);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
