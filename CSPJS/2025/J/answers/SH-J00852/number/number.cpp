#include <bits/stdc++.h>
using namespace std;
const int N=19;
string s;
int cnt[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	while(cnt[9]>0){
		cnt[9]--;
		cout<<9;
	}
	while(cnt[8]>0){
		cnt[8]--;
		cout<<8;
	}
	while(cnt[7]>0){
		cnt[7]--;
		cout<<7;
	}
	while(cnt[6]>0){
		cnt[6]--;
		cout<<6;
	}
	while(cnt[5]>0){
		cnt[5]--;
		cout<<5;
	}
	while(cnt[4]>0){
		cnt[4]--;
		cout<<4;
	}
	while(cnt[3]>0){
		cnt[3]--;
		cout<<3;
	}
	while(cnt[2]>0){
		cnt[2]--;
		cout<<2;
	}
	while(cnt[1]>0){
		cnt[1]--;
		cout<<1;
	}
	while(cnt[0]>0){
		cnt[0]--;
		cout<<0;
	}
	cout<<endl;
	return 0;
} 
