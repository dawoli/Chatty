#include<bits/stdc++.h>
using namespace std;

int j = 0;

string s;

char c[1000005] = {};

bool cmp(char a , char b){
	return a > b;
}

int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			c[j] = s[i];
			j++;
		}
	}
	sort(c , c + j , cmp);
	for(int i = 0 ; i < j ; i++){
		cout << c[i];
	}
	return 0;
}
