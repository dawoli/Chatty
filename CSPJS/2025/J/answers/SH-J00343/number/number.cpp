#include<bits/stdc++.h>
using namespace std;
string s;
int make[1100000],c(0);
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<=s.size();i++){
		if ('0'<=s[i]&&s[i]<='9'){
			make[c++]=int(s[i])-int('0');
		}
	}
	sort(make,make+c);
	for (int i=c-1;i>=0;i--){
		cout<<make[i];
	}
	cout<<endl;
	return 0;
} 
