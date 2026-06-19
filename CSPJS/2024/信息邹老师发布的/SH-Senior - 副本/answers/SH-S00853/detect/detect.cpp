#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,t,l,v_lim,p[N];
int ans_cr=0,ans_p=0;
int crt=0;
struct cr{
  int d,v,a;
}info[N];
bool cmp(cr x,cr y){
  return x.d<y.d;
}
void init(){
  memset(p,0,sizeof(p));
  memset(info,0,sizeof(info));
  ans_cr=0;ans_p=0;
  crt=0;
  n=0;m=0;l=0;v_lim=0;
}
int main(){
  freopen("detect.in","r",stdin);
  freopen("detect.out","w",stdout);
  scanf("%d",&t);
  while(t--){
  	init();
  	scanf("%d%d%d%d",&n,&m,&l,&v_lim);
  	for(int i=1;i<=n;i++){
  	  scanf("%d%d%d",&info[i].d,&info[i].v,&info[i].a);
	}
  	for(int i=1;i<=m;i++){
  	  scanf("%d",&p[i]);
	}
	sort(info+1,info+n+1,cmp);
	crt=0;
	for(int i=1;i<=n;i++){
	  float vcr=0;
	  while(info[i].d>p[crt]){
	  	crt++;
	  }
	  if(info[i].a>0){
	  	vcr=sqrt(info[i].v*info[i].v+2*info[i].a*(p[m]-info[i].d));
	  }
	  else if(info[i].a==0){
	  	vcr=info[i].v;
	  }
	  else{
	  	vcr=sqrt(info[i].v*info[i].v+2*info[i].a*(p[crt]-info[i].d));
	  }
	  if(vcr>v_lim) ans_cr++;
	}
	printf("%d ",ans_cr);
	if(ans_cr!=0) printf("%d\n",m-1);
	else printf("%d\n",m);
  }
  return 0;
}
