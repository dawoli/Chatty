#include<bits/stdc++.h>
using namespace std;
int T,n;
int w;
string res;
bool fl = true;
int num[] = {0,1,2,3,4,5,6,7,8,9};
int vl[] = {6,2,5,5,4,5,6,3,7,6};

bool cmp(string s1,string s2){
	int sz = min(s1.size(),s2.size());
	for(int i = 0; i < sz; i ++){
		if(s1[i] > s2[i]) return 1;
		else if(s1[i] < s2[i]) return 0;
	}
	if(s1.size() > s2.size()) return 1;
	else return 0; 
}

void solve(int ws,int al,string r){
	if(ws == 0){
		if(al) return ;
		else if(al == 0){
			if(r[0] != '0'){
				cout << r << endl;
				fl = false;
			}
			return ;
		} 
	}
	for(int i = 0; i < 10; i ++){
		if(fl) solve(ws - 1,al - vl[i],r + to_string(num[i]));
//		cout << r << ' ';
	}
	return ;
}
int main(){
	ifstream cin("sticks.in");
	ofstream cout("sticks.out");
	cin >> T;
	while(T --){
		fl = true;
		cin >> n;
		res = "\0";
		if(n == 1){
			cout << -1 << endl;
			continue;
		}
//		if(n == 6){
//			cout << 6 << endl;
//			continue;
//		}
		if(n % 7) w = n / 7 + 1;
		else{
			w = n / 7;
			for(int i = 1; i <= w; i ++){
				res = res + "8";
			}
			cout << res << endl;
			continue;
		}
//		cout << w << endl;;
		solve(w,n,res);
	}
	return 0;
}
