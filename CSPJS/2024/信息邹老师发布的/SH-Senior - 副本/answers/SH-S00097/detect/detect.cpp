#include<bits/stdc++.h>
using namespace std;
struct qiche{
	int d,v,a;
};
struct qujian{
	float l,r;
	int num;
};
int n,m,l,v;
qiche c[100010];
int p[100010];
qujian q[100010];
bool bijiao(qujian a,qujian b){
	if(a.r!=b.r)  return a.r<b.r;
	return a.l<b.l;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	//t=4;
	for(int i=1;i<=t;i++){
		vector<qujian> g;
		cin>>n>>m>>l>>v;
		for(int j=0;j<n;j++)   cin>>c[j].d>>c[j].v>>c[j].a;
		for(int j=0;j<m;j++)   cin>>p[j];
		//for(int j=0;j<m;j++)   cout<<p[j]<<" ";
		//cout<<endl;
		int ccc=0;
		for(int j=0;j<n;j++){
			q[j].num=j;
			if(c[j].a==0){
				if(c[j].v>v){
					q[j].l=c[j].d;q[j].r=l;
				}
				else{
					q[j].l=-1;q[j].r=-1;
					ccc++;
				}
			}
			if(c[j].a>0){
				float tem=(v*v-c[j].v*c[j].v)*1.000/2/c[j].a;
				if(tem<=0){
					q[j].l=c[j].d;q[j].r=l;
				}
				if(tem+c[j].d<=l&&tem>0){
					q[j].l=tem+c[j].d;q[j].r=l;
				}
				if(tem+c[j].d>l){
					q[j].l=-1;q[j].r=-1;
				}
			}
			if(c[j].a<0){
				if(c[j].v<=v){
					q[j].l=-1;q[j].r=-1;
				}
				else{
					float tem=(v*v-c[j].v*c[j].v)*1.000/2/c[j].a;
					if(tem+c[j].d<=l){
						q[j].l=c[j].d;q[j].r=tem+c[j].d;
					}
					if(tem+c[j].d>l){
						q[j].l=c[j].d;q[j].r=l;
					}	
				}
			}
		}
		sort(q,q+n,bijiao);
		int ans=0;
		for(int j=0;j<n;j++){
			if(q[j].l==-1&&q[j].r==-1)   continue;
			int nn=q[j].num;
			int cam=lower_bound(p,p+m,q[j].l)-p;
			if(cam==m)   cam--;
			float f;
			if(c[nn].v*c[nn].v+2*c[nn].a*(p[cam]-c[nn].d)<0) f=0;
			else f=sqrt(c[nn].v*c[nn].v+2*c[nn].a*(p[cam]-c[nn].d));
			if(f==v){
				if(cam!=m-1)   cam++;
				else{
					continue;
				} 
			}
			if(c[nn].v*c[nn].v+2*c[nn].a*(p[cam]-c[nn].d)<0) f=0;
			else f=sqrt(c[nn].v*c[nn].v+2*c[nn].a*(p[cam]-c[nn].d));
			if(f>v&&p[cam]>=q[j].l){
				ans++;
				g.push_back(q[j]);
			}
		}
		int ans2=0,curcam=0;
		//for(int j=0;j<g.size();j++)   cout<<g[j].l<<" "<<g[j].r<<" "<<g[j].num<<endl;
		for(int j=0;j<g.size();j++){
			int nn=g[j].num;
			if(curcam){
				float ff;
			if(c[nn].v*c[nn].v+2*c[nn].a*(p[curcam]-c[nn].d)<0) ff=0;
			else ff=sqrt(c[nn].v*c[nn].v+2*c[nn].a*(p[curcam]-c[nn].d));
				if(ff>v&&p[curcam]>=c[nn].d)   continue;
			}
			int cam=lower_bound(p,p+m,g[j].r)-p;
			if(cam==m)   cam--;
			float f;
			if(c[nn].v*c[nn].v+2*c[nn].a*(p[cam]-c[nn].d)<0) f=0;
			else f=sqrt(c[nn].v*c[nn].v+2*c[nn].a*(p[cam]-c[nn].d));
			if(f<=v)   cam--;
			//cout<<cam<<endl;
			curcam=cam;ans2++;
		}
		cout<<ans<<" "<<m-ans2<<endl;
	}
	return 0;
}
