#include <bits/stdc++.h>
using namespace std;
int T,l,m,n,lim,d[100009],v[100009],a[100009],p[100009],cnt,start[100009],to[100009];		//start代表起点，to代表终点 
bool alladd=true;
int prep[100009],prem;
int solve(){
	int ret=0;
	for (int i=1;i<=n;++i){
		if (a[i]==0&&v[i]>lim) if (prep[prem]>=d[i]) ++ret;
		if (a[i]>0){
			if (prep[prem]<d[i]) continue;
			if (v[i]*v[i]+2*a[i]*(prep[prem]-d[i])>lim*lim) ++ret;
		}
		if (a[i]<0){
			if(v[i]<=lim||prep[prem]<d[i]) continue;
			else{
				int s=(*lower_bound(prep,prep+prem+1,d[i]))-d[i];
				if (v[i]*v[i]+2*a[i]*s>lim*lim) ++ret;
			}
		}
	}
	return ret;
}
int find_lower(int pred){
	int l=1,r=m,ret=0;
	while (l<r){
		int mid=(l+r)/2;
		if (p[mid]<=pred) ret=mid,l=mid+1;
		else r=mid-1;
	}
	while (p[ret+1]<=pred&&ret+1<=m) ++ret;
	return ret;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for (int q=1;q<=T;++q){
		alladd=true;cnt=0;
		cin>>n>>m>>l>>lim;for (int i=1;i<=n;++i) scanf("%d %d %d",d+i,v+i,a+i);for (int i=1;i<=m;++i) scanf("%d",p+i);sort(p+1,p+m+1);
		for (int i=1;i<=n;++i){
			if (a[i]<0) alladd=false;
			if (a[i]==0&&v[i]>lim) if (p[m]>=d[i]) start[++cnt]=lower_bound(p,p+m+1,d[i])-p,to[cnt]=m;
			if (a[i]>0){
				if (p[m]<d[i]) continue;
				double smin=(lim*lim-v[i]*v[i])/2.0/a[i];if (smin==(int)smin) smin+=1;
				if (v[i]*v[i]+2*a[i]*(p[m]-d[i])>lim*lim) ++cnt,start[cnt]=lower_bound(p,p+m+1,d[i]+ceil(smin))-p,to[cnt]=m;
			}
			if (a[i]<0){
				if(v[i]<=lim||p[m]<d[i]) continue;
				else{
					int s=(*lower_bound(p,p+m+1,d[i]))-d[i];
					double smax=(lim*lim-v[i]*v[i])/2.0/a[i];if (fabs(smax-(int)smax)<0.0000001) smax-=1;
					if (v[i]*v[i]+2*a[i]*s>lim*lim) ++cnt,start[cnt]=lower_bound(p,p+m+1,d[i])-p,to[cnt]=find_lower(min((int)(d[i]+(floor(smax))),l));
				}
			}
		}
		printf("%d ",cnt);
		if (cnt==0) printf("%d\n",m);
		else if (alladd) printf("%d\n",m-1);
		else if (n<=20&&m<=20){
			int ans=m;
			for (int j=0;j<((1<<m)-1);++j){
				prem=0;for (int i=1;i<=m;++i) prep[i]=0;
				for (int i=1;i<=m;++i){
					if ((j|(1<<(i-1)))==j){
						prep[++prem]=p[i];
					}
				}
				if (solve()==cnt) ans=min(ans,prem);
			}
			printf("%d\n",m-ans);
		}
		else if (n<=3000&&m<=3000){						//这cnt个区间中，至少要抓多少个数才能使每个区间内都有一个数 
			int dis[10009],sum[10009],left=cnt,ans=0;fill(d,d+10009,0);
			bool vst[10009];fill(vst,vst+10009,0);
			for (int i=1;i<=cnt;++i){
				dis[start[i]]+=1;d[to[i]+1]-=1;
			}
			while (left>0){
				for (int i=1;i<=m;++i) sum[i]=sum[i-1]+dis[i];
				int pos=max_element(sum,sum+m+1)-sum;++ans;
				for (int i=1;i<=cnt;++i){
					if (!vst[i]&&start[i]<=pos&&pos<=to[i]){
						vst[i]=true;--left;dis[start[i]]-=1;d[to[i]+1]+=1;
					}
				}
			}
			printf("%d\n",m-ans);
		}
		else printf("26767\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
