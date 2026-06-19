#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;

int T,n,m,l,vl;
bool flagin0=false,flaginlow0=false;
int d[MAXN]={};
int v[MAXN]={};
int a[MAXN]={};
int p[MAXN]={};
int fc[MAXN]={};
int lc[MAXN]={};
int cw[MAXN]={};
bool op[MAXN]={};
bool yxc[MAXN]={};

double e[MAXN]={};//the place it stops
bool t[MAXN]={};//wrong or not

int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n>>m>>l>>vl;
		flagin0=false; flaginlow0=false;
		for(int i=1;i<=n;i++) {
			yxc[i]=false;
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0) {
				flagin0=true;
			}
			if(a[i]<0) {
				flaginlow0=true;
			}
		}
		for(int i=1;i<=m;i++) {
			cin>>p[i];
		}
		if(!flagin0) {      //all of them are 0!
			int ljy=0,arist=m-1;
			for(int i=1;i<=n;i++) {
				if(v[i]>vl && d[i]<=p[m]) {
					ljy++;
				}
			}
			if(ljy==0) arist++;
			cout<<ljy<<" "<<arist<<endl;
			continue;
		}
		else if(!flaginlow0) {   //all of them are up 0!
			int ljy=0,arist=m-1;
			for(int i=1;i<=n;i++) {
				if(d[i]<=p[m]) {
					double tmp=v[i]*v[i]+2*a[i]*(p[m]-d[i]);
					tmp=sqrt(tmp);
					if(tmp>vl) {
						ljy++;
					}
				}
			}
			if(ljy==0) arist++;
			cout<<ljy<<" "<<arist<<endl;
			continue;
		}
		else {
			int ljy=0,arist=0;
			p[m+1]=l+1; p[0]=-1;
			for(int i=1;i<=n;i++) {
				if(a[i]>=0) e[i]=l;
				else if(a[i]<0) {
					e[i]=v[i]*v[i]*0.5/(-a[i])+d[i];
					if(e[i]>l) e[i]=l;
				}
			}
			for(int i=1;i<=n;i++) {
				if(d[i]<=p[m] && e[i]>=p[1]) {
					yxc[i]=true;
					for(int j=1;j<=m;j++) {
						if(p[j]>=d[i] && p[j-1]<d[i]) {
							fc[i]=j;
						}
						if(p[j]<=e[i] && p[j+1]>e[i]) {
							lc[i]=j;
						}
					}
					if(a[i]>=0) {
						double tmp=(p[lc[i]]-d[i])*a[i]*2+v[i]*v[i];
						tmp=sqrt(tmp);
						if(tmp>vl) {
							ljy++;
							t[i]=true;
						}
					}
					else if(a[i]<0) {
						double tmp=(p[fc[i]]-d[i])*a[i]*2+v[i]*v[i];
						tmp=sqrt(tmp);
						if(tmp>vl) {
							ljy++;
							t[i]=true;
						}
					}
				}
			}
			cout<<ljy<<" ";
			for(int i=1;i<=m;i++) {
				cw[i]=0;
				op[i]=false;
			}
			for(int i=1;i<=n;i++) {
				if(yxc[i]) {
					for(int j=fc[i];j<=lc[i];j++) {
						cw[j]++;
					}
				}
			}
			int lef=ljy; arist=m;
			while(lef>0) {
				int idx=0,lq=-1;
				for(int i=1;i<=m;i++) {
					if(!op[i] && cw[i]>lq) {
						lq=cw[i];
						idx=i;
					}
				}
				op[idx]=true; arist--;
				for(int i=1;i<=n;i++) {
					if(yxc[i] && t[i] && idx>=fc[i] && idx<=lc[i]) {
						t[i]=false; lef--;
						for(int j=fc[i];j<=lc[i];j++) {
							cw[j]--;
						}
					}
				}
			}
			cout<<arist<<endl;
		}
	}
	return 0;
}
