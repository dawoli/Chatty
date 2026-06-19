#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	long long j=0,ls;
	cin>>s;
	ls=s.size();
	for(int i=0;i<ls;i++){
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int k=1;k<=a[i];k++){
			cout<<i;
		}
	}
	return 0;
}
