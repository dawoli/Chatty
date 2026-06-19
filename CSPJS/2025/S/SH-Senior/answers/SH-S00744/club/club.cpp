#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,T,a[maxn][3],cnt[3],maxpr,maxk,maxp,ans=0;
int delta[maxn],maxx;bool is[3];
inline int zero(int x){
	return x==0? 0x7fffffff:x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	memset(delta,0x7fffffff,sizeof(delta));
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>n;ans=0;cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			maxx=max(max(a[i][0],a[i][1]),a[i][2]);
			ans+=maxx;
			for(int j=0;j<3;j++){
				is[j]=(maxx==a[i][j]);
			}
			maxk=0x7fffffff;
			for(int j=0;j<3;j++){
				if(is[j]&&cnt[j]<maxk){
					maxp=j;
					maxk=cnt[j];
				}
			}
			cnt[maxp]++;
		}
		maxk=-1;
		for(int i=0;i<3;i++){
			if(cnt[i]>maxk){
				maxpr=i;
				maxk=cnt[i];
			}
		}
//		for(int i=0;i<n;i++){
//			cout<<delta[i]<<endl;
//		}
		if(cnt[maxpr]<=n/2) cout<<ans<<endl;
		else{
			for(int i=0;i<n;i++){
				delta[i]=0x7fffffff;
				if(a[i][maxpr]<a[i][0]) continue;
				if(a[i][maxpr]<a[i][1]) continue;
				if(a[i][maxpr]<a[i][2]) continue;
				if(a[i][maxpr]>a[i][0]){
					delta[i]=min(delta[i],a[i][maxpr]-a[i][0]);
				}
				if(a[i][maxpr]>a[i][1]){
					delta[i]=min(delta[i],a[i][maxpr]-a[i][1]);
				}
				if(a[i][maxpr]>a[i][2]){
					delta[i]=min(delta[i],a[i][maxpr]-a[i][2]);
				}
			}
			sort(delta,delta+n);
			for(int i=0;i<cnt[maxpr]-n/2;i++){
				ans-=delta[i];
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
