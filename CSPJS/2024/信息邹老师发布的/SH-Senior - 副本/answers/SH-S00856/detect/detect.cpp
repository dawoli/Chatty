#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V;
int d[100050],v[100050],a[100050];
int p[100050];
int ansa,ansb;
bool vis[100050];
//bool ce[100050][100050];
int xx[100050],yy[100050];
int cnt;
int cee[100050];
void chu(){
	memset(d,0,sizeof(d));
	memset(v,0,sizeof(v));
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	memset(vis,0,sizeof(vis));
	n=0,m=0,L=0,V=0,ansa=0,ansb=0;
}
int sqr(int a){
	int ll=0,rr=50000,mid;
	while(ll!=rr){
		mid=(ll+rr)/2;
		if(a<mid*mid)rr=mid;
		else if(a>=mid*mid)ll=mid+1;
	}
	return ll;
}
void panguoa(int i){
	++cnt;
	int x=lower_bound(p+1,p+1+m,d[i])-p, y=p[m];
	//ce[x][y]=1;
	xx[cnt]=x;
	yy[cnt]=y;
}
void panguob(int i){//a<0
	++cnt;
	int sss;
	sss=(v[i]*v[i])/(2*a[i]);
	int x=lower_bound(p+1,p+1+m,d[i])-p, y=lower_bound(p+1,p+1+m,d[i]+sss)-p;
	//ce[x][y]=1;
	xx[cnt]=x;
	yy[cnt]=y;
}
void panguoc(int i){
	++cnt;
	int sss;
	sss=(V*V-v[i]*v[i])/(2*a[i]);
	int x=lower_bound(p+1,p+1+m,d[i]+sss)-p, y=p[m];
	//ce[x][y]=1;
	xx[cnt]=x;
	yy[cnt]=y;
}
bool pana(int i){
	return sqr((p[lower_bound(p+1,p+1+m,d[i])-p]-d[i])*2*a[i]+v[i]*v[i])>V;
}
int vmax(int i){
	return sqr(v[i]*v[i]+2*a[i]*(p[m]-d[i]));
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		chu();
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;++i){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;++i){
			cin>>p[i];
		}
		for(int i=1;i<=n;++i){
			if(a[i]=0){
				if(d[i]>p[m])continue;
				else if(v[i]>V){
					++ansa;
					panguoa(i);
					//if(vis[lower_bound(p+1,p+1+m,d[i])-p]=1){continue;}
					//else {vis[lower_bound(p+1,p+1+m,d[i])-p]=1,++ansb;}
			}
		}
			else if(a[i]<0){
				if(d[i]>p[m])continue;
				else if(pana(i)){
					++ansa;
					panguob(i);
					//if(vis[lower_bound(p+1,p+1+m,d[i])-p]=1){continue;}
					//else {vis[lower_bound(p+1,p+1+m,d[i])-p]=1,++ansb;}
				}
			}
			else if(a[i]>0){
				if(d[i]>p[m])continue;
				else if(vmax(i)>V){
					++ansa;
					panguoc(i);
				}
			}
		}
		ansb=1;
		for(int i=2;i<=cnt;++i){
			if((xx[i]<=yy[i-1]&&xx[i]>=xx[i-1])||(yy[i]<=yy[i-1]&&yy[i]>=xx[i-1]))continue;
			else ++ansb;
		}
	cout<<ansa<<' ';
	if(ansb==0)cout<<"1";
	else cout<<ansb;
	}
	return 0;
}
