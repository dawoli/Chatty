#include<bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 10,maxm = 3000 + 10,maxl = 1e6 + 10;
int t,n,m,len,v,ans1,ans2;
int p[maxm],sump[maxl];
bool vis[maxn];
struct node{
	int d,a,s;
	bool flag;
}car[maxn];
struct node2{
	int num,calc;
	int g[maxn]; 
}detect[maxm];

int up(int a,int b){
	return (a + b - 1) / b;
}

bool cmp(node2 a,node2 b){
	return a.calc > b.calc;
}

void init(){
	ans1 = 0;
	ans2 = 0;
	for(int i = 1;i <= m;i ++){
		detect[i].num = 0;
	} 
	memset(sump,0,sizeof(sump));
	memset(p,0,sizeof(p)); 
	memset(vis,false,sizeof(vis));
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t --){
		init();
		scanf("%d %d %d %d",&n,&m,&len,&v);
		for(int i = 1;i <= n;i ++){
			scanf("%d %d %d",&car[i].d,&car[i].s,&car[i].a);
			car[i].flag = false;
		}
		for(int i = 1;i <= m;i ++){
			scanf("%d",&p[i]);
			sump[p[i]] = 1;
		}
		for(int i = 0;i <= len;i ++){
			if(i > 0)	sump[i] += sump[i - 1];
		}
		for(int i = 1;i <= n;i ++){
			int l,r; 
			if(car[i].s > v){
				if(car[i].a >= 0){
					l = car[i].d; r = len;
				}else{
					l = car[i].d;
					r = min(car[i].d + (car[i].s * car[i].s - v * v) / (-2 * car[i].a),len);
				}
			}else{
				if(car[i].a > 0){
					l = min(car[i].d + up(v * v - car[i].s * car[i].s,2 * car[i].a),len + 1);
					r = len;
				}else{
					l = 0; r = 0; 
				}
			}
			if(sump[r] - sump[l - 1] >= 1){
				car[i].flag = true;
				for(int j = 1;j <= m;j ++){
					if(l <= p[j] && p[j] <= r)	detect[j].g[++ detect[j].num] = i;
				}
			}
		}
		for(int i = 1;i <= m;i ++){
			detect[i].calc = detect[i].num;
		} 
		for(int i = 1;i <= n;i ++){
			if(car[i].flag)	ans1 ++;
		}
		for(int i = 1;i <= m;i ++){
			bool flag = false;
			sort(detect + i,detect + m + 1,cmp);
			for(int j = 1;j <= detect[i].num;j ++){
				if(!vis[detect[i].g[j]]){
					vis[detect[i].g[j]] = true;
					flag = true;
				}
			}
			if(!flag)	ans2 ++;
			for(int j = i + 1;j <= m;j ++){
				for(int k = 1;k <= detect[j].num;k ++){
					if(vis[detect[j].g[k]])	detect[j].calc --;
				}
			}
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
