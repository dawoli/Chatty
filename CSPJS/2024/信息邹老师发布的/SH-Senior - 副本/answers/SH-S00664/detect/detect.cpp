#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
struct Node{
	int a,b;
	bool operator<(const Node B)const{
		return a<B.a;
	}
};
int t,n,m,l,k,ll[N],rr[N],p[N];
int cnt;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		vector<Node>v;
		scanf("%d%d%d%d",&n,&m,&l,&k);
		for(int i=1;i<=n;i++){
			int d,v,a;
			scanf("%d%d%d",&d,&v,&a);
			if(a==0){
				if(v<=k)ll[i]=l+1,rr[i]=l;
				else ll[i]=d,rr[i]=l;
				continue;
			}
			double dis=(k*k-v*v)*1.0/(2*a);
			if(v>k){
				ll[i]=d;
				if(dis<0)rr[i]=l;
				else rr[i]=min(l,d+(int)ceil(dis-1.0));
			}else{
				rr[i]=l;
				if(dis<0)ll[i]=l+1;
				else ll[i]=min(l+1,d+(int)floor(dis+1.0));
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			int a=lower_bound(p+1,p+1+m,ll[i])-p;
			int b=upper_bound(p+1,p+1+m,rr[i])-p-1;
			if(a>b||a>m)continue;
			cnt++;
			v.push_back((Node){a,b});
		}
		printf("%d ",cnt);
		sort(v.begin(),v.end()); 
		for(int i=1;i<v.size();i++){
			if(v[i].a<=v[i-1].b){
				v[i].b=min(v[i].b,v[i-1].b);
				cnt--;
			}
		}
		printf("%d\n",m-cnt);
	} 
	return 0;
}
