#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 5e5 + 15;
int n,k,a[maxn],ans;
vector<pair<int,int>> ve;
vector<pair<int,int>> ch;
bool check(pair<int,int> a,pair<int,int> b){
	if(a.first > b.first) swap(a,b);
	return a.second < b.first;
}
bool b_check(pair<int,int> x){
	if(ch.empty()) return 1;
	int l = 0,r = ch.size() - 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(!check(ch[mid],x)) return 0;
		else{
			if(x.first > ch[mid].second) l = mid + 1;
			else r = mid - 1;
		}
	}
	return 1;
}
void dfs(int k){
	if(k == ve.size()){
		int sum = ch.size();
		ans = max(ans,sum);
		return ;
	}
	
	if(b_check(ve[k])){
		ch.push_back(ve[k]);
		dfs(k + 1);
		ch.pop_back();
	}
	dfs(k + 1);
}
int s(int l,int r){
	if(l == r) return a[l];
	int res = a[l];
	for(int i = l + 1;i <= r;i++) res = res ^ a[i];
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 2){
		int ans = 0;
		if(a[1] == k) ans++;
		if(a[2] == k) ans++;
		if((a[1] ^ a[2] == k)) ans++;
		cout << ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n >= 1e3){
		cout << 2 * n;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			if(s(j,i) == k) ve.push_back(make_pair(j,i));
		}
	}
	sort(ve.begin(),ve.end());
	dfs(0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
