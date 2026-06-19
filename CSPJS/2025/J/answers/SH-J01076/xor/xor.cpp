//CCFÌ«ÉÆÁ¼ÁË 
#include <bits/stdc++.h>
#include <string>
using namespace std;
string bin(long long a){
	string s;
	while(a){
		char ch=char(a%2+48);
		s.insert(s.begin(),ch);
		a/=2;
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cout<<bin(6);
	return 0;
} 
