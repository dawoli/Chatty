#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
struct node{
	long long w,max,ct;
}p[maxn];
long long T,n,a[maxn][5],w[maxn],flag=0,cnt[5]={0},ans=0;
void cp(long long x){
	long long tmax=-1,tmin=100005,xmax,xmin,tmid=0;
	for(long long i=1;i<=3;i++){
		tmid+=a[x][i];
		if(a[x][i]>tmax){
			tmax=a[x][i];
			xmax=i;
		}
		if(a[x][i]<tmin){
			tmin=a[x][i];
			xmin=i;
		}
	}
	tmid-=tmax+tmin;
	p[x].max=xmax;
	p[x].ct=tmax;
	p[x].w=tmax-tmid;
}
bool cmp(node u,node v){
	return u.w>v.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		flag=ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
				cin>>a[i][j];
				cp(i);
			}
		}
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(p[i].max!=flag){
				ans+=p[i].ct;
				cnt[p[i].max]++;
				if(cnt[p[i].max]*2==n){
					flag=p[i].max;
				}
			}
			else{
				ans+=p[i].ct-p[i].w;
			}
		}
		cout<<ans<<endl;
	}
}
