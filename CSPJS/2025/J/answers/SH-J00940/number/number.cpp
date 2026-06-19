#include<bits/stdc++.h>
#include<cstring>
using namespace std;
	int ton[15];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i=0; i < (signed)s.size(); i++){
		if(s[i]>='0' && s[i]<='9'){
			ton[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0; i--){
		for(int j=1; j<= ton[i];j++){
			cout << i;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
} 
