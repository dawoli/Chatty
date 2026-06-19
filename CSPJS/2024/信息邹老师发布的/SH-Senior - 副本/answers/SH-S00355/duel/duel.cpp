#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	vector<int>m;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int t;
		cin>>t;
		m.push_back(t);
	}
	sort(m.begin(),m.end());
	for(int i:m){
		if(i>m.front()){
			m.erase(m.begin());
		}
	}
	cout<<m.size();
	return 0;
}
