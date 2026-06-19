#include <iostream>
#include <cstdio>
#include <algorithm>
long long a[1000005];
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int number=0;
	cin >> s;
	for(int i=0;i<=s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			number=s[i]-48;
			a[number]+=1;
		}
	}

	for(int i=9;i>=0;i--){
		if(a[i]>0){
		for(int j=1;j<=a[i];j++){
			cout << i;
		}
	}
	}

	
	return 0;
} 
