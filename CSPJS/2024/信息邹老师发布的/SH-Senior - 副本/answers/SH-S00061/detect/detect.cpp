#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,o,c,car[100000][3],p[100000],opd[100000],opn[100000];double bx;bool ad=0;
struct rg{
	int f,r;
};
rg op[100000];int io;
bool cmp(rg a,rg b){
	return a.r<b.r;
}
int fd(int x){
	int f=0,r=m,mid;
	while(r-f!=1){
		mid=(r+f)/2;
		if(x<p[mid])r=mid;
		else f=mid;
	}
	return f;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		o=0;c=0;io=0;
		scanf("%d%d%d%d",&n,&m,&l,&v);
		memset(opn,0,sizeof(opn));memset(opd,0,sizeof(opd));
		for(int j=0;j<n;j++){
			scanf("%d%d%d",&car[j][0],&car[j][1],&car[j][2]);
		}
		for(int j=0;j<m;j++){
			scanf("%d",&p[j]);
			
		}
		for(int k=0;k<n;k++){
			
			if(car[k][2]){
				bx=car[k][0]+(double)(v*v-car[k][1]*car[k][1])/(2*car[k][2]);
				if(car[k][2]<0){
					ad=0;
					for(int y=fd(car[k][0]);y<=min(fd(bx)+1,m);y++){
						if(car[k][0]<=p[y]&&p[y]<bx){
							if(!ad){
								op[io].f=y;
								o++;ad=1;io++;
							}
							op[io-1].r=max(op[io-1].r,y);
							
							
						}
					}
					
				}else{
					ad=0;
					for(int y=fd(bx);y<m;y++){
						if(bx<p[y]){
							op[io].f=y;
							op[io].r=m;
							o++;io++;
							
							
							break;
						}
					}
				}
				sort(op,op+m,cmp);
				for(int q=0;q<m;q++){
					for(int qi=0;qi<io;qi++){
						if(op[qi].f<=q&&q<=op[qi].r){
							opn[qi]++;
						}
					}
				}
				for(int q=0;q<io;q++){
					if(opd[q]==0){
						c++;
						int mx=-1,mxi=op[q].r;
						for(int qi=op[q].r;qi>=op[q].f;qi--){
							if(opn[qi]==0&&opn[qi]>mx){
								mx=opn[qi];mxi=qi;
							}
						}
						for(int qi=0;qi<io;qi++){
							if(op[qi].f<=mxi&&mxi<=op[qi].r){
								opd[qi]++;
							}
						}
					}
				}
			}else{
				if(car[k][1]>v){
					o++;
					op[io].f=0;op[io++].r=m;
				}
			}
		}
		printf("%d %d\n",o,m-c);
	}
	return 0;
}
