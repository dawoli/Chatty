#include<bits/stdc++.h>
using namespace std;
struct car{
	int d,v,a;
	int l,r;
}a[100001];
bool p[1000001];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	scanf("%d",&t);
	int n,m,L,V;
	int maxover=0,sum=0;
	for(int ti=0;ti<t;ti++){
		memset(p,0,sizeof(p));
		scanf("%d%d%d%d",&n,&m,&L,&V);
		maxover=0;
		sum=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i].d,&a[i].v,&a[i].a);
			if(a[i].a==0){
				if(a[i].v<=V){
					a[i].r=-1;
				} 
				else{
					a[i].l=a[i].d;
					a[i].r=L+1;
				}
			}
			else if(a[i].a>0){
				if(a[i].v>V){
					a[i].l=a[i].d;
					a[i].r=L+1;
				} 
				else{
					float m=(pow(V,2)-pow(a[i].v,2))/(2*a[i].a);
					if(a[i].d+m>=L){
						a[i].r=-1;
					}
					else if(m>floor(m)){
						a[i].l=a[i].d+ceil(m);
						a[i].r=L+1;
					}
					else{
						a[i].l=a[i].d+floor(m)+1;
						a[i].r=L+1;
					}
				}
			}
		}
		int te;
		for(int i=0;i<m;i++){
			scanf("%d",&te);
			p[te]=1;
			sum++;
		}
		for(int i=0;i<n;i++){
			if(a[i].r==-1) continue;
			for(int j=a[i].l;j<=L;j++){
				if(p[j]){
					maxover++;
					break;
				}
			}
		}
		if(maxover!=0) sum--;
		printf("%d %d\n",maxover,sum);
	}
	return 0;
}
