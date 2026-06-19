#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
struct Car{
	int id,d,v,a;
	int op=0;//标记 减速=-1；从头到尾不超速：0，有超速：1 
	int s=0; //匀速&加速：从哪个位置开始超速（匀速超速即为本身）； 减速：减到哪里不超速 （始终没超速：0） 
}a[100010];
struct Road{
	int Monitor=0;
	vector<int> car;
	void clear(){
		car.clear();
	}
}l[1000010];
int n,m,L,V,T,vis[100010],vis2[100010],ans1=0,ans2=0;
int p[100010];
vector<int> monitor[100010]; 
void init(){
	scanf("%d%d%d%d",&n,&m,&L,&V);
	ans1=0,ans2=0;
	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis2));
	for(int i=0;i<=m+1;i++)
		monitor[i].clear();		
	for(int i=0;i<=L;i++)
		l[i].clear(),l[i].Monitor=0;
	for(int i=1;i<=n;i++){
		a[i].id=i;
		scanf("%d%d%d",&a[i].d,&a[i].v,&a[i].a);
		int v=a[i].v,d=a[i].d,aa=a[i].a;
		if(aa>0){
			a[i].op=1;
			if(v>=V) a[i].s=d;//一直超速 
			else{
				long double t=(long double)(V-v)/aa;
				a[i].s=d+(int)ceil((long double)v*t+0.5*aa*t*t);
				if(a[i].s>L) a[i].s=0,a[i].op=0; 
			}
		}//加速 
		else if(aa<0){
			a[i].op=-1;long double t;
			if(v<=V) a[i].s=0,a[i].op=0;
			else{
				aa=0-aa;
				t=(long double)(v-V)/aa;
				a[i].s=min(L,d+max(0,(int)floor((long double)v*t-0.5*aa*t*t)));
			}
//			if(i==5) cout<<a[i].s<<" "<<t<<" "<<(int)ceil((double)v*t-0.5*(double)aa*t*t)<<endl;
		}//减速 
		else{
			a[i].op=0;
			if(v>V) a[i].s=d,a[i].op=1; 
			else a[i].s=0;
		}//匀速 
		l[d].car.push_back(a[i].id);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
		l[p[i]].Monitor=i;
	}
	/*
	for(int i=1;i<=n;i++){
		printf("%d %d %d\n",i,a[i].s,a[i].op);
	}
	*/
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
//		for(int i=1;i<=n;i++){
//			printf("%d %d\n",a[i].op,a[i].s);
//		}
		queue<int> lis;//list 
		for(int i=0;i<=L;i++){
			if(l[i].car.size()){
				for(int j=0;j<l[i].car.size();j++){
					if(a[l[i].car[j]].op==0) continue;
					lis.push(l[i].car[j]);
				}
			}
			if(l[i].Monitor){
//			cout<<i<<endl;
				int len=lis.size();
				while(len--){
					int num=lis.front();lis.pop();
					if(a[num].op==1){//从S开始超速 
						if(i>=a[num].s){//已经超速 
							monitor[l[i].Monitor].push_back(num);
							if(!vis[num]) ans1++,vis[num]=1;
						} 
						lis.push(num); 
					}else if(a[num].op=-1){//超速到S
						if(i<=a[num].s){ 
							monitor[l[i].Monitor].push_back(num);
							if(!vis[num]) ans1++,vis[num]=1;
							lis.push(num);
						}
					}
				}
			}
		}/*
		for(int i=1;i<=m;i++){
			for(int j=0;j<monitor[i].size();j++){
				printf("%d ",monitor[i][j]);
			}
			printf("\n");
		}*/
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				if(monitor[j].size()>monitor[i].size()) swap(monitor[i],monitor[j]);
			}
		}
		for(int i=1;i<=m;i++){
			bool flag=false;
			for(int j=0;j<monitor[i].size();j++){
//					cout<<monitor[i][j]<<endl;
				if(!vis2[monitor[i][j]]){
					flag=true;
					vis2[monitor[i][j]]++;
				}
			}
			if(!flag) ans2++;
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
} 
/*
两个问题
1 测速仪全部开启  有多少来辆车超速
2 在保证超速的车都被检测，可以关掉多少测速仪 

问题1： 
对于减速：1 计算降到限速时走过多少路程
		  2 在这段路程中是否有摄像头经过
对于加速：1 走到哪里时加到限速
		  2 后续是否仍有摄像头 
*/ 
