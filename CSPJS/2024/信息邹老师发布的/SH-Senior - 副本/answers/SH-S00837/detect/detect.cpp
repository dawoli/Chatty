#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath> 
using namespace std;

int t;
int n,m,L,V;//车辆数量，监控数量，道路长度，限速 
int d[100086],v[100086],a[100086];//驶入位置，初速度，加速度 
int p[100086];//监控位置 
int dmax;//最靠后驶入的位置 
int pmax;//最靠后的监控 
bool flag1,flag2,flag3;//特判 匀速 加速 减速 
int ans1,ans2,anss;//超速数量，移除数量 
int cnt[100086];//每个监控拍到的超速个数 
bool f[100086],ff;

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	for(int i =1; i <=t; ++i){
		ans1 = 0,ans2 = 0,flag1 = 0,pmax = 0;//清空数据!! 
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int j =1; j <=n; ++j){//描述每辆车 
			scanf("%d%d%d",&d[j],&v[j],&a[j]);
			if(a[j])flag1 = 1;
			if(a[j]<=0)flag2 = 1;
			if(a[j]>=0)flag3 = 1;
		}
		for(int j = 1; j <=m; ++j){
			scanf("%d",&p[j]); 
			pmax = max(pmax,p[j]);
		}
		if(!flag1){
			for(int j = 1; j <=n; ++j)if(v[j]>V&&d[j]<=pmax&&d[j]<L)ans1++;
			ans2 = m-1;
			if(ans1==0)ans2++;
			printf("%d %d",ans1,ans2);
		}
		else if(!flag2){
			for(int  j = 1; j <=n; ++j){
				if(p[m]<d[j])continue;
				double vt = sqrt(2*a[j]*(p[m]-d[j])+v[j]*v[j]);
				if(vt>V){
					ans1++;
				}
			}
			ans2 = m-1;
			if(ans1==0)ans2++;
			printf("%d %d",ans1,ans2);
		}
		
		
		printf("\n");
	}
	return 0; 
} 
