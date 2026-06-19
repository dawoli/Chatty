#include<bits/stdc++.h>
using namespace std;
const int N=100009;
const long double ERR=1e-4;
const long double ER=1e-6;
int T,n,m,L,V,p[N],acnt;
bool ov[N];
struct car{
	int d,v,a;
	long double l,r;
	int fdl,fdr;
}c[N],a[N];
bool cmp(const car&x,const car&y){
	return x.fdl<y.fdl||(x.fdl==y.fdl&&x.fdr<y.fdr); 
}
void init(){
	for(int i=1;i<=n;i++){
		if(c[i].a>0){
			if(c[i].v>V) c[i].l=c[i].d,c[i].r=L;
			else if(c[i].v==V) c[i].l=c[i].d+ERR,c[i].r=L;
			else{
				long double dis=(V*V-c[i].v*c[i].v)/(2*c[i].a+0.0);
				if(c[i].d+dis>L) c[i].l=c[i].r=L+ERR;
				else c[i].l=c[i].d+dis+ERR,c[i].r=L; 
			}
		}else if(c[i].a==0){
			if(c[i].v>V) c[i].l=c[i].d,c[i].r=L;
			else c[i].l=c[i].r=L+ERR;
		}else{
			if(c[i].v<=V) c[i].l=c[i].r=L+ERR;
			else{
				long double dis=(V*V-c[i].v*c[i].v)/(2*c[i].a+0.0);
				if(c[i].d+dis>L) c[i].l=c[i].d,c[i].r=L;
				else c[i].l=c[i].d,c[i].r=c[i].d+dis-ERR;
			}
		}
	}
	//for(int i=1;i<=n;i++)
	//	cout<<fixed<<setprecision(5)<<"i="<<i<<' '<<c[i].l<<" "<<c[i].r<<endl; 
}
void solvefr(){
	int ansfr=0;
	acnt=0;
	for(int i=1;i<=n;i++){
		if(c[i].l>L){ov[i]=0; continue;}
		int le=1,re=m,ans1=m+1;
		while(le<=re){
			int mid=(le+re)>>1;
			if(c[i].l>p[mid]+ER) le=mid+1;
			else ans1=mid,re=mid-1;
		} 
		le=1,re=m; int ans2=0;
		while(le<=re){
			int mid=(le+re)>>1;
			if(c[i].r<p[mid]-ER) re=mid-1;
			else ans2=mid,le=mid+1;
		} 
		//cout<<i<<' '<<ans1<<' '<<ans2<<endl;
		if(ans1<=ans2){
			ov[i]=1; ansfr++;
			c[i].fdl=ans1,c[i].fdr=ans2;
			a[++acnt]=c[i];
		}
	}
	cout<<ansfr<<' ';
}
void solvels(){
	sort(a+1,a+1+acnt,cmp);
	//for(int i=1;i<=acnt;i++) cout<<i<<' '<<a[i].fdl<<' '<<a[i].fdr<<endl;
	int ansls=0,nwl=-1;
	for(int i=acnt;i;i--){
		if(a[i].fdr>=nwl&&nwl!=-1) continue;
		ansls++; nwl=a[i].fdl;
	//	cout<<i<<' ';
	}
	cout<<m-ansls<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
		for(int j=1;j<=m;j++) cin>>p[j];
		init();
		solvefr();
		solvels();
	}
	return 0;
}

