#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll t,n;
ll a[N][4];
ll b[N][4];
ll cnt[4];
ll c[N];
ll ans,cct;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		n=0;
		cin>>n;
		memset(cnt,0,sizeof cnt);
		memset(c,0,sizeof c);
		ans=0;
		cct=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				b[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2] && a[i][2]>=a[i][3]){
				b[i][1]=1;
				b[i][2]=2;
				b[i][3]=3;
			}
			else if(a[i][1]>=a[i][3] && a[i][3]>=a[i][2]){
				b[i][1]=1;
				b[i][2]=3;
				b[i][3]=2;
			}
			else if(a[i][2]>=a[i][3] && a[i][3]>=a[i][1]){
				b[i][1]=2;
				b[i][2]=3;
				b[i][3]=1;
			}
			else if(a[i][2]>=a[i][1] && a[i][1]>=a[i][3]){
				b[i][1]=2;
				b[i][2]=1;
				b[i][3]=3;
			}
			else if(a[i][3]>=a[i][2] && a[i][2]>=a[i][1]){
				b[i][1]=3;
				b[i][2]=2;
				b[i][3]=1;
			}
			else if(a[i][3]>=a[i][1] && a[i][1]>=a[i][2]){
				b[i][1]=3;
				b[i][2]=1;
				b[i][3]=2;
			}
			sort(a[i]+1,a[i]+4,cmp);
		}
		for(int i=1;i<=n;i++){
			cnt[b[i][1]]++;
			ans+=a[i][1];
		}
		if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2){
			cout<<ans<<endl;
		}
		else{
			int q=0;
			if(cnt[1]>n/2){
				q=1;
			}
			else if(cnt[2]>n/2){
				q=2;
			}
			else if(cnt[3]>n/2){
				q=3;
			}
			for(int i=1;i<=n;i++){
				if(b[i][1]==q){
					c[++cct]=a[i][1]-a[i][2];
				}
			}
			sort(c+1,c+cct+1);
			for(int i=1;i<=cnt[q]-(n/2);i++){
				ans-=c[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
