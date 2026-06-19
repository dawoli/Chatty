#include <bits/stdc++.h>
using namespace std;
int t;
int n,max_people;
int a[100009][3];
int club[3];

bool cmp(int a, int b){
	return a > b;
}
void f(int idx,long long tot, vector<long long> &p){
	if(idx >= n){
		p.push_back(tot);
		return;
	}
	for(int i=0; i<3; i++){
		if(club[i] > max_people-1){
			continue;
		}
		club[i]++;
		tot += a[idx][i];
		f(idx+1,tot,p);
		tot -= a[idx][i];
		club[i]--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> n;
		max_people = n / 2;
		bool is_a230 = true;
		bool is_a30 = true;
		for(int j=0; j<n; j++){
			cin >> a[j][0] >> a[j][1] >> a[j][2];
			if(a[j][1] != 0 || a[j][2] != 0){
				is_a230 = false;
			}
			if(a[j][2] != 0){
				is_a30 = false;
			}
		}
		if(n == 2){
			int x = max(a[0][0] + a[1][1],a[0][0] + a[1][2]);
			int y = max(a[0][1] + a[1][0],a[0][1] + a[1][2]);
			int z = max(a[0][2] + a[1][0],a[0][2] + a[1][1]);
			cout << max(max(x,y),z) << endl;
		}else if(n <= 100000 && is_a230){
			vector<int> p;
			for(int k=0; k<n; k++){
				p.push_back(a[k][0]);
			}
			sort(p.begin(), p.end(), cmp);
			long long tot = 0;
			for(int j=0; j<max_people; j++){
				tot += p[j];
			}
			cout << tot << endl;
		}else if(is_a30){
			vector<int> p;
			for(int k=0; k<n; k++){
				p.push_back(a[k][0]-a[k][1]);
			}
			sort(p.begin(), p.end(),cmp);
			long long tot = 0;
			for(int j=0; j<max_people; j++){
				tot += a[j][0];
			}
			for(int j=max_people; j<n; j++){
				tot += a[j][0] - p[j];
			}
			cout << tot << endl;
		}else if(n <= 10){
			vector<long long> p;
			f(0,0,p);
			sort(p.begin(),p.end(),cmp);
			cout << p[0] << endl;
		}
	}
	
	return 0;
}
