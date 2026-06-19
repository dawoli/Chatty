#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,v;
struct node{
	int d,v,a;
}a[100005];
int poss[100005];
int q[100005];
int common;
int ans1=INT_MAX;
int detect(){
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i].a==0){
			if(a[i].v==0){
				if(poss[m-1]>=a[i].d) ans++;
			}
		}else if(a[i].a<0){
			for(int j=0;j<m;j++){
				int speed=ceil(sqrt(a[i].v*a[i].v+2*a[i].a*(poss[j]-a[i].d)));
				if(speed<=0) break;
				if(poss[i]!=-1 && speed>v){
					ans++;break;
				}
			}
		}else{
			for(int j=m-1;j>0;j--){
				if(poss[i]!=-1 && ceil(sqrt(a[i].v*a[i].v+2*a[i].a*(poss[j]-a[i].d)))>v){
					ans++;break;
				}
			}
		}
	}
	return ans;
}
void dfs(int step,int cnt){
	if(step==m){
		ans1=min(ans1,cnt);
		return;
	}
	int temp=poss[step];
	poss[step]=-1;
	if(detect()==common) dfs(step+1,cnt);
	poss[step]=temp;
	dfs(step+1,cnt+1);
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	for(int times=0;times<t;times++){
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i].d,&a[i].v,&a[i].a);
		}for(int i=0;i<m;i++){
			scanf("%d",&poss[i]);
		}
		common=detect();
		printf("%d",common);
		ans1=INT_MAX;
 		dfs(0,0);
		printf(" %d\n",ans1);
	}
}
