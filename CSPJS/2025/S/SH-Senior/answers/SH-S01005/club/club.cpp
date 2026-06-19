#include<bits/stdc++.h>
using namespace std;
int n,t,a[100010],b[100010],c[100010],ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out"."w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n<=15){
			long long x=1,r=1;
			for(int i=1;i<=n;i++){
				r*=3;
			}
			while(x<r){
				int cnt=0,g=0,sum=x,step[10]={0,0,0,0,0,0,0,0},s,aa=0,bb=0,cc=0;
				while(sum){
					step[g]=sum%3;
					sum/=3;
					g++;
				}
				for(int i=1;i<=n;i++){
					s=step[n-i];
					if(s==0){
						aa++;
						cnt+=a[i];
					}
					if(s==1){
						bb++;
						cnt+=b[i];
					}
					if(s==2){
						cc++;
						cnt+=c[i];
					}
					if(aa>n/2||bb>n/2||cc>n/2){
						cnt=0;
						break;
					}
				}
				ans=max(ans,cnt);
				x++;
			}
			cout<<ans<<'\n';
		}
		else{
			sort(a+1,a+1+n);
			for(int i=0;i<n/2;i++){
				ans+=n-i;
			}
			cout<<ans;
		}
	}
	return 0;
}
