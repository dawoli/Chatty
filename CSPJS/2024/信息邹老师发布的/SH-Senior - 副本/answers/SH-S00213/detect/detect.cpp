#include<bits/stdc++.h>
using namespace std;

int T,liu[100002];

struct C{
	int d,v,a;
	bool chao;
};

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout)
	scanf("%d", &T);
	for(int i=1;i<=T;i++){
		C c[100002];
		int n,m,L,V,num=0;
		int p[100002];
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for(int i=1;i<=n;i++) c[i].chao=0;
		for(int j=1;j<=n;j++)
			scanf("%d%d%d", &c[j].d, &c[j].v, &c[j].a);
		for(int j=1;j<=m;j++)
			scanf("%d", &p[j]);
		for(int j=1;j<=n;j++){
			int s =0;
			for(int k=1;k<=m;k++)
				if(p[k]>=c[j].d){
					s=k;
					break;
				}
			for(int k=s;k<=m;k++){
				int v = c[j].v*c[j].v+2*c[j].a*(c[j].d-p[k]);
				if(v>V*V && !c[j].chao){
					c[j].chao=1;
					num++;
				}
			}
		}
		printf("%d ", num);
		for(int j=0;j<=m;j++){
			if(j==0){
				bool flag = 0;
				for(int i=1;i<=n;j++)
					if(c[j].chao){
						flag =1;
						break;
					}
				if(flag){
					printf("%d", m);
					break;
				}
			}
			else{
				printf("%d", m/2+1);
			}
		}
		printf("\n");
	}
	return 0;
}
