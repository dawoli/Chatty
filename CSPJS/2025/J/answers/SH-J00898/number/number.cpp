#include<bits/stdc++.h>
using namespace std;
string s;
int haxi[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			haxi[s[i]-'0']++;
		} 
	}
	for(int i=9;i>=0;i--){
		while(haxi[i]){
			cout<<i;
			haxi[i]--;
		}
	}
	return 0;
}
