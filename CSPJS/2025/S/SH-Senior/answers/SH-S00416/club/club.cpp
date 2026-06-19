#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct p{
	int a;
	int b;
	int c;
}x[100010],xa[50010],xb[50010],xc[50010];
bool cmpa(p x,p y){
	return (x.a-max(x.b,x.c))<(y.a-max(y.b,y.c));
}
bool cmpb(p x,p y){
	return (x.b-max(x.a,x.c))<(y.b-max(y.a,y.c));
}
bool cmpc(p x,p y){
	return (x.c-max(x.a,x.c))<(y.a-max(y.b,y.c));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,cnta=0,cntb=0,cntc=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a>=x[i].b&&x[i].a>=x[i].c){
				ans+=x[i].a;
				cnta++;
				xa[cnta].a=x[i].a;
				xa[cnta].b=x[i].b;
				xa[cnta].c=x[i].c;
			}
			else if(x[i].b>=x[i].a&&x[i].b>=x[i].c){
				ans+=x[i].b;cntb++;
				xb[cntb].a=x[i].a;
				xb[cntb].b=x[i].b;
				xb[cntb].c=x[i].c;
			}
			else{
				ans+=x[i].c;
				cntc++;
				xc[cntc].a=x[i].a;
				xc[cntc].b=x[i].b;
				xc[cntc].c=x[i].c;
			}
		}
		while(cnta>(n/2)){
			sort(xa+1,xa+n+1,cmpa);
			ans=ans-xa[cnta].a+max(xa[cnta].b,xa[cnta].c);
			if(xa[cnta].b>=xa[cnta].c){
				cntb++;
				xb[cntb].a=xa[cnta].a;
				xb[cntb].b=xa[cnta].b;
				xb[cntb].c=xa[cnta].c;	
			}
			else {
				cntc++;
				xc[cntc].a=xa[cnta].a;
				xc[cntc].b=xa[cnta].b;
				xc[cntc].c=xa[cnta].c;
			}
			xa[cnta].a=0;
			xa[cnta].b=0;
			xa[cnta].c=0;
			cnta--;	
		}
		while(cntb>(n/2)){
			sort(xb+1,xb+n+1,cmpb);
			ans=ans-xb[cntb].b+max(xb[cntb].a,xb[cntb].c);
			if(xb[cntb].a>=xb[cntb].c){
				cnta++;
				xa[cnta].a=xb[cntb].a;
				xa[cnta].b=xb[cntb].b;
				xa[cnta].c=xb[cntb].c;
			}
			else {
				cntc++;
				xc[cntc].a=xb[cntb].a;
				xc[cntc].b=xb[cntb].b;
				xc[cntc].c=xb[cntb].c;	
			}
			xb[cntb].a=0;
			xb[cntb].b=0;
			xb[cntb].c=0;
			cntb--;
		}
		while(cntc>(n/2)){
			sort(xc+1,xc+n+1,cmpc);
			ans=ans-xc[cntc].c+max(xc[cntc].b,xc[cntc].a);
			if(xc[cntc].a>=xc[cntc].b){
				cnta++;
				xa[cnta].a=xc[cntc].a;
				xa[cnta].b=xc[cntc].b;
				xa[cnta].c=xc[cntc].c;
			}
			else {
				cntb++;
				xb[cntb].a=xc[cntc].a;
				xb[cntb].b=xc[cntc].b;
				xb[cntb].c=xc[cntc].c;	
			}
			xc[cntc].a=0;
			xc[cntc].b=0;
			xc[cntc].c=0;
			cntc--;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
