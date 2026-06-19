#include <bits/stdc++.h>

using namespace std;

struct student{
	int score;
	bool is_R, vis;
};

int n, m;

bool cmp(student x, student y){
	return x.score > y.score;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	vector<student> v;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int x;
			cin >> x;
			if(i == 1 && j == 1)
				v.push_back({x, true, false});
			else
				v.push_back({x, false, false});
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	int c = 1, r = 1, idx = 0;
	bool flag = false;
	while(c != m + 1){
		v[idx].vis = true;
		if(v[idx].is_R == true){
			cout << c << " " << r << endl;
			break;
		}
		idx++; 
		if(flag)
			r--;
		else 
			r++;
		if(r == n + 1 || r == 0){
			if((idx / n) % 2 == 1) flag = true, c++, r = n;
			else flag = false, c++, r = 1; 
		}
		
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
