#include<bits/stdc++.h>
using namespace std;
ifstream fin ("number.in");
ofstream fout ("number.out");
char s[1000009];
string a;
int main(){
	fin >> a;
	int ans = 1;
	for(int i = 0 ; i < a.size() ; i++){
		if(a[i] == '0' || a[i] == '1' || a[i] == '2' ||a[i] == '3' ||a[i] == '4' ||a[i] == '5' ||a[i] == '6' ||a[i] == '7' ||a[i] == '8' ||a[i] == '9'){
			s[ans] = a[i];
			ans++;
		}
	}
	sort(s + 1, s + ans + 1);
	for(int i = ans ; i > 0; i--){
		fout << s[i];
	}
	return 0;
}
