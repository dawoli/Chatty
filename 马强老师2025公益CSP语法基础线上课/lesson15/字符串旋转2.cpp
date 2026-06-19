/*
  append()
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	cout<<s.substr(s.size()-k,k);
	cout<<s.substr(0,s.size()-k);
	return 0;
}
