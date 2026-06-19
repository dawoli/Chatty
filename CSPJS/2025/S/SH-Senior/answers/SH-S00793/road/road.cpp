#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+20,M = 2e6;
long long final_ans = 5e18;
int n,nown,m,nowm,k;
int c[15],a[15][N];
int newtown[15]; 
struct size{
	int x,y,d;
} st[M],en[M];
bool cmp(size a,size b){
	return a.d < b.d;
}
int fa[N];
int find(int x){
	if(fa[x] == x) return x;
	return find(fa[x]);
}
void merge(int x,int y){
	const int fx = find(x),fy = find(y);
	//if(fx != fy)
		fa[fx] = fy; 
	return;
}
long long prim(){
	//priority_queue <int,vector<int>,greater<int> > q; 
	//cout << "鸡你太美" << endl << "城镇化乡村：";
	//for(int i = 1;i <= nown-n;i++) cout << newtown[i] << ' ';
	
	//cout << endl;
	
	long long ans = 0;
	int cnt = 0,i = 1;
	while(cnt != nown-1&&i <= nowm){
		size noww = en[i];
		if(find(noww.x) != find(noww.y)){
			cnt++;
			merge(noww.x,noww.y);
			//cout << "连接边" << noww.x << ' ' << noww.y << ' ' << noww.d << endl; 
			ans += noww.d;
		}
		i++;
	}
	
	
	//cout << "ans:" << ans << endl << endl;
	
	
	if(cnt == nown-1)
		return ans;
	else return 5e18;
}

void dfs(int step,long long sumc){
	if(step > k){
		//cout << "进入成功" << endl;
		//cout << nown << " " << nowm << endl << endl;
		
		for(int i = 1;i <= nowm;i++)
			en[i] = st[i];
		
		sort(en+1,en+1+nowm,cmp);
		for(int i = 1;i <= nown;i++) fa[i] = i;
		final_ans = min(final_ans,prim()+sumc);
		
		return;
	}
	
	dfs(step+1,sumc);
	
	nown++;
	
	newtown[nown-n] = step;
	
	for(int i = nowm+1;i <= nowm+n;i++){
		st[i] = {nown,i-nowm,a[step][i-nowm]};
	}
	nowm+=n;
	dfs(step+1,sumc+c[step]);
	nown--;
	nowm-=n;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> st[i].x >> st[i].y >> st[i].d;
	}
	
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	
	nown = n,nowm = m;
	dfs(1,0);
	
	cout << final_ans << endl;
	return 0;
}
