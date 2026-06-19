#include<bits/stdc++.h>

using namespace std;

const int maxN=100000;

int T; //数据组数
int n,m,L,V;
//车辆数，测速仪数，主干道长度，道路限速

int di[maxN+5];
int vi[maxN+5];
int ai[maxN+5];
int p[maxN+5];

vector<int> caught[maxN+5];
//记录超速的车被那些测速仪抓了 
int cntcc=0;//超速的车数量 

int work(){
	
	scanf("%d%d%d%d", &n,&m,&L,&V);
	
	for(int i=1;i<=n;i++){
		scanf("%d%d%d", &di[i], &vi[i], &ai[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d", &p[i]);
	}
	sort(p+1, p+1+m);//对p排序
	
	cntcc=0;//超速的车数量 
	
	for(int i=1;i<=n;i++){
		int d=di[i], v=vi[i], a=ai[i];
		//对于a分类讨论
		if(a==0){
			if(v>V){
				int *firstp=lower_bound(p+1, p+1+m, d);//大于等于d的第一个位置
				long long j=firstp-p;
				if(j>m)continue;
				while(j<=m){
					caught[cntcc].push_back(j);
					j++;
				}
				cntcc++;
			}
		}else if(a>0){
			int chaosu=(V*V-v*v)/(2*a);
			if( (V*V-v*v)%(2*a)!=0 )chaosu++;
			chaosu+=d;
			int *firstp=lower_bound(p+1, p+1+m, chaosu);//大于等于chaosu的第一个位置 
			
			long long j=firstp-p;
			if(j>m)continue;
			while(j<=m){
				caught[cntcc].push_back(j);
				j++;
			}
			cntcc++;
		}else{//(a<0)
			if(v<=V)continue;
			int chaosu=(V*V-v*v)/(2*a);//向下取整
			chaosu+=d;
			int *lastp=upper_bound(p+1,p+1+m,chaosu);
			long long j=lastp-p-1;
			if(j<1 || p[j]<d )continue;//p是从1开始存的，如果小于1说明不存在
			while(j>=1 && p[j]>=d){
				caught[cntcc].push_back(j);
				j--;
			}
			sort(caught[cntcc].begin(), caught[cntcc].end());
			cntcc++;
		}
	}
	
	printf("%d ", cntcc);
	
	return 0;
}


int ansdfs=0x3f3f3f3f;
//看可以减少那些测速器（Brutal Force） 
int work2dfs(){
	
	return 0;
} 

int main(){
	
	//freopen("detect.in", "r", stdin);
	//freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	for(int i=0;i<T;i++){ 
		work();
	} 
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
