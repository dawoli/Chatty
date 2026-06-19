#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	map<int,int>d;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			d[s[i]-'0']++;
		}
	}
	for(int x=9;x>=0;x--){
		for(int i=1;i<=d[x];i++){
			cout <<x;
		}
	}
	return 0;
}
