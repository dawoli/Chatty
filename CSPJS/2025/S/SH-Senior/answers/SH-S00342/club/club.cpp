#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long ans,t,n,a[N][5],x[5],flag[N][5],maxn,lss,lsi,minn;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0; 
		maxn=-1;
		minn=1e6;
		for(int i=1;i<=n;i++){
			x[i]=0;
			flag[i][1]=0;
			flag[i][2]=0;
			flag[i][3]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maxn=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=maxn;
			if(maxn==a[i][1]){
				x[1]++;
				continue;
			}
			if(maxn==a[i][2]){
				x[2]++;
				continue;
			}
			if(maxn==a[i][3]){
				x[3]++;
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			if(x[1]>(n/2)){
				for(int i=1;i<=n;i++){
					if(minn>min(a[i][1]-a[i][2],a[i][1]-a[i][3]) && flag[i][1]!=1){
						lsi=i;//临时的i
						if(a[i][1]-a[i][2]<=a[i][1]-a[i][3]){
							lss=2;
							flag[lsi][lss]=1;
							minn=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
							continue;
						}
						if(a[i][1]-a[i][3]<=a[i][1]-a[i][2]){
							lss=3;
							flag[lsi][lss]=1;
							minn=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
							continue;
						}
					}
					minn=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				}
				x[1]--;
				x[lss]++;
				ans-=(a[i][1]-a[lsi][lss]);
			}
			if(x[2]>(n/2)){
				for(int i=1;i<=n;i++){
					if(minn>min(a[i][2]-a[i][1],a[i][2]-a[i][3]) && flag[i][2]!=1){
						lsi=i;//临时的i
						if(a[i][2]-a[i][1]<=a[i][2]-a[i][3]){ 
							lss=1;
							flag[i][2]=1;
							minn=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
							continue;
						}
						if(a[i][2]-a[i][3]<=a[i][2]-a[i][1]){
							lss=3;
							flag[i][2]=1;
							minn=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
							continue;
						}
					}
					minn=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				}
				x[2]--;
				x[lss]++;
				ans-=(a[i][2]-a[lsi][lss]);
			}
			if(x[3]>(n/2)){
				for(int i=1;i<=n;i++){
					if(minn>min(a[i][3]-a[i][2],a[i][1]-a[i][1]) && flag[i][3]!=1){
						lsi=i;//临时的i
						if(a[i][3]-a[i][2]<=a[i][3]-a[i][1]){
							lss=2;
							flag[i][3]=1;
							minn=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
							continue;
						}
						if(a[i][3]-a[i][1]<=a[i][3]-a[i][2]){
							lss=1;
							flag[i][3]=1;
							minn=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
							continue;
						}
					}
					minn=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
				}
				x[3]--;
				x[lss]++;
				ans-=(a[i][3]-a[lsi][lss]);
			}
		}
		cout<<ans<<endl;
	}
}
