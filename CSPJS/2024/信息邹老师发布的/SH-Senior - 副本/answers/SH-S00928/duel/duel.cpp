#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
int cate[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>> n;
	for(int i = 1;i<=n;i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int idx = 1;
	cate[idx] = 1;
	for(int i = 1;i<a.size();){
		while(a[i] == a[i-1]){
			cate[idx]++;
			i++;
		}
		cate[++idx] = 1;
		i++;
	}
	idx--;
	int maxn = 0;
	for(int i =1 ;i<=idx;i++) maxn = max(maxn,cate[i]);
	cout << maxn;
	
	return 0;
}
