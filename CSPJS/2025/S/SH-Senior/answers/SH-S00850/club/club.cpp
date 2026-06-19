#include<bits/stdc++.h>
#define N 100005
#define INF 2e9
using namespace std;
int n,a[N][4],T,d[N],ans=0,cnt[4],x[N];
inline int max3num(int a,int b,int c){
	if(a>=b&&a>=c) return 1;
	else if(b>=a&&b>=c) return 2;
	else return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int mx=max3num(a[i][1],a[i][2],a[i][3]);
			ans+=a[i][mx];
			cnt[mx]++;
			d[i]=a[i][mx]-max(a[i][mx%3+1],a[i][(mx+1)%3+1]);
		}
		int k=max3num(cnt[1],cnt[2],cnt[3]);
		int dd=cnt[k]-n/2;
		if(dd>0){
			int l=1,r=0,res=0,mid,tot;
			for(int i=1;i<=n;i++){
				if(max3num(a[i][1],a[i][2],a[i][3])==k){
					x[l]=d[i];
					r=max(r,x[l]);
					l++;
				}
			}
			l=0;
			while(l<=r){
				mid=(l+r)/2;
				tot=0;
				for(int i=1;i<=cnt[k];i++){
					if(mid>=x[i]) tot++;
				}
				if(tot>=dd){
					r=mid-1;
					res=mid;
				}
				else{
					l=mid+1;
				}
			}
			for(int i=1;i<=cnt[k];i++){
				if(x[i]<=res) ans-=x[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

