#include <bits/stdc++.h>
using namespace std;
int pot[10000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i=0; i<s.size(); i++){
		if ('0'<=s[i] && s[i]<='9'){
			pot[s[i]-'0']++;
		}
	}
	//From Large To Small!
	for (int i=9; i>=0; i--){
		for (int j=1; j<=pot[i]; j++){
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
8:31 Open This
8:33 Easy one Start!
8:38 Finish
8:42 Passed Samples Exp 100.0
*/
