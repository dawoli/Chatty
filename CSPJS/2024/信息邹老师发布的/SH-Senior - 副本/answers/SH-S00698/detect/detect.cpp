#include<stdio.h>
#define NM 100001
struct bqj{
	int lo;
	int hi;
} bqj[NM];
int p[NM];
void bqj_eq(int left,int right){
	bqj[left].lo=bqj[right].lo;
	bqj[left].hi=bqj[right].hi;
	return;
}
void bqj_exc(int left,int right){
	bqj_eq(0,a);
	bqj_eq(a,b);
	bqj_eq(b,0);
	return;
}
int bottom;
_Bool isupper(int up,int down){
	if(bqj[up].lo<bqj[down].lo)
		return true;
	else
		return false;
}
_Bool needtogd(int up){
	if(isupper(up,up*2)&&isupper(up,up*2+1))
		return false;
	else
		return true;
}
void getting_down(){
	int k=1;
	while(needtogd(k)){
		if(isupper(k*2,k*2+1)){
			bqj_exc(k,k*2);
			k*=2;
		}
		else{
			bqj_exc(k,k*2+1);
			k=k*2+1;
		}
	}
	return;
}
void getting_new_bottom(){
	++bottom;
	return;
}
void getting_in_new(int lo,int hi){
	getting_new_bottom();
	bqj[bottom].lo=lo;
	bqj[bottom].hi=hi;
	return;
}
void getting_in(int lo,int hi){
	getting_in_new(lo,hi);
	int k=bottom;
	while(isupper(k,k/2)){
		bqj_exc(k,k/2);
		k/=2;
	}
	return;
}
void getting_out(){
	bqj_exc(1,bottom);
	getting_down();
}
void del(){
	bottom=0;
	for(int i=0;i<NM;++i){
		bqj[i].hi=0;
		bqj[i].lo=0;
		p[i]=0;
	}
}
File* get,put;
void del
void solve(){
	int n,m,L,V;
	int d,v,a;
	del();
	scanf("%d%d%d%d",&n,&m,&L,&V);
	for(int i=0;i<n;++i){
		int hi,lo;
		scanf("%d%d%d",d,v,a);
		if(a<=0&&v<=V)
			;
		else if(a<0&&v>V){
			lo=d;
			if((v*v-V*V)%(0-2*a)==0)
				hi=(v*v-V*V)/(0-2*a)-1+d;
			else
				hi=(v*v-V*V)/(0-2*a)+d;
			if(hi>a)
				hi=a;
			getting_in(lo,hi);
		}
		else if(a>=0&&v>V){
			lo=d;
			hi=L;
			getting_in(lo,hi);
		}
		else if(a>0&&v<=V){
			lo=(V*V-v*v)/(2*a)+1;
			if(lo>L)
				;
			else{
				hi=L;
				getting_in(lo,hi);
			}
		}
	}
	for(int i=0;i<m;++i){
		scanf("%d",&p[i]);
	}
	int lo_=L+1;
	int t;
	for(int i=1;i<=m;++i){
		int hi,int lo;
		hi=bqj[1].hi;
		lo=bqj[1].lo;
		getting_out();
		int j=lo;
		while(p[t]>=lo)
			--t;
		while(j<=hi&&p[j]
		lo_=lo;
int main(){
	get=fopen("detect.in","r");
	put=fopen("detect.out","w");
	scanf("%d",T);
	for(int i=1;i<=T;++i){
		solve();
	}
	return 0;
}
