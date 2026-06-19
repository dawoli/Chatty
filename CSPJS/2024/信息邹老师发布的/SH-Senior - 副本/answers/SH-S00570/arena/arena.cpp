#include<bits/stdc++.h>
using namespace std;
int n,m,K;
int t;
int a[100010],c[100010];
string d[100010];
int x[4],aa[100010];
long long ans=0;
int mergeArena(int st,int ed,int i){
	if(ed-st==1){
		if(ed>c[i]&&st<=c[i]){
			ans+=ed;
			return st;	
		}
		if(st>c[i]){
			ans+=st;
			return ed;	
		}
		if(d[1][ed/2]=='0')return aa[st]>1;
		else return aa[ed]>1;
	}
	else{
		int a=mergeArena(st,((ed-st)/2)+st;
		int b=mergeArena(((ed-st)/2)+st+1,ed);
		if(d[1<<log2(b-a)][a/1<<log2(b-a)]=='0')return aa[a]>1<<log2(b-a);
		else return aa[b]>1<<log2(b-a);		
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	K=ceil(log2(n));
	for(int R=1;R<=K;R++){
		cin>>d[R];
	}
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<4;i++)scanf("%d",&x[i]);
		for(int i=1;i<=n;i++){
			aa[i]=a[i]^(x[i%4]);
		}
		long long kkk=0;
		for(int i=1;i<=m;i++){
			ans=0;
			int k=ceil(log2(c[i]));
			kkk^=(mergeArena(1,k,i)+ans)*i;
		}
		printf("%lld\n",kkk);
	}
	return 0;
}
