#include<bits/stdc++.h>
#define eps 1e-9
using namespace std;
typedef long double ld;
const int N=1e5+9;
const int INF=1e6+1;
int n,m,L,V;
bool dtb[N]; //
int d[N],v[N],a[N],l[N],r[N];
int pl[N],pr[N]; //从pl[x]~pr[x]号摄像头可以管辖x 
int p[N]; //p[k]=第k个摄像头的位置 
int target[N],nT;
bool ok[N];
ld speed(int x,int id) { //第x辆车在第id个摄像头地方的速度 
	if (p[id]<d[x]) return -1;
	if (a[x]==0) return v[x];
	int dis=p[id]-d[x];
	int v0=v[x],ax=a[x];
	ld delta=(ld)v0*v0+2.*dis*ax;
	if (abs(delta)<=eps) return 0;
	if (delta<0) return -2;
	return sqrt(delta);
}
pair<int,int> range(int x) { //第i辆车超速区间(分别向里收缩)，-1和1000001代表无穷，返回{-114,-514}表示不存在 
	if (a[x]==0) {
		if (v[x]>V) return make_pair(d[x],INF);
		else return make_pair(-1,INF);
	}
	int ax=a[x],v0=v[x],dx=d[x];
	if (ax>0) {
		if (v0>V) return make_pair(dx,INF);
		ld t=(ld)(V-v0)/ax;
		ld s=v0*t+0.5*ax*t*t;
		if (s+dx-L>eps) return make_pair(-1,INF);
		else {
			if (ceil(s)-s<=eps) return make_pair(ceil(s)+dx+1,INF);
			else return make_pair(ceil(s)+dx,INF);
		}
	}
	if (ax<0) {
		if (v0<=V) return make_pair(-1,INF);
		ld t=(ld)(V-v0)/ax;
		ld s=v0*t+0.5*ax*t*t;
		if (s+dx-L>eps) return make_pair(-1,INF);
		else {
			if (s-floor(s)<=eps) return make_pair(dx,floor(s)+dx-1);
			else return make_pair(dx,floor(s)+dx);
		}
	}
}
void get_range() {
	for (int i=1;i<=n;++i) {
		pair<int,int> pii=range(i);
		int xl=pii.first,xr=pii.second;
		l[i]=xl,r[i]=xr;
	}
}
void brush(int id) {
	int pid=p[id];
	for (int i=1;i<=nT;++i) {
		if (l[target[i]]<=pid&&pid<=r[target[i]])
			ok[i]=1;
	}
}
int cer;
int bkt[N];
void solve() {
	bool f=1;
	while (f) {
		f=0;
		memset(bkt,0,sizeof bkt);
		for (int i=1;i<=nT;++i) {
			if (!ok[i]) {
				for (int k=pl[i];k<=pr[i];++k)
					bkt[k]++,f=1;
			}
		}
		int pos=max_element(bkt+1,bkt+1+m)-bkt;
		cer++;
		brush(pos);
	} 
}
bool op1=1,op2=1,op3=1; 
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--) {
		nT=cer=0;
		memset(ok,0,sizeof ok);
		scanf("%d %d %d %d",&n,&m,&L,&V);
		op1=op2=op3=1;
		for (int i=1;i<=n;++i) {
			scanf("%d %d %d",&d[i],&v[i],&a[i]);
			if (a[i]!=0) op1=0;
			if (a[i]<=0) op2=0;
			if (a[i]>=0) op3=0; 
		}
		for (int i=1;i<=m;++i)
			scanf("%d",&p[i]);
//		for (int i=1;i<=n;++i) {//
//			cout<<"Car "<<i<<" : \n";//
//			for (int j=1;j<=m;++j)//
//				cout<<fixed<<setprecision(2)<<speed(i,j)<<" ";//
//			cout<<endl;//
//			cout<<"   Overspeed range: ["<<range(i).first<<" , "<<range(i).second<<"]\n";
//		}//
		int count=0;
		for (int i=1;i<=n;++i) {
			int pre=count;
			int ax=a[i],v0=v[i],dx=d[i];
			if (ax==0) count+=(v0>V);
			if (ax>0) count+=(speed(i,m)-V>eps);
			if (ax<0) {
				int pos=lower_bound(p+1,p+1+m,dx)-p;
				count+=(speed(i,pos)-V>eps);
			}
			if (pre!=count) {
//				cout<<"Overspeed: Car "<<i<<" . \n";//
				target[++nT]=i; 
			}
		}
		printf("%d ",count);
		if (op1||op2) { //a[i]=0
			printf("%d\n",count==0?m:m-1);
			continue;
		}
		else {
			get_range();
			//接下来的操作针对nT个数，分别原编号是target[i]
			for (int i=1;i<=nT;++i) {
				if (l[target[i]]==-1) pl[i]=1;
				else pl[i]=lower_bound(p+1,p+1+m,l[target[i]])-p;
				if (r[target[i]]==INF) pr[i]=m;
				else {
					int tl=1,tr=m;
					for (int kk=1;kk<=30;++kk) {
						int mid=(tl+tr)/2;
						if (p[mid]<=r[target[i]]) tl=mid;
						else tr=mid-1;
					}
					pr[i]=tl;
				}
	//			cout<<"Car "<<target[i]<<" : "<<pl[i]<<" "<<pr[i]<<" .\n";//
				if (pl[i]==pr[i]) brush(pl[i]),cer++;
			}
			solve();
			printf("%d\n",m-cer+1);
		} 
	}
	
}
