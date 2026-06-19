#include <iostream>
#include<string>
#include<cstring>
using namespace std;
int number[15];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			int digit = s[i] - '0';
			number[digit]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<number[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
