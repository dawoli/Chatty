#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

const int maxn = 55;
struct node{
	int s;
	bool flag;
};
bool cmp(node a,node b){
	return a.s > b.s;
}
vector<node> a = {{0,0}};
int n,m,x,y,mp[maxn][maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		int x;
		cin >> x;
		if(i == 1) a.push_back({x,1});
		else a.push_back({x,0});
	}
	sort(a.begin() + 1,a.end(),cmp);
	int nx = 1,ny = 1,add = 1;
	for(int i = 1;i < a.size();i++){
		mp[nx][ny] = a[i].s;
		if(a[i].flag){
			cout << ny << " " << nx;
			break;
		}
		if(nx == n && mp[nx - 1][ny] > 0){
			nx = n,ny++;
			add = -add;
			continue;
		}
		else if(nx == 1 && mp[nx + 1][ny] > 0){
			nx = 1,ny++;
			add = -add;
			continue;
		}
		else{
			nx += add;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
