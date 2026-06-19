#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int N=100009;
const db ERR=0.0000001;
int T,n,m;
db len,sl,d[N],v[N],a[N],p[N];
void solveAll0(){
	int ans=0;
	for(int i=1;i<=n;i++){
		db maxP=*max_element(p+1,p+1+m);
		if(d[i]-maxP+ERR<0&&v[i]-sl-ERR>0) ans++; 
	}
	if(ans==0) printf("%d %d\n",ans,m);
	else printf("%d %d\n",ans,m-1);
}
void solveAllPositive(){
	int ans=0;
	for(int i=1;i<=n;i++){
		db maxP=*max_element(p+1,p+1+m);
		db s=(sl*sl-v[i]*v[i])/a[i]/2;
		if(s-maxP+ERR<0&&len-s+ERR>0) ans++; 
	}
	if(ans==0) printf("%d %d\n",ans,m);
	else printf("%d %d\n",ans,m-1);
}
bool All0(){
	for(int i=1;i<=n;i++) if(abs(a[i])>ERR) return 0;
	return 1;
}
bool AllPositive(){
	for(int i=1;i<=n;i++) if(a[i]<0) return 0;
	return 1;
}
void input(){
	scanf("%d%d%lf%lf",&n,&m,&len,&sl);
	for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&d[i],&v[i],&a[i]);
	for(int i=1;i<=m;i++) scanf("%lf",&p[i]);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	for(int asdfghjkl=1;asdfghjkl<=T;asdfghjkl++){
		input();
		if(All0()) solveAll0();
		else if(AllPositive()) solveAllPositive(); 
		else printf("ÎâÉê¹ã´óË§¸ç\n");
	}
	return 0;
}

