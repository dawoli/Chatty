#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string a[100000], b[100000];
int l[100005];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	if(n<=100){
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		l[i] = a[i].size();
	}
	while(q--){
		string s1, s2;
		cin >>s1 >> s2;
		int l1 = s1.size();
		int l2 = s2.size();
		if(l1!=l2){
			cout << 0 << endl;
			continue;
		}
		int res = 0;
		for(int i = 0; i < l1; i++){
			for(int j = 1; j<=n; j++){
				if(s1.substr(i, l[j])==a[j]){
					string tmp = s1;
					string ss1 = tmp.substr(0, i), ss2 = b[j], ss3 = tmp.substr(i+l[j]);
					string tp = ss1 + ss2 + ss3;
					if(tp==s2)res++;
				}
			}
		}
		cout << res << endl;
	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
}
