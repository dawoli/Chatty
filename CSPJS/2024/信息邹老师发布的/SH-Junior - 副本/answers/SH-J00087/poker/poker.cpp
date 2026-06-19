#include <iostream>
#include <map>
#include <cstdio>
#include <string>
using namespace std;
map <string,bool> mp;
int n,cnt;
string c1[14] = {" ","A","2","3","4","5","6","7","8","9","T","J","Q","K"};
string c2[5] = {" ","D","C","H","S"};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		string s = "";
		cin >> s;
		mp[s] = 1;
	}
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= 13;j++){
			string m = c2[i] + c1[j];
			if(!mp[m]) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
