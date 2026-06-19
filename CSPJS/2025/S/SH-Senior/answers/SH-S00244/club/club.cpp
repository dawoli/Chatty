#include<bits/stdc++.h>
using namespace std;
#define N 200009
int n,a[N][5];
vector<int> idx[5];
bool cmp1(int x,int y){
	return a[x][1] - max(a[x][2],a[x][3]) < a[y][1] - max(a[y][2],a[y][3]);
}
bool cmp2(int x,int y){
	return a[x][2] - max(a[x][3],a[x][1]) < a[y][2] - max(a[y][3],a[y][1]);
}
bool cmp3(int x,int y){
	return a[x][3] - max(a[x][1],a[x][2]) < a[y][3] - max(a[y][1],a[y][2]);
}
inline int cal(){
	int ans = 0;
	for(int i = 0;i < idx[1].size();i++) ans += a[idx[1][i]][1];
	for(int i = 0;i < idx[2].size();i++) ans += a[idx[2][i]][2];
	for(int i = 0;i < idx[3].size();i++) ans += a[idx[3][i]][3];
	return ans;
}
inline void solve(){
	idx[1].clear();
	idx[2].clear();
	idx[3].clear();
	for(int i = 1;i <= n;i++){
		int mx = max(max(a[i][1],a[i][2]),a[i][3]);
		if(a[i][1] == mx) idx[1].push_back(i);
		else if(a[i][2] == mx) idx[2].push_back(i);
		else idx[3].push_back(i);
	}
	if(idx[1].size() <= n / 2 && idx[2].size() <= n / 2 && idx[3].size() <= n / 2){
		cout<<cal()<<endl;
		return;
	}
	sort(idx[1].begin(),idx[1].end(),cmp1);
	sort(idx[2].begin(),idx[2].end(),cmp2);
	sort(idx[3].begin(),idx[3].end(),cmp3);
	int tmp1 = idx[1].size();
	for(int i = 0;i < tmp1 - n / 2;i++){
		int j = idx[1][i];
		idx[1][i] = 0;
		if(a[j][2] > a[j][3]) idx[2].push_back(j);
		else idx[3].push_back(j);
	}
	int tmp2 = idx[2].size();
	for(int i = 0;i < tmp2 - n / 2;i++){
		int j = idx[2][i];
		idx[2][i] = 0;
		if(a[j][1] > a[j][3]) idx[1].push_back(j);
		else idx[3].push_back(j);
	}
	int tmp3 = idx[3].size();
	for(int i = 0;i < tmp3 - n / 2;i++){
		int j = idx[3][i];
		idx[3][i] = 0;
		if(a[j][1] > a[j][2]) idx[1].push_back(j);
		else idx[2].push_back(j);
	}
	cout<<cal()<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		solve(); 
	}
}

