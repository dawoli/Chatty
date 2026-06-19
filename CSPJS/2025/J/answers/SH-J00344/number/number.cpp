#include<bits/stdc++.h>
using namespace std;

string s;
int num[100007];
int n,a = 0;

long long p = 1,ans = 0;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if('0' <= s[i] && s[i] <= '9'){
			num[a] = s[i] - '0';
			a++;
		}
	}
	for(int k = 0;k < a;k++){
		for(int c = 0;c < a - k - 1;c++){
			if(num[c] > num[c + 1]){
				n = num[c];num[c] = num[c + 1];num[c + 1] = n;}
		}
	}
	for(int w = 0;w < a;w++){
		ans += num[w] * p;
		p = p * 10;
	}
	cout << ans << endl;
	return 0;
}
