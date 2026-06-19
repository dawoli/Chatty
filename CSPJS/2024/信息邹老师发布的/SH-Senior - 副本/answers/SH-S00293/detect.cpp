#include<bits/stdc++.h>
using namespace std;
//n:car m:detect L:length V:speed limit
//d:beginpos v:chusu a:jiasu
int T,n,m;
long long L,V,d[200005],v[200005],a[200005],p[200005];
int l[200005],r[200005];
struct node{
	int ll,rr;
} nod[200005];
bool cmp(node x,node y){
	return x.rr<y.rr;
}
long long sqsp(long long v0,long long aa,long long s){
	return v0*v0+2*aa*s;
}
void pre1(){
	memset(l,0x3f,sizeof(l));
	memset(r,-1,sizeof(r));
}
void solve1(){
	pre1();
	int ans=0x3f3f3f3f,ans2=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(p[j]<d[i]) continue;
			long long tt=sqsp(v[i],a[i],p[j]-d[i]);
			if(a[i]<0&&tt<=0) break;
			if(tt>V*V) l[i]=min(l[i],j),r[i]=max(r[i],j);
		}
		if(r[i]>=1) ans2++;
	}	
	for(int i=0;i<(1<<m);i++){
		vector<int> vv;
		bool succ=1;
		for(int j=1;j<=m;j++)
			if(i&(1<<(j-1))) vv.push_back(j);
		for(int j=1;j<=n;j++){
			vector<int>::iterator it=lower_bound(vv.begin(),vv.end(),l[j]);
			if(r[j]<1) continue;
			if(it==vv.end()){
				succ=0;
				break;
			}
			if(*it>r[j]){
				succ=0;
				break; 
			}
		}
		if(succ) ans=min(ans,(int)vv.size());
	}
	printf("%d %d\n",ans2,m-ans);
}
void solve2(){
	int ans2=0;
	for(int i=1;i<=n;i++){
		if(p[m]<d[i]) continue;
		if(sqsp(v[i],a[i],p[m]-d[i])>V*V) ans2++;
	}
	if(ans2==0) printf("%d %d\n",ans2,m);
	else printf("%d %d\n",ans2,m-1);
}
void solve3(){
	pre1();
	int ans2=0,ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(p[j]<d[i]) continue;
			long long tt=sqsp(v[i],a[i],p[j]-d[i]);
			if(tt<=0) break;
			if(tt>V*V) l[i]=min(l[i],j),r[i]=max(r[i],j);
		}
		if(r[i]>=1) ans2++;
		nod[i].ll=l[i],nod[i].rr=r[i];
	}
	sort(nod+1,nod+n+1,cmp);
	int lst=0;
	for(int i=1;i<=n;i++){
		if(nod[i].rr<1) continue;
		if(lst>=nod[i].ll) continue;
		else{
			ans++;
			lst=nod[i].rr;
		}
	}
	printf("%d %d\n",ans2,m-ans);
}
void solve4(){
	pre1();
	int ans2=0,ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=0){
//			cout<<"A"<<endl;
			int l2=lower_bound(p+1,p+m+1,d[i])-p,r2=m,mid,ress=-1;
//			cout<<l2<<' '<<r2<<endl;
			while(l2<=r2){
				mid=(l2+r2)/2;
				if(sqsp(v[i],a[i],p[mid]-d[i])>V*V){
					ress=mid;
					r2=mid-1;
				}
				else l2=mid+1;
			}
			if(ress>0) l[i]=ress,r[i]=m;
		}
		else{
			long long tt=(1.0*v[i])/(-2*a[i])+d[i];
			int l2=lower_bound(p+1,p+m+1,d[i])-p,r2=upper_bound(p+1,p+m+1,tt)-p-1,mid,ress=-1;
			while(l2<=r2){
				mid=(l2+r2)/2;
				if(sqsp(v[i],a[i],p[mid]-d[i])>V*V){
					ress=mid;
					l2=mid+1;
				}
				else r2=mid-1;
			}
			if(ress>0) l[i]=lower_bound(p+1,p+m+1,d[i])-p,r[i]=ress;
		}
		if(r[i]>=1) ans2++;
		nod[i].ll=l[i],nod[i].rr=r[i];
	}	
	sort(nod+1,nod+n+1,cmp);
	int lst=0;
	for(int i=1;i<=n;i++){
		if(nod[i].rr<1) continue;
		if(lst>=nod[i].ll) continue;
		else{
			ans++;
			lst=nod[i].rr;
		}
	}
	printf("%d %d\n",ans2,m-ans);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%lld%lld",&n,&m,&L,&V);
		long long minn=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
			minn=min(minn,a[i]);
		}
		for(int i=1;i<=m;i++) scanf("%lld",&p[i]);
		if(n<=20&&m<=20) solve1();
		else if(minn>=0) solve2();
		else solve3();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
