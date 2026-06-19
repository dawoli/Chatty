#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s; 
	int c[12] = {0};
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i] == '0') c[0]+=1;
		if(s[i] == '1') c[1]+=1;
		if(s[i] == '2') c[2]+=1;
		if(s[i] == '3') c[3]+=1;
		if(s[i] == '4') c[4]+=1;
		if(s[i] == '5') c[5]+=1;
		if(s[i] == '6') c[6]+=1;
		if(s[i] == '7') c[7]+=1;
		if(s[i] == '8') c[8]+=1;
		if(s[i] == '9') c[9]+=1;
	}for(int i=9;i>=0;i--){
		for(int j=0;j<c[i];j++){
			cout << i;
		}
	}
	return 0;
} 
