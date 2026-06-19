#include<bits/stdc++.h>
using namespace std;
const int maxn=3010;
const int maxm=1e5+10;
int T,n,m,L,ans,ans2,cnt;
double V;
double d[maxm],v[maxm],a[maxm],p[maxn],endd[maxn],maxp;
double vn;
int num[maxn];//第j辆车在第i个测速仪处是否超速 
bool flag[maxn],f,fA=true;
inline int read(){
	int x(0),f(1);
	char c=getchar();
	while(c<'0' or c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0' and c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
struct node{
	int used[maxn],times;
}c[maxn];
bool cmp(node a,node b){
	return a.times<b.times;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),L=read(),cin>>V,f=false,ans=0,ans2=0,cnt=0,maxp=0;
		if(fA==false){memset(c,0,sizeof(c));
		memset(num,0,sizeof(num));
		memset(flag,false,sizeof(flag));}
		for(int i=1;i<=n;++i){
			scanf("%lf",&d[i]);
			scanf("%lf",&v[i]);
			scanf("%lf",&a[i]);
			if(a[i]==0) endd[i]=L;
			else if(a[i]<0){
				double e=-v[i]*v[i]/2/a[i];
				if(e+d[i]<L) endd[i]=e+d[i];
				else endd[i]=L;
				fA=false;
			}
			else if(a[i]>0) fA=false,endd[i]=L;
		}
		for(int i=1;i<=m;++i) p[i]=read(),maxp=max(p[i],maxp);
//		cout<<maxp<<'\n';
		if(fA==true){
//			cout<<d[1];
			for(int j=1;j<=n;++j){
				if(v[j]>V and d[j]<=maxp) ans++;
//				cout<<ans<<'\n';
//				cout<<j<<'\n';
			}
			if(ans!=0) cout<<ans<<" "<<m-1<<'\n';
			else cout<<ans<<" "<<m<<'\n';
		}
		else{
			for(int i=1;i<=m;++i){
				for(int j=1;j<=n;++j){
					if(p[i]>=d[j] and p[i]<=endd[j]){
						vn=sqrt(v[j]*v[j]+2*a[j]*(p[i]-d[j]));
	//					cout<<j<<" "<<vn<<'\n';
						if(vn>V and flag[j]==false) ans++,flag[j]=true,c[i].used[j]=1,num[j]++;
						else if(vn>V) c[i].used[j]=1,num[j]++;
					}
				}
			}
			for(int i=1;i<=m;++i){
				for(int j=1;j<=n;++j){
					if(c[i].used[j]==1) c[i].times++;
				}
			}
			sort(c+1,c+n+1,cmp);
	//		for(int i=1;i<=m;++i){
	//			for(int j=1;j<=n;++j){
	//				cout<<c[i].used[j]<<" ";
	//			}
	//			cout<<c[i].times<<'\n';
	//		}
		//	for(int i=1;i<=n;++i) cout<<num[i]<<" ";
		//	cout<<'\n'; 
			for(int i=1;i<=m;++i){
				for(int j=1;j<=n;++j){
					if(c[i].used[j]==1 and num[j]==1){cnt=j-1;f=true;break;}
					if(c[i].used[j]==1 and num[j]>1) num[j]--;
					if(j==n and ans2!=m-1) ans2++;
				//	cout<<i<<" ";
				}
				if(f==true)
					for(int j=1;j<=cnt;++j)
						if(c[i].used[j]==1) num[j]++;
				f=false;
			}
		//	if(ans==0) cout<<ans<<" "<<m<<'\n';
			cout<<ans<<" "<<ans2<<'\n';
			//else cout<<ans<<" "<<m-1<<'\n';
		}
	}
	return 0;
}

