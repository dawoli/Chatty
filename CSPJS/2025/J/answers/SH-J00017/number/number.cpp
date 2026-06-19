#include<bits/stdc++.h>
using namespace std;
bool isNum(char x){
	return '0'<=x&&x<='9';
}
int book[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	//time -O(1e6)
	for(int i=0;i<s.size();i++){
		char x=s[i];
		if(isNum(x)){
			book[x-'0']++;
		}
	}
	bool flag=1;
	for(int i=9;i>=0;i--){
		while(book[i]--){
			cout<<i;
			if(i==0&&flag){
				break;
			}
			flag=0;
		}
	}
	return 0;
}

