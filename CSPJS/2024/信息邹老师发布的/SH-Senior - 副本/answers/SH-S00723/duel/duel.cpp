#include<bits/stdc++.h>
using namespace std;
int n;
map<int,int> m;
set<int> s;
deque<int> dq;
vector<pair<int,int> > v;
int ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	ans = n;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		m[a]++;
		s.insert(a);
	}
	for(auto x : s){
		v.push_back({x,m[x]});
	}
	sort(v.begin(),v.end());
	for(auto i : v){
		dq.push_back(i.second);
	}
	while(dq.size()>=2){
		int a = dq.front();
		dq.pop_front();
		int b = dq.front();
		dq.pop_front();
		if(a == b){
			ans -= a;
		} 
		else if(a > b){
			ans -= b;
			b = a;
		}
		else{
			ans -= a;
		}
		dq.push_front(b);
	}
	cout << ans;
	return 0;
} 
