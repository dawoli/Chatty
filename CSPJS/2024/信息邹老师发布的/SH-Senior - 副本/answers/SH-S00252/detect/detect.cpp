#include<bits/stdc++.h>
#define qian first
#define hou second
using namespace std;
int dis1[100010];//[dis1,dis2]上若有监控就超速 
int dis2[100010];
int d[100010],v[100010],a[100010],p[100010];
pair<int,int> qujian[100010];
int cnt,ans,pos,tmp;
void init(){
//	memset(dis1,0,sizeof(dis1));
//	memset(dis2,0,sizeof(dis2));
//	memset(d,0,sizeof(d));
//	memset(v,0,sizeof(v));
//	memset(a,0,sizeof(a));
//	memset(p,0,sizeof(p));
	memset(qujian,0,sizeof(qujian));
	cnt=0;
	ans=0;
	pos=0;
	tmp=0;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,n,m,ll,vv;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d%d%d%d",&n,&m,&ll,&vv);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if(a[i]==0){
				if(v[i]>vv){
					dis1[i]=d[i];
					dis2[i]=ll;
				}
				if(v[i]<=vv){
					dis1[i]=ll+1;
					dis2[i]=-1;
				}
			}
			if(a[i]>0){
				if(v[i]>vv){
					dis1[i]=d[i];
					dis2[i]=ll;
				}
				if(v[i]<=vv){
					dis1[i]=d[i]+(vv*vv-v[i]*v[i])/(2.0*a[i])+1;
					dis2[i]=ll;
				}
			}
			if(a[i]<0){
				if(v[i]>vv){
					dis1[i]=d[i];
					dis2[i]=d[i]+ceil((vv*vv-v[i]*v[i])/(2.0*a[i])-1);
				}
				if(v[i]<=vv){
					dis1[i]=ll+1;
					dis2[i]=-1;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cin >> p[i]; 
		}
		for(int i=1;i<=n;i++){
			if(dis1[i]<=dis2[i]){
				int l=1,r=m,mid;
				while(l<r){
					mid=(l+r)/2;
					if(p[mid]<dis1[i]){
						l=mid+1;
					}
					else{
						r=mid;
					}
				}
				if(p[l]>=dis1[i]){
					qujian[i].qian=l;
				}
				l=1;
				r=m;
				while(l<r){
					mid=(l+r)/2+1;
					if(p[mid]>dis2[i]){
						r=mid-1;
					}
					else{
						l=mid;
					}
				}
				if(p[l]<=dis2[i]){
					qujian[i].hou=l;
				}
			}
			
			
			if(qujian[i].qian<=qujian[i].hou && qujian[i].qian!=0 && qujian[i].hou!=0){
				cnt++;
			}
			else{
				qujian[i].qian=0;
				qujian[i].hou=0;
			}
//			cout << qujian[i].qian << ' ' << qujian[i].hou << endl;
		}
		cout << cnt << ' ';
		sort(qujian+1,qujian+n+1);
		for(int i=n-cnt+1;i<=n;i++){
			if(qujian[i].qian<=pos){
				if(qujian[i].hou<pos){
					pos=qujian[i].hou;
				}
			}
			else{
				pos=qujian[i].hou; 
				tmp++;
			}
		}
		ans=m-tmp;
		
		cout << ans << endl;
	}

	return 0;
}

