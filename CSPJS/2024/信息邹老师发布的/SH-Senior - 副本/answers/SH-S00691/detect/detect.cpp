#include<bits/stdc++.h>
using namespace std;
int d[100001],v[100001],a[100001],p[100001],pa[100001];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T,n,m,l,vl;scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d %d %d %d",&n,&m,&l,&vl);
		for(int j=1;j<=n;j++){
			scanf("%d %d %d",&d[j],&v[j],&a[j]);
		}
		for(int j=1;j<=m;j++){
			scanf("%d",&p[j]);
		}
		int cnt=0,t=0,s,b=0;
		float vt;
		for(int j=1;j<=n;j++){
			for(int k=m;k>=1;k--){
				if(p[k]>d[j]){
					s=p[k]-d[j];
					if(a<0&&s>=-0.5*v[j]*v[j]/a[j]){break;}
					a[j]==0?vt=v[j]:vt=sqrt(1.0*v[j]*v[j]+2.0*a[j]*s);
					if(vt-0.000001>vl){
						if(a[j]>0&&b==0){
							for(int o=k+1;o<=m;o++){
								if(pa[o])b=1;
							}
						}
						b==0?pa[k]=1:pa[k]=0;
						t=1;
					}
				}
			}if(t) cnt++;t=0;b=0;
		}
		int sum=0;
		for(int k=1;k<=m;k++){
			if(!pa[k]){sum++;}
	}
		printf("%d %d",cnt,sum);printf("\n");
	}
	return 0;
}
