#include<bits/stdc++.h>
using namespace std;
long long cnt=10000000000000,n,m,k,atemp0[1100005],atemp1[1100005];
struct node{
	long long l;
	long long s;
	long long e;
};node a[1100005],atemp[1100005];
bool bj[1100005];
struct p{
	long long c;
	long long l[10005];
};p b[15];
bool f(node a,node b){
	return a.l<b.l;
}
long long t(node a[]){
	long long bc=0,e=0,s=0;
	while(bc<n){
		if(bj[a[s].s]==0){
			bc=bc+2-bj[a[s].e];
			bj[a[s].s]=1;
			bj[a[s].e]=1;
			e+=a[s].l;
		}else if(bj[a[s].e]==0){
			bc++;
			bj[a[s].e]=1;
			e+=a[s].l;
		}
		s++;
	}
	return e;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(long long i=0;i<m;i++){
		scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].l);
	}
	
	if(k==0){
		sort(a,a+m,f);
		cnt=t(a);
		printf("%d",cnt);
		return 0;
	}
	bool flag=false;
	for(long long i=0;i<k;i++){
		scanf("%d",&b[i].c);
		for(long long j=0;j<n;j++){
			scanf("%d",&b[i].l[j]);
		}
		if(b[i].c==0){
			for(long long j=0;j<m;j++){
				a[j].l=min(b[i].l[a[j].s]+b[i].l[a[j].e],a[j].l);
			}
		}else{
			flag=true;
		}
	}
	sort(a,a+m,f);
	cnt=min(t(a),cnt);
	printf("%d",cnt);
	return 0;
} 
