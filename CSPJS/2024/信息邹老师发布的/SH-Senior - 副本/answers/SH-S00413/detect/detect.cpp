#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
struct Car{
	int goin,goout;
}cars[N];

bool tst[N];
int tsts[N];
double T,n,m,L,V;
vector<Car> cars2;
vector<int> spdtst[N];
int tot = 0;
int cnts[N];
int ans = 1e9;

bool cmp(const Car&x,const Car&y){
	return x.goin < y.goin || (x.goin == y.goin && x.goout >= y.goout);
}

void dfsans(int dep,int sum){
	if (dep > tot){
		
		for (int i = 0;i < (int)cars2.size();i++){
			if (cnts[i] <= 0) return;
		}
		ans = min(ans,sum);
		return;
	}
	
	dfsans(dep+1,sum);   //不选下标为dep的测速仪 
	
	for (int i = 0;i < (int)spdtst[dep].size();i++) cnts[spdtst[dep][i]]++;
	dfsans(dep+1,sum+1);														//选下标为dep的测速仪 
	for (int i = 0;i < (int)spdtst[dep].size();i++) cnts[spdtst[dep][i]]--;
	
}
/*
bool isin(int x,int y){   //spdtst的x号是否是spdtst 的y号的子集 
	if (spdtst[x].empty()) return 1;
	if (spdtst[y].empty()) return 0;
	if (spdtst[x].size() >= spdtst[y].size()) return 0;
	for (int i = 0;i < spdtst[x].size();i++){
		bool ok = 0;
		for (int j = 0;j < spdtst[y].size();j++){
			if (spdtst[x][i] == spdtst[y][j]){
				ok = 1;
				break;
			}
		}
		if (ok == 0) return 0;
	}
	return 1;
}

*/


void solve2(){
	ans = 1;
} 
void solve3(){
	ans = 1;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	cin>>T;
	while (T--){
		bool cansolve2 = 1;
		bool cansolve3 = 1;
		int cnt = 0;
		ans = 1e9;tot = 0;
		cars2.clear();
		for (int i = 0;i < N;i++){
			tst[i] = 0;
			spdtst[i].clear();
			cnts[i] = 0;
		}
		
		cin>>n>>m>>L>>V;
		for (int i = 1;i <= n;i++){
			double d,v,a;
			cin>>d>>v>>a;
			if (a == 0){
				cansolve2 = 0;
				if (v <= V){
					cars[i].goin = 0;
					cars[i].goout = 0;
				}else{
					cars[i].goin = d;
					cars[i].goout = L;
				}
			}else if (a > 0){
				cansolve3 = 0;
				double s = 1.0*(V*V-v*v)/(2*a);
				if (s < 0){
					cars[i].goin = d;
					cars[i].goout = L;
				}else{
					cars[i].goin = floor(s+1);
					cars[i].goout = L;
				}
			}else{
				cansolve2 = 0;
				cansolve3 = 0;
				double s = 1.0*(V*V-v*v)/(2*a);
				if (s < 0){
					cars[i].goin = 0;
					cars[i].goout = 0;
				}else{
					cars[i].goin = d;
					cars[i].goout = min(L,ceil(d+s-1));
				}
			}
			
		}
		for (int i = 1;i <= m;i++){
			int p;
			cin>>p;
			tst[p] = 1;
		}
		
		for (int i = 1;i <= L;i++){
			tsts[i] = tsts[i-1] + tst[i];
		}
		
		for (int i = 1;i <= n;i++){
			int l = cars[i].goin;
			int r = cars[i].goout;
			
			if (l == 0 || r < l || l > L) continue;
			if (tsts[r] - tsts[l-1] <= 0) continue;
			cars2.push_back(cars[i]);
			cnt++;
		}
		cout<<cnt<<' ';
		
		for (int i = 1;i <= L;i++){
			if (tst[i]){
				++tot;
				for (int j = 0;j < (int)cars2.size();j++){
					if (cars2[j].goin <= i && i <= cars2[j].goout){
						spdtst[tot].push_back(j);
					}
				}
			}
		}
		
		if (cansolve2 && n > 20) solve2();
		if (cansolve3 && n > 20) solve3();
		else dfsans(1,0);
		
		cout<<m-ans<<endl;
	}
	return 0;
}
