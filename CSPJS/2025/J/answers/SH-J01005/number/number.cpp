#include<bits/stdc++.h>
using namespace std;
int book[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int w=s.size();
	for(int i=0;i<w;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-48;
			book[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=book[i];j++){
			cout<<i;
		}
	}
	return 0;
}
