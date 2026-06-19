#include<bits/stdc++.h>
using namespace std;
const int N_MX=200002;
int T;
int n,m,L,V;
int d[N_MX],v0[N_MX],a[N_MX];
int p[N_MX];
bool judge_A=true,judge_B=true,judge_C=true;
struct block{
	double l,r;
} f[N_MX];
bool cmp_block(block a,block b){
	if(a.l==b.l)
		return a.r<b.r;
	return a.l<b.l;
}
void input(){
	n=0,m=0,L=0,V=0;
	memset(d,0,sizeof(d));
	memset(v0,0,sizeof(v0));
	memset(a,0,sizeof(a));
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;++i){
		cin>>d[i]>>v0[i]>>a[i];
		if(a[i]<=0)
			judge_B=false;
		if(a[i]!=0)
			judge_A=false;
		if(a[i]>=0)
			judge_C=false;
	}
	for(int i=1;i<=m;i++)
		cin>>p[i];
	sort(p+1,p+1+m);
}
void solveA(){
	int cnt=0,ans=m-1;
	int p_mx=p[m];
	for(int i=1;i<=n;i++){
		if(v0[i]>V&&d[i]<=p_mx)
			cnt++;
	}
	if(cnt==0)
		ans++;
	cout<<cnt<<" "<<ans<<endl;
}
void solveB(){
	int cnt=0,ans;
	int p_mx=p[m];
	double s;
	for(int i=1;i<=n;i++){
		s=1.0*(1.0*V*V-1.0*v0[i]*v0[i])/(2.0*a[i])+1.0*d[i]+1;
		if(s<p_mx&&d[i]<=p_mx)
			++cnt;
	}
	ans=m-1;
	if(cnt==0)
		ans++;
	cout<<cnt<<" "<<ans<<endl;
}
void solveC(){
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		double l,r;
		l=d[i];
		r=1.0*(1.0*V*V-1.0*v0[i]*v0[i])/(a[i]*2.0)+1.0*d[i]+1.0;
		f[i].l=l,f[i].r=r;
	}
	sort(f+1,f+1+n,cmp_block);
	int id=1;
	for(int i=1;i<=n&&id<=m;){
		while(p[id+1]<=f[i].r){
			id++;
			ans++;
		}
		while(f[i].l<=p[id])
			i++,cnt++;
		id++;
	}
	cout<<cnt<<" "<<ans<<endl;;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		input();
		if(judge_A)
			solveA();
		else if(judge_B)
			solveB();
		else
			solveC();
	}
	return 0;
}
