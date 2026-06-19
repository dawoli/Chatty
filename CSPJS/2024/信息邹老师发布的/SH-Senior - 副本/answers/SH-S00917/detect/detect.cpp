#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int T,n,m,L0,V0,cnt,p[100005],pqzh[1000005],limax;
struct li{//区间 
	int l,r;//为[]
	bool prom;//保证可行，后面随便删
}arr[100005]; 
struct mycar{
	int d,v,a;
}dt[100005];
inline int mycei(double x){
	return (int)x+1;
}
inline int myflo(double x){
	if(double(int(x))==x) return int(x-1);
	return int(x);
}
inline int mn1(int d){
	if(d) return d-1;
	return 1000003;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		//清空数据 
		memset(p,0,sizeof(p));
		memset(pqzh,0,sizeof(pqzh));
		limax=0;
		cnt=0;
		for(int i=0;i<100005;i++){
			arr[i].l=0;
			arr[i].r=0;
			arr[i].prom=0;
			dt[i].d=0;
			dt[i].a=0;
			dt[i].v=0;
		}
		cin>>n>>m>>L0>>V0;
		for(int i=1;i<=n;i++){
			cin>>dt[i].d>>dt[i].v>>dt[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=m;i++){
			pqzh[p[i]]++;
		}
		for(int i=1;i<=L0;i++){
			pqzh[i]+=pqzh[i-1];
		}//前缀和 
		for(int i=1,d,v,a;i<=n;i++){
			d=dt[i].d;
			v=dt[i].v;
			a=dt[i].a;
			if(a==0){
				if(v>V0){
					//[d,L0]超速 
					if(pqzh[L0]>pqzh[mn1(d)]){
						cnt++;//超速个数 
						arr[++limax].l=d;
						arr[limax].r=L0;
					}
				} 
			}else if(a>0){
				if(v>V0){
					//[d,L0]
					if(pqzh[L0]>pqzh[mn1(d)]){
						cnt++;//超速个数 
						arr[++limax].l=d;
						arr[limax].r=L0;
					}
				}else{
					double stp=(double)(V0*V0-v*v)/(2.0*a);
					stp=stp+d;
					//(stp,L0]或无 
					if(stp<L0){
						if(pqzh[L0]>pqzh[mn1(mycei(stp))]){
							cnt++;//超速个数 
							arr[++limax].l=mycei(stp);
							arr[limax].r=L0;
						}
					}
				}
			}else if(a<0){
				if(v>V0){
					double enp=(double)(V0*V0-v*v)/(2.0*a);
					enp=enp+d;
					//[d,enp)或[d,L0] 
					if(enp<=L0){
						if(pqzh[myflo(enp)]>pqzh[mn1(d)]){
							cnt++;//超速个数 
							arr[++limax].l=d;
							arr[limax].r=myflo(enp);
						}
					}else{
						if(pqzh[L0]>pqzh[mn1(d)]){
							cnt++;//超速个数 
							arr[++limax].l=d;
							arr[limax].r=L0;
						}
					}
				}
			}
		}
		cout<<cnt<<" ";
		int dcntt=0;
		for(int i=1;i<=m;i++){//枚举测速 
			bool flag=1; 
			for(int j=1;j<=limax;j++){//枚举区间 
				if(arr[j].r<p[i]||arr[j].l>p[i]) continue;
				if(!arr[j].prom&&(pqzh[arr[j].r]-pqzh[p[i]])==0){
					//不能删 
					flag=0;
					break;
				}
			}
			if(flag){//del
				dcntt++;
			}else{
				for(int j=1;j<=limax;j++){//枚举区间 
					if(arr[j].r>=p[i]&&arr[j].l<=p[i]){
						arr[j].prom=1;
					}
				}
			}
		}
		cout<<dcntt<<'\n';
	}
	return 0;
}

