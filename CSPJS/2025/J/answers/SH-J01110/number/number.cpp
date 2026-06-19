#include<iostream>
#include<algorithm>
#include<string> 
using namespace std;
int main(){   
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	string digits;
	for(char c : s){
		if(isdigit(c)){
		 	digits+=c;	 
		}	
	}
	sort(digits.rbegin() , digits.rend());
	cout<< digits << endl;
	return 0; 
}
