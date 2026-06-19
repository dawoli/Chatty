#include<bits/stdc++.h>
using namespace std;
int ypy[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int i=0;
	while(i<s.size()){
		char c=s[i];
		if(c>='0'&&c<='9'){
			ypy[int(c-'0')]++;
		}
		i++;
	}
	for(int i = 9;i>=0;i--){
		for(int j = 1;j<=ypy[i];j++){
			cout<<i;
		}
	}
	return 0;
}
