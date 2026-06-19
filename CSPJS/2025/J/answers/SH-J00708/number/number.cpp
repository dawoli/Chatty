#include<bits/stdc++.h>
using namespace std;
string s;
int p[11];
bool t = 1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		int k = s[i] - '0';
		if(s[i] >= '0' && s[i] <= '9')p[k]++;
		if(s[i] >= '1' && s[i] <= '9')t = 0;
	}
	if(t){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= p[i];j++){
			cout << i;
		}
	}
	return 0;
}
