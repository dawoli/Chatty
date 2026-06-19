#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9,M=N,LL=1e6+9,INF=1e9;
const double eps=1e-6;
int t,n,m,L,V,d[N],v[N],a[N],p[M];
int ans1,ans2;
int cntp[LL];
struct node{
	int l,r;
}b[N];
int cntb;
int R[N],f[N],mx[N];
bool cmp(node x,node y){//∞¥”“∂Àµ„≈≈ 
	return x.r<y.r||x.r==y.r&&x.l<y.l;
}
int sum(int l,int r){
	if(r>L) r=L;
	if(l<=0) return cntp[r];
	if(l>r) return 0;
	//cout<<"sum "<<l<<","<<r<<" "<<cntp[r]<<" "<<cntp[l-1]<<endl;
	return cntp[r]-cntp[l-1];
}
int find1(int x){//[x,L]◊Óøø◊Ûµƒ≤‚ÀŸ“«±‡∫≈ 
	int k=lower_bound(p+1,p+m+1,x)-p;
	//cout<<"find1 x="<<x<<" k="<<k<<" pk="<<p[k]<<endl;
	if(p[k]<x) return m;
	return k;
}
int find2(int x){//(x,L]◊Óøø◊Ûµƒ≤‚ÀŸ“«±‡∫≈ 
	int k=upper_bound(p+1,p+m+1,x)-p;
	if(p[k]<=x) return m;
	return k;
}
void init(){
	memset(cntp,0,sizeof(cntp));
	ans1=ans2=0;
	memset(b,0,sizeof(b));
	cntb=0;
	memset(R,0,sizeof(R));
	memset(f,0,sizeof(f));
	memset(mx,0,sizeof(mx));
}
int main(){
	ios::sync_with_stdio(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		init();
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=m;i++) cntp[p[i]]++;
		for(int i=1;i<=L;i++) cntp[i]+=cntp[i-1];
		//cout<<"cntp\n";
		//for(int i=0;i<=L;i++) cout<<cntp[i]<<" ";
		//cout<<endl;
		for(int i=1;i<=n;i++){
			//cout<<"car "<<i<<endl;
			int now=0;
			int cl=-1,cr=-1;
			if(a[i]==0){
				if(v[i]>V){//[d[i],L]
					now=sum(d[i],L);
					cl=find1(d[i]);
					cr=m;
				}
				else now=0;//¶µ
			}
			else if(a[i]>0){
				if(v[i]>V){//[d[i],L]
					now=sum(d[i],L);
					cl=find1(d[i]);
					cr=m;
				}
				else if(v[i]==V){//(d[i],L]
					now=sum(d[i]+1,L);
					cl=find2(d[i]);
					cr=m;
				}
				else{//(d[i]+x,l]
					double x=(V*V-v[i]*v[i])*1.0/(2.0*a[i]);
					int s=d[i]+ceil(x+eps);
					now=sum(s,L);
					cl=find1(s);
					cr=m;
				}
			}
			else if(a[i]<0){
				if(v[i]>V){//[d[i],d[i]+x)
					double x=(v[i]*v[i]-V*V)*1.0/(-2.0*a[i]);
					int s=d[i]+floor(x-eps);
					//cout<<d[i]<<" "<<x<<" "<<s<<endl;
					now=sum(d[i],s);
					cl=find1(d[i]);
					cr=find2(s)-1;
					if(d[i]+x>=L) cr=m;
				}
				else now=0;//¶µ
			}
			//cout<<"over speed "<<now<<endl;
			if(now>0){
				//cout<<"["<<cl<<","<<cr<<"]"<<endl;
				cntb++;
				b[cntb].l=cl;b[cntb].r=cr;
				ans1++;
			}
		}
		//cout<<"b:\n";
		//for(int i=1;i<=cntb;i++) cout<<b[i].l<<","<<b[i].r<<endl;//
		sort(b+1,b+cntb+1,cmp);
		//cout<<"b:\n";
		//for(int i=1;i<=cntb;i++) cout<<i<<":"<<b[i].l<<","<<b[i].r<<endl;//
		for(int i=1;i<=cntb;i++) R[i]=b[i].r;
		for(int i=1;i<=cntb;i++){
			int ll=b[i].l,rr=b[i].r;
			int k=lower_bound(R+1,R+cntb+1,ll)-R;
			k--;
			//cout<<k<<"("<<mx[k]<<")"<<"->"<<i<<endl;
			f[i]=mx[k]+1;
			mx[i]=max(mx[i-1],f[i]);
			ans2=max(ans2,f[i]);
		}
		//for(int i=1;i<=cntb;i++) cout<<f[i]<<" ";
		//cout<<endl;
		ans2=m-ans2;
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
