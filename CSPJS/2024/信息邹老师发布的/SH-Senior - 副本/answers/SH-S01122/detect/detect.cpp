#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1317;
int T,n,m,L,V;
int l,r,mid;
int a[N],d[N],v[N];
int b[N];
int l1[N],r1[N],cnt1;
long double tt=0;
bool out[N];
struct dat{
	int x,y;
	bool o;
}q2[N];
bool cmp(dat xx,dat yy){
	if(xx.x!=yy.x)
	return xx.x<yy.x;
	return xx.y<yy.y;
}
bool sp(int i,int x){
	return V*V<v[i]*v[i]+2*a[i]*(x-d[i]);
}
void get(int i){
	if(a[i]>0){
		l=1,r=m;
		while(l<=r){
			mid=(l+r)>>1;
			if(b[mid]>=d[i]&&sp(i,b[mid])){
				l1[i]=mid;
				out[i]=1;
				r=mid-1;
			}
			else l=mid+1;
		}
		r1[i]=m;
	}
	else if(a[i]==0){
		if(v[i]<=V) return ;
		l=1,r=m;
		while(l<=r){
			mid=(l+r)>>1;
			if(b[mid]>=d[i]){
				l1[i]=mid;
				out[i]=1;
				r=mid-1;
			}
			else l=mid+1;
		}
		r1[i]=m;
	}
	else{
		l=1,r=m;
		while(l<=r){
			mid=(l+r)>>1;
			if(b[mid]>=d[i]) l1[i]=mid,r=mid-1;
			else l=mid+1;
		}
		if(!sp(i,b[l1[i]]))return ;
		l=l1[i],r=m;
		while(l<=r){
			mid=(l+r)>>1;
			if(b[mid]>=d[i]&&sp(i,b[mid])){
				r1[i]=mid;
				out[i]=1;
				l=mid+1;
			}
			else r=mid-1;
		}
	}
	if(out[i]){
		cnt1++;
	}
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cnt1=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			out[i]=0;
			l1[i]=-1,r1[i]=-1;
		}
		for(int i=1;i<=m;i++) cin>>b[i];
		for(int i=1;i<=n;i++){
			if(d[i]>b[m]) continue;
			get(i);
		}
		cout<<cnt1<<" ";
		for(int i=1;i<=n;i++){
			if(out[i]==0) q2[i].x=-1317,q2[i].y=-1317;
			else q2[i].x=l1[i],q2[i].y=r1[i],q2[i].o=out[i];
		}
		for(int i=1;i<=13;i++)q2[n+i].o=0,q2[n+i].x=-1,q2[n+i].y=-1;
		sort(q2+1,q2+n+1,cmp);
		int tot=0,cnt2=0,qx=0,qy=0;
		for(int i=1;i<=n;i=tot+1){
			tot=i;
			if(q2[i].x==-1317){
				tot=i;
				continue;
			}
			cnt2++;
			qx=q2[i].x,qy=q2[i].y;
			while(tot<n&&q2[tot+1].x<=qy&&q2[tot+1].y>=qx){
				tot++;
				qy=min(q2[tot].y,qy);
				qx=max(q2[tot].x,qx);
			}
		}
		cout<<m-cnt2<<endl;
	}
	return 0;
}
/*
我永远喜欢珂朵莉
2024-S-T2
神题，麻烦死人
过了大样例
希望AC
+100？ 
*/ 
