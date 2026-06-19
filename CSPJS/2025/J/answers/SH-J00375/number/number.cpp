#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<set>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	string in;
	multiset<char,greater<char>> nums;
	cin>>in;
	for(char c:in){
		if('0'<=c&&c<='9'){
			nums.insert(c);
		}
	}
	bool is = 0;
	for(char c:nums){
		if(!is&&c!='0') is = 1;
		if(is) cout<<c;
	}
	if(!is)cout<<'0';
	return 0;
}
