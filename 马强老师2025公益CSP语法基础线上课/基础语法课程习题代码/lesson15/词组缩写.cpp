/*
  
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(cin>>s){
		//cout<<s<<endl;
		if(s[0]>='a'&&s[0]<='z')
			s[0]-=32;
		cout<<s[0];
	}
	return 0;
}
