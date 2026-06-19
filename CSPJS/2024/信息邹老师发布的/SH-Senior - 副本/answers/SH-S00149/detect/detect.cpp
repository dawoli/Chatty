#include<bits/stdc++.h>
using namespace std;
int q;
struct car{
	int d,v,a,b1,b2;
	bool f=true;
}t[3010];
int n,m,l,vi;
int b[3010];
int ans1,ans2,ansnow;
int fp[3010];
void dfs(int deep,int ch){
	fp[deep]=ch;
	if(ch==0){
		ansnow++;
	}
	if(deep==m){
		bool f1=true,f2=true;
		for(int i=1;i<=n;i++){
			if(t[i].f){
				f1=false;
				for(int j=t[i].b1;j<=t[i].b2;j++){
					if(fp[j]==1){
						f1=true;
						break;
					}
				}
			}
			if(f1==false){
				f2=false;;
				break;
			}
		}
		if(f2){
			ans2=max(ans2,ansnow);
		}
		if(ch==0){
			ansnow--;
		}
		return;
	}
	dfs(deep+1,0);
	dfs(deep+1,1);
	if(ch==0){
		ansnow--;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    scanf("%d",&q);
    while(q>0){
		scanf("%d%d%d%d",&n,&m,&l,&vi);
		ans1=n;ans2=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&t[i].d,&t[i].v,&t[i].a);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&b[i]);
		}
		for(int i=1;i<=n;i++){
			int a1=t[i].a,d1=t[i].d,v1=t[i].v,vt;
			bool f1=true,f2=true;
			for(int j=1;j<=m&&f1;j++){
				if(b[j]>=d1){
					vt=v1*v1+2*a1*(b[j]-d1);
					if(vt>vi*vi){
						t[i].b1=j;
						f1=false;
					}
				}
			}
			if(f1){
				t[i].f=false;
				ans1--;
				continue;
			}
			for(int j=m;j>=t[i].b1&&f2;j--){
				if(b[j]>=d1){
					vt=v1*v1+2*a1*(b[j]-d1);
					if(vt>vi*vi){
						t[i].b2=j;
						f2=false;
					}
				}
			}
		}
		dfs(0,1);
		printf("%d %d\n",ans1,ans2);
		q--;
	}
}
