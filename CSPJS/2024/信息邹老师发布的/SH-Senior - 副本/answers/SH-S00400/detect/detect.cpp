#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int L=1e6+10;
int T;
int n,m,l,V;
struct car{
	int d,v,a;
}c[N];
int p;
int ans1,ans2;
int vis[L];
bool det[L];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);	
	scanf("%d",&T);
	while(T--){
		ans1=ans2=0;
		memset(vis,false,sizeof(vis));
		memset(det,false,sizeof(det));

		scanf("%d%d%d%d",&n,&m,&l,&V);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p);
			det[p]=true;
		}
		
		for(int i=1;i<=n;i++){
			int v0=c[i].v;
			int a1=c[i].a;
			int d1=c[i].d;
			bool f=false;
			for(int j=d1;j<=l;j++){
				if(det[j]){//有测速仪 
					int x=j-d1;//计算位移 
					double vt=sqrt(1.0*v0*v0+2.0*a1*x);//计算瞬时速度 
					if(a1==0)vt=v0;
					if(vt<=0){ 
						break;
					}
					if(vt>V*1.0){//超速 
						vis[j]++;//可能不可关闭此处测速仪
						if(!f)ans1++;//超速车+1
						f=true;
					}
				}
			}
		}
		for(int i=1;i<=l;i++){
			if(vis[i]!=0&&det[i]){
				ans2=max(ans2,vis[i]);	
			}
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
