#include<bits/stdc++.h>
using namespace std;
struct Score{
	int val;
	int idx;
};
bool compare(const Score& a, const Score& b){
	return a.val >b.val;
}
int main(){   
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int total = n * m;
	vector<Score> scores;
	for(int i = 0; i < total; ++i){
		int val;
		cin >> val;
		scores.push_back({val,i});
	}
	sort(scores.begin(),scores.end(),compare);
	int targetIdX = scores[1].idx;
	int c = targetIdX % m + 1;
	int r = targetIdX / m + 1;
	cout << c << " " << r << endl; 
	
}
