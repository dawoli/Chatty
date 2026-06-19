#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n , vis[4];
struct node{
	int f,s,t;
}a[N];
struct num{
	int dg , id;
	
	bool friend operator < ( num a , num b){
		return a.dg < b.dg;
	}
};
bool cmp(node a,node b){
	return max({a.f,a.s,a.t}) > max({b.f,b.s,b.t});
}
long long ans = 0;
void dfs(int x , long long cnt){
	if( x == n + 1){
		ans = max( ans , cnt);
		return ;
	}
	if( vis[1] < n / 2){
		vis[1] ++;
		dfs(x+1,cnt+a[x].f);
		vis[1] --;
	}
	if( vis[2] < n / 2){
			
		vis[2] ++;
		dfs(x+1,cnt+a[x].s);
		vis[2] --;	
	}	
	if( vis[3] < n / 2){
			
		vis[3] ++;
		dfs(x+1,cnt+a[x].t);
		vis[3] --;	
	}
}
void solveA(){
	int maxn = 0 , cimax = 0;
	for(int i=1;i<=n;i++){
		if( a[i].f >= maxn){
			cimax = maxn;
			maxn = a[i].f;
		}
		else if( a[i].f > cimax)
			cimax = a[i].f;
	}
	cout << maxn + cimax << endl;
}
void solveB(){
	sort(a+1,a+1+n,cmp);
	long long ans = 0;
	priority_queue<num> q1 , q2;
	for(int i=1;i<=n;i++){
		if( a[i].f > a[i].s){
			if( q1.size() < n / 2){
//				cout << "1 " << i << endl;
				q1.push({a[i].f,i});
			}else if( a[i].f > q1.top().dg){
//				cout << "del1 " << i << endl; 
				q2.push({a[q1.top().id].s,q1.top().id});
				q1.pop();
				q1.push({a[i].f,i});
			}else if( a[i].f + a[q1.top().id].s > a[i].s + q1.top().dg){
//				cout << "exchange " << i << endl;
				q2.push({a[q1.top().id].s,q1.top().id});
				q1.pop();
				q1.push({a[i].f,i});
			}
		}else if( a[i].s > a[i].f){
			if( q2.size() < n / 2){
//				cout << "2 " << i << endl;
				q2.push({a[i].s,i});
			}else if( a[i].s > q2.top().dg){
//				cout << "del2 " << i << endl;
				q1.push({a[q2.top().id].f,q2.top().id});
				q2.pop();
				q2.push({a[i].s,i});
			}else if( a[i].s + a[q2.top().id].f > a[i].f + q2.top().dg){
//				cout << "exchange2 "<<i << endl;
				q1.push({a[q2.top().id].f,q2.top().id});
				q2.pop();
				q2.push({a[i].s,i});
			}
		}else{
			if( q1.size() > q2.size())
				q2.push({a[i].s,i});
			else
				q1.push({a[i].f,i});
		}
	}
	while(!q1.empty()){
		ans += q1.top().dg;
		q1.pop();
	}
	while(!q2.empty()){
		ans += q2.top().dg;
		q2.pop();
	}
	cout << ans << endl;
}
void solve(){
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i].f >> a[i].s >> a[i].t;
	int A = 0 , B = 0;
	for(int i=1;i<=n;i++){
		if( a[i].s == 0 && a[i].t == 0) A++;
		if( a[i].t == 0)B ++;
	}
	if( A == n)
		solveA();
	else if (B == n)
		solveB();
	else if( n >= 10){
		ans = 0;
		dfs(1,0);
		cout << ans << endl;
	}else{
		solveB();
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while( t --){
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
Ren5Jie4Di4Ling5%
1
4
1 2 0
2 3 0
3 3 0
5 1 0

*/
