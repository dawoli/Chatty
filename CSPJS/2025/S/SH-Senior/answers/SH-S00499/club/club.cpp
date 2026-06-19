#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],n,ans,d1,d2,d3,dis[100005],T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		d1=0;
		d2=0;
		d3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			d1+=a[i];
			d2+=b[i];
			d3+=c[i];
		}
		if(d1>=d2&&d1>=d3){
			ans=d1;
			for(int i=1;i<=n;i++){
				dis[i]=max(c[i]-a[i],b[i]-a[i]);
			}
			sort(dis+1,dis+1+n);
			for(int i=n;i>=1;i--){
				if(dis[i]<0&&i<=n/2)break;
				//cout<<dis[i]<<" ";
				ans+=dis[i];
			}
		}
		else if(d2>=d1&&d2>=d3){
			ans=d2;
			for(int i=1;i<=n;i++){
				dis[i]=max(c[i]-b[i],a[i]-b[i]);
			}
			sort(dis+1,dis+1+n);
			for(int i=n;i>=1;i--){
				if(dis[i]<0&&i<=n/2)break;
				//cout<<dis[i]<<" ";
				ans+=dis[i];
			}
		}
		else{
			ans=d3;
			for(int i=1;i<=n;i++){
				dis[i]=max(b[i]-c[i],a[i]-c[i]);
			}
			sort(dis+1,dis+1+n);
			for(int i=n;i>=1;i--){
				if(dis[i]<0&&i<=n/2)break;
				//cout<<dis[i]<<" ";
				ans+=dis[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
