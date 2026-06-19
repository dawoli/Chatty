#include<iostream>
#include<cstdio>
using namespace std;
const int N=114514;
const int M=1000010;
struct car{
	int d,v,a;
}spd[N];//ÃèÊö³µÁ¾ 
int ans1,ans2,n,m,L,V,dtr[N],diff[M],qzh[M];//dtr ²âËÙ diff²î·Ö 
int cnt_d(int v0,int a){
	if(v0>V)return 0;
	int s=V*V;
	s-=v0*v0;
	return s/(2*a)+1;
}
void diff_add(int l,int r){
	diff[l]++,diff[r+1]--;
	return;
}
void input(){
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++)cin>>spd[i].d>>spd[i].v>>spd[i].a;
	for(int i=1;i<=m;i++)cin>>dtr[i];
	return;
}
void init(){
	ans1=ans2=0;
	for(int i=1;i<=L;i++)diff[i]=qzh[i]=0;
	for(int i=1;i<=m;i++)qzh[dtr[i]]++;
	for(int i=1;i<=L+2;i++)qzh[i]+=qzh[i-1];
	for(int i=1,l,r;i<=n;i++){
		if(spd[i].v<=V&&spd[i].a<=0)continue;
		else if(spd[i].a==0)l=spd[i].d,r=L;
		else if(spd[i].a>0){
			if(spd[i].v*spd[i].v+2*spd[i].a*(L-spd[i].d)<V*V)continue;
			l=spd[i].d+max(0,cnt_d(spd[i].v,spd[i].a)),r=L;
			if(l>=r)continue;
		}
		else l=spd[i].d,r=min(L,spd[i].d+cnt_d(spd[i].v,spd[i].a));
		if(qzh[max(0,l-1)]<qzh[r]){
			ans1++;
//			cout<<i<<"<----"<<endl;
		}
		diff_add(l,r);
	}
	for(int i=1;i<=L+1;i++)diff[i]+=diff[i-1];
}
void output(){
	for(int i=2;i<=m;i++)if(diff[dtr[i]]==diff[dtr[i-1]])ans2++;
	if(ans1==0)cout<<ans1<<" "<<m<<endl; 
	else cout<<ans1<<" "<<m-1<<endl;
	return;
}
void test(){
	for(int i=0;i<=L;i++)cout<<diff[i]<<" ";
	cout<<endl;
	for(int i=0;i<=L;i++)cout<<qzh[i]<<" ";
	cout<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		input();
		init();
//		test();
		output();
	}
	return 0;
} 
