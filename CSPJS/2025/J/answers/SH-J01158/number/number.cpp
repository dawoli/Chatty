






#include <bits/stdc++.h>
using namespace std;
int a[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;

	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	int f=0;
	for(int i=1000100;i>=0;i--){
		if(a[i]){
			for(int j=1;j<=a[i];j++){
				cout<<i;
				f=1;
			}
		}
	}
	if(!f){
		cout<<0;
	}
	return 0;
}
