#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int M=1e6+10;
int n,m,L,V;
int t;
int d[N],v[N],s[N];
int p[N];
struct node{
	int a,b;
}ab[N];
int l;
int xiansu[M];
int fz=0,fm=0;

bool cmp(const node &x,const node &y){
	return x.b<y.b;
}

signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t; 
	while(t--){
		int ans1=0,ans2=0;
		cin>>n>>m>>L>>V;
		memset(ab,0,sizeof(ab));l=0;
		memset(xiansu,0,sizeof(xiansu));
		
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>s[i];
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=0,now=1;i<=L;i++){
			if(p[now]==i) xiansu[i]=p[now++];
			else if(i==0) xiansu[i]=-3;
			else xiansu[i]=xiansu[i-1];
		}
//		for(int i=0;i<=L;i++) cout<<xiansu[i]<<" ";
//		cout<<endl;
		for(int i=1;i<=n;i++){
			if(s[i]==0){
				if(v[i]>V){
					l++;
					ab[l].a=d[i];
					ab[l].b=L;
				}
				continue;
			}
			if(v[i]<=V&&s[i]<=0) continue;
			fz=0,fm=0;
			int x=V*V,y=v[i]*v[i];
			fz=x-y;
			fm=2*s[i];bool flag=1;
			if(fz<0&&fm<0) fz=-fz,fm=-fm,flag=0;
			if(fz<=0&&fm>=0){
				if(fz==0) d[i]++;
				l++;
				ab[l].a=min(d[i],L);
				ab[l].b=L;
				continue;
			}
			if(fz>=0&&fm<=0) continue;
			int fs=fz/fm;
			fs++;
			if(flag&&fs>=0){
				if(d[i]+fs>L) continue;
				l++;
				
				ab[l].a=min(L,d[i]+fs);
				ab[l].b=L;	
			}
			else{
				l++;
				ab[l].a=d[i];
				if(fz%fm==0) fs--;
				ab[l].b=min(L,d[i]+fs-1);	
			}
		}
		for(int i=1;i<=l;i++){
			if(xiansu[ab[i].b]>ab[i].a-1) ans1++; 
//						if(t==6)
//			cout<<xiansu[ab[i].b]<<endl;
		}
		
		sort(ab+1,ab+1+l,cmp);
		for(int i=1,now=0;i<=l;i++){
			if(ab[i].a>ab[i].b) continue;
			if(ab[i].a<=now) continue;
			if(xiansu[ab[i].b]<ab[i].a) continue;
			now=xiansu[ab[i].b];
			ans2++;
		}
		cout<<ans1<<" "<<m-ans2<<"\n";
	}
	return 0;
}
