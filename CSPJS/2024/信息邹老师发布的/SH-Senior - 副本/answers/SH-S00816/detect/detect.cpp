#include<bits/stdc++.h> 
#define N 100003
#define M 100003
using namespace std;
// ~20, Partial Correct
int T,n,m,L,V;
int d[N],v[N],a[N],p[M];
int use[M];
void input(){
	scanf("%d%d%d%d",&n,&m,&L,&V);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&d[i],&v[i],&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&p[i]);
}
bool check0(){
	for(int i=1;i<=n;i++)
		if(a[i]!=0)return false;
	return true;
}
void solve0(){
	int ans=0;
	for(int i=1;i<=n;i++)
		if(v[i]>V&&d[i]<=p[m]){
			ans++;
		}
	if(ans==0)printf("%d %d\n",ans,m);
	else printf("%d %d\n",ans,m-1);
}
bool checkPos(){
	for(int i=1;i<=n;i++)
		if(a[i]<=0)return false;
	return true;
}
void solvePos(){
	int ans=0;
	double tmp=0.0;
	for(int k=1;k<=n;k++){
		double s=0.0;
		if(v[k]>V)s=(V*V-v[k]*v[k])/(2.0*a[k]);
		if(s<0.0)s=0.0; 
		if(d[k]+s-p[m]<=0.0)ans++; 
		if(tmp-s>0.0)tmp=s;
	}
	int ans2=0;
	for(int i=1;i<=m;i++)
		if(tmp-p[m]>0)ans2++;
	printf("%d %d\n",ans,ans2);
}
void solve(){
	printf("imnothing & biometrics\n");
}
int main(){
	freopen("detect4.in","r",stdin);
	freopen("detect4.out","w",stdout); 
	int T=0;
	scanf("%d",&T);
	while(T--){
		input();
		if(check0())
			solve0();
		//else if(checkPos())
		//	solvePos();
		else
			solve();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
