#include<bits/stdc++.h>
const long long N=1e5+9;
struct Node{
	long long x,y,z,m;
}a[N],X[N],Y[N],Z[N];
long long t,n;
long long cx,cy,cz;
long long ans;
bool cmp(const Node &u,const Node &v){
	return u.m<=v.m;
}
void solve(){
	cx=cy=cz=0;
	ans=0;
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
//			puts("1");
			ans+=a[i].x;
			X[++cx]=a[i];
		}
		else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
//			puts("2");
			ans+=a[i].y;
			Y[++cy]=a[i];
		}
		else{
//			puts("3");
			ans+=a[i].z;
			Z[++cz]=a[i];
		}
	}
	if(cx<=n/2&&cy<=n/2&&cz<=n/2){
		printf("%lld\n",ans);
		return;
	}
	if(cx>n/2){
		for(long long i=1;i<=cx;i++){
			X[i].m=X[i].x-std::max(X[i].y,X[i].z);
		}
		std::sort(X+1,X+1+cx,cmp);
		for(long long i=1;cx-i>=n/2;i++){
			ans=ans-X[i].m;
		}
	}
	else if(cy>n/2){
		for(long long i=1;i<=cy;i++){
			Y[i].m=Y[i].y-std::max(Y[i].x,Y[i].z);
		}
		std::sort(Y+1,Y+1+cy,cmp);
		for(long long i=1;cy-i>=n/2;i++){
			ans=ans-Y[i].m;
		}
	}
	else{
		for(long long i=1;i<=cz;i++){
			Z[i].m=Z[i].z-std::max(Z[i].x,Z[i].y);
		}
		std::sort(Z+1,Z+1+cz,cmp);
		for(long long i=1;cz-i>=n/2;i++){
			ans=ans-Z[i].m;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--) solve();
	return 0;
}
