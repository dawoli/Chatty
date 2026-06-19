#include <bits/stdc++.h>
using namespace std;
string s;
int a[10];
int rp; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	rp++;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			a[i]--;
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
