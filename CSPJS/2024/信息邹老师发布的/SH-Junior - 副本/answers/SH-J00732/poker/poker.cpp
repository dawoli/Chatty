#include<bits/stdc++.h>
using namespace std;
int hashList[52] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int n;
int ans = 0, tmp;
string poker = "";
int solve(string str){
	int ret;
	if(str[0] == 'D') ret = 0;
	else if(str[0] == 'C') ret = 13;
	else if(str[0] == 'H') ret = 26;
	else if(str[0] == 'S') ret = 39;
	if(str[2] == 'A') ret += 0;
	else if(str[2] == '2') ret += 1;
	else if(str[2] == '3') ret += 2;
	else if(str[2] == '4') ret += 3;
	else if(str[2] == '5') ret += 4;
	else if(str[2] == '6') ret += 5;
	else if(str[2] == '7') ret += 6;
	else if(str[2] == '8') ret += 7;
	else if(str[2] == '9') ret += 8;
	else if(str[2] == 'T') ret += 9;
	else if(str[2] == 'J') ret += 10;
	else if(str[2] == 'Q') ret += 11;
	else if(str[2] == 'K') ret += 12;
	return ret;
}
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin>>n;
	for(int i = 0;i < n;i ++){
		cin>>poker;
		tmp = solve(poker);
		hashList[tmp] = 0;
	}
	for(int i = 0;i < 52;i ++){
		ans += hashList[i];
	}
	cout<<ans;
	return 0;
}
