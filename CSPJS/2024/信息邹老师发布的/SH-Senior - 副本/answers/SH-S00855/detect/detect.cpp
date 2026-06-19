#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T, n, m, cnt[100009], ans, del;
ll V, L;
int rec1[100009], rec2[100009];	//rec1记录所有超速车辆，rec2记录当前解决的超速数量 
struct AuMob{
	ll d;			//Entry Point
	ll v;			//Startup Velocity
	ll a;			//accelerete
};
struct Detector{
	ll pos;
	vector<int> DetList;
}; 
AuMob a[100009];
Detector d[3009];
void dfs(int num,int dl,int doit){
	if(num>n) return;
	del = max(del,dl);
	for(int i=1 ; i<=n ; i++){
		if((rec1[i]>0) != (rec2[i]>0)){
			return;				//删多了 
		}
	}
	if(doit){
		for(int i=0 ; i<d[num].DetList.size() ; i++){
			rec2[d[num].DetList[i]]--;
		}
	}
	dfs(num+1,dl+doit,0);
	dfs(num+1,dl+doit,1);
	if(doit){
		for(int i=0 ; i<d[num].DetList.size() ; i++){
			rec2[d[num].DetList[i]]++;
		}
	}
}
//对于每辆车，计算其在所有测速点的速度
//对于每个测速仪，记录其编号，以及存储的车辆列表 
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T > 0){
		ans = del = 0;
		cin>>n>>m>>L>>V;
		for(int i=1 ; i<=n ; i++){
			rec1[i] = 0; rec2[i] = 0;
		}
		for(int i=1 ; i<=m ; i++){
			d[i].DetList.clear();
		}
		for(int i=1 ; i<=n ; i++){
			cin>>a[i].d>>a[i].v>>a[i].a;
		}
		for(int i=1 ; i<=m ; i++)
			cin>>d[i].pos;
		for(int i=1 ; i<=n ; i++){		//枚举车 
			for(int j=1 ; j<=m ; j++){	//枚举探头 
				if(d[j].pos < a[i].d)
					continue;
				ll vel_sq = a[i].v*a[i].v+2*a[i].a*(d[j].pos-a[i].d);
				if(vel_sq > V*V){
					rec1[i]++;
					rec2[i] = rec1[i];
					d[j].DetList.push_back(i);
				}
				else{
					if(a[i].a <= 0)
						break;
				}
			}
		}
		for(int i=1 ; i<=n ; i++)
			if(rec1[i]) ans++;
		dfs(1,0,0);
		dfs(1,0,1);
		cout<<ans<<' '<<del<<'\n';
		T--;
	}
	return 0;
}
