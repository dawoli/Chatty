#include<bits/stdc++.h>
using namespace std;
int n;
pair<string,string> t[100010];
string yuan[100010];
string hou[100010];
string gy[100010];
string gh[100010];
map<string,bool> m1;
map<string,bool> m2;
pair<string,string> not_same(string a , string b){
	if(a == b) return make_pair(a , b);
	long long st = -1 , en = -1;
	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i] and st == -1){
			st = i;
		}
		if(a[a.size() - i - 1] != b[a.size() - i - 1] and en == -1){
			en = a.size() - i - 1;
		}
		if(st != -1 and en != -1){
			break;
		}
	}
	string res1 , res2;
	long long k = a.size();
	a.erase(0,st);
	a.erase(en-st+1,k - en - 1);
	long long j = b.size();
	b.erase(0,st);
	b.erase(en - st + 1,j - en - 1);
	return make_pair(a , b);
}
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out", "w", stdout);
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		string s1 , s2;
		cin >> s1 >> s2;
		yuan[i] = s1;
		hou[i] = s2;
		t[i] = not_same(s1 , s2);
	}
	for(int i = 1; i <= m; i++){
		string s3 , s4;
		cin >> s3 >> s4;
		gy[i] = s3;
		gh[i] = s4;
		if(s3.size() != s4.size()){
			cout << 0 << endl;
			continue;
		}
		pair<string,string> t1 = not_same(s3 , s4);
		long long ans = 0;
		for(int j = 1; j <= n; j++){
			if(t[j].first == t1.first and t[j].second == t1.second and gy[i].find(yuan[j]) != string::npos and gh[i].find(hou[j]) != string::npos){
				ans++;
			}
		}
		cout << ans << endl;
	}
}
