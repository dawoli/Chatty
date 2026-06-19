#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 100010
using namespace std;
int T,n,m,L,V,det[maxn],detr[maxn][2],vis[maxn],diff[maxn];
struct car{
	int d,v,a;
}cars[maxn];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){;
    	memset(detr,0,sizeof(detr));
    	memset(vis,0,sizeof(vis));
    	scanf("%d%d%d%d",&n,&m,&L,&V);
    	int V2=V*V;
    	for(int i=1;i<=n;++i){
    		scanf("%d%d%d",&cars[i].d,&cars[i].v,&cars[i].a);
		}for(int i=1;i<=m;++i){
			scanf("%d",&det[i]);
		}
		//sort(det+1,det+1+m);
		int ans=0,pt,pos,pos1,lc;
    	for(int i=1;i<=n;++i){
    		if(cars[i].a==0){
    			if(cars[i].v<=V)continue;
    			pos=lower_bound(det+1,det+1+m,cars[i].d)-det;
    			//cout<<pos<<'\n';
				if(pos<=m){
					++ans;
					detr[i][0]=pos,detr[i][1]=m; 
				}
			}else{
				lc=(V2-cars[i].v*cars[i].v) / (2*cars[i].a);
				//cout<<lc<<' ';
				if(cars[i].a<0){
					if((V2-cars[i].v*cars[i].v) % (2*cars[i].a))++lc;
					if(lc<=0)continue;
					pos=lower_bound(det+1,det+1+m,cars[i].d)-det;
					pos1=lower_bound(det+1,det+1+m,cars[i].d+lc)-det;
					if(pos!=pos1){
						++ans;
						detr[i][0]=pos,detr[i][1]=pos1-1; 
					}
				}
				else{
					++lc;
					if(lc<0)pt=cars[i].d;
					else pt=cars[i].d+lc;
					pos=lower_bound(det+1,det+1+m,pt)-det;
					if(pos<=m){
						++ans;
						detr[i][0]=pos,detr[i][1]=m; 
					}
				}
			}
		}
		int lft=ans,cnt=0,maxs=-1,maxk,sum;
		for(int i=1;i<=n;++i){
			if(!detr[i][0])continue;
			++diff[detr[i][0]],--diff[detr[i][1]+1];
			//printf("%d %d\n",detr[i][0],detr[i][1]);
		}
		while(lft>0){
			++cnt;
			
			maxs=0,sum=0;
			for(int k=1;k<=m;++k){
				//cout<<diff[k]<<' ';
				sum+=diff[k];
				if(maxs<sum){
					maxs=sum;
					maxk=k;
				}
			}
			lft-=maxs;
			//cout<<maxs<<'/'<<lft<<'\n';
			for(int i=1;i<=n;++i){
				if(maxk>=detr[i][0]&&maxk<=detr[i][1]&& !vis[i]){
					vis[i]=1;
					--diff[detr[i][0]],++diff[detr[i][1]+1];
				}
			}
		}
		printf("%d %d\n",ans,m-cnt);
	}
    
    fclose(stdin);
	fclose(stdout); 
    return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15

3 3

1
3 5 15 3
0 4 0
14 100 1
0 0 1
2 5 8 9 15
---
1
9 10 158022 5
65435 666 -3
1342 672 -2
10867 862 -8
110389 708 -9
1709 920 -8
130502 291 626
80612 947 -10
48629 783 -3
107502 903 -10
15014 53560 78649 88021 91322 104253 111591 117138 138176 152757

9 7
*/
