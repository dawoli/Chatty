#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][5],cnt[5];
struct stu{
	int s1,s2,s3,c,i1,i2,i3;
}e[N];
bool cmp(stu x,stu y){
	if(x.c!=y.c) return x.c>y.c;
	if(x.s1!=y.s1) return x.s1>y.s1;
	if(x.s2!=y.s2) return x.s2>y.s2;
	if(x.s3!=y.s3) return x.s3>y.s3;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t,n,ans=0;
	cin>>t;
	while(t--){
		cin>>n;
		memset(e,0,sizeof(e));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>e[i].s1) e[i].s1=a[i][j],e[i].i1=j;
				else if(a[i][j]>e[i].s2) e[i].s2=a[i][j],e[i].i2=j;
				else e[i].s3=a[i][j],e[i].i3=j;
			}
			e[i].c=e[i].s1-e[i].s2;
		}
		sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[e[i].i1]+1<=n/2){
				ans+=e[i].s1;
				cnt[e[i].i1]++;
			}
			else if(cnt[e[i].i2]+1<=n/2){
				ans+=e[i].s2;
				cnt[e[i].i2]++;
			}
			else if(cnt[e[i].i3]+1<=n/2){
				ans+=e[i].s3;
				cnt[e[i].i3]++;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}

