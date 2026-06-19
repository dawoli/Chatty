#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MN=100005;

int t,n;
struct cei{
	int a1,a2,a3;
	int now,dif;
	int deg;
} x[MN];
int sum1,sum2,sum3;
bool cmp(const cei &a,const cei &b) {
	return a.dif<b.dif; 
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	 
	scanf("%lld",&t);
	while(t--) {
		sum1=sum2=sum3=0;
		memset(x,0,sizeof x);
		scanf("%lld",&n);
		for(int i=1;i<=n;++i) {
			scanf("%lld%lld%lld",
				&x[i].a1,&x[i].a2,&x[i].a3);
			int tmpa=max(x[i].a1,max(x[i].a2,x[i].a3));
			if(tmpa==x[i].a1) {
				x[i].now=1, sum1++;	
				x[i].dif=tmpa-max(x[i].a2,x[i].a3);
			}
			else if(tmpa==x[i].a2) {
				x[i].now=2, sum2++;
				x[i].dif=tmpa-max(x[i].a1,x[i].a3);
			}
			else if(tmpa==x[i].a3) {
				x[i].now=3, sum3++;
				x[i].dif=tmpa-max(x[i].a1,x[i].a2);	
			}
			x[i].deg=tmpa;
		}
		sort(x+1,x+n+1,cmp);
		if(sum1>(n/2)) {
			int rst=sum1-(n/2);
			for(int i=1;i<=n;++i) {
				if(rst==0) break;
				if(x[i].now==1) {
					x[i].deg-=x[i].dif;
					rst--;
				}
			}
		}
		else if(sum2>(n/2)) {
			int rst=sum2-(n/2);
			for(int i=1;i<=n;++i) {
				if(rst==0) break;
				if(x[i].now==2) {
					x[i].deg-=x[i].dif;
					rst--;
				}
			}
		}
		else if(sum3>(n/2)) {
			int rst=sum3-(n/2);
			for(int i=1;i<=n;++i) {
				if(rst==0) break;
				if(x[i].now==3) {
					x[i].deg-=x[i].dif;
					rst--;
				}
			}
		}
		int ans=0;
//		cout<<sum1<<" "<<sum2<<" "<<sum3<<endl;
		for(int i=1;i<=n;++i) {
//			cout<<x[i].now<<" "<<x[i].dif<<" "<<x[i].deg<<" "<<x[i].a1<<" "<<x[i].a2<<" "<<x[i].a3<<endl; 
			ans+=x[i].deg;
		}
		printf("%lld\n",ans);
	}  
	
	return 0;
} 
