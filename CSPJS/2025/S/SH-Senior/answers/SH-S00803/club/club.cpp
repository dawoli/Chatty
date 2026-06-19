#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,maax,miin,miid,hn,nth,cnt,a[100003][4],b[4];
long long z[100003][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		hn=n/2;
		for(i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maax=max(max(a[i][1],a[i][2]),a[i][3]);
			miin=min(min(a[i][1],a[i][2]),a[i][3]);
			miid=a[i][1]+a[i][2]+a[i][3]-maax-miid;
			if(maax==a[i][1]){
				z[i][0]=10*i+1;
				z[i][1]=10000000*a[i][1];
			}
			else if(maax==a[i][2]){
				z[i][0]=10*i+2;
				z[i][1]=10000000*a[i][2];
			}
			else{
				z[i][0]=10*i+3;
				z[i][1]=10000000*a[i][3];
			}
			z[i][1]=10000000000*maax+100000*miid+miin;
			//cout<<z[i]<<"	";
		}
		//sort(z+1,z+n+1);
		for(i=n,b[1]=0,b[2]=0,b[3]=0;i>0;i--){
			nth=z[i][0]%10;
			j=z[i][0]/10;
			if(b[nth]<hn){
				;
			}
			else{
				if(nth==1){
					if(a[j][nth+1]>=a[j][nth+2]){
						nth++;
					}
					else{
						nth+=2;
					}
				}
				else if(nth==2){
					if(a[j][nth-1]>=a[j][nth+1]) nth--;
					else nth++;
				}
				else{
					if(a[j][nth-2]>=a[j][nth-1]){
						nth-=2;
					}
					else{
						nth--;
					}
				}
				z[i][1]=a[j][nth]*10000000000;
			}
			b[nth]++;
			//cout<<z[i]<<endl;
			//cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
		}
		for(i=1,cnt=0;i<=n;i++){
			cnt+=(z[i][1]/10000000000);
			cout<<(z[i][1]/10000000000)<<' ';
		}
		cout<<cnt<<endl;
	}
	return 0;
}
