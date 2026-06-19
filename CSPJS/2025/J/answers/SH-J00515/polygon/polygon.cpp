#include<bits/stdc++.h>
using namespace std;
//
bool cmp(long long a,long long b) {
	if(a > b)return true;
	else return false;
}
//long long dfs
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	vector<int>length(n);
	long long all = 0;
	for(int i = 0;i < n;i ++){
		cin >> length[i];
		all += length[i];
	}
	sort(length.begin(),length.end(),cmp);
//	long long ans = 0;
//	for(int i = 2;i < n;++ i){
//		ans ++;
//		long long temp = length[i] + length[i-1] + length[i-2];
//		for(int j = 0;j < (i-2);++j){
//			if(temp + length[j] <= length[i] * 3)
//		}
//	}
	if(length[0] * 3 <= all)cout << 1;
	else cout << 0;
	return 0;
}
