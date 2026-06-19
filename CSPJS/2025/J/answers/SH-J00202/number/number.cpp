#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(cnt,0,sizeof(cnt));
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		cnt[s[i]-'0']++;
	}
	string str="";
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++)
			str+=char(i+'0');
	}
	cout<<str;
	return 0;
}
