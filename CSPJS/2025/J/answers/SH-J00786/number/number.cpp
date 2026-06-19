#include<bits/stdc++.h>
using namespace std;
string a;
bool zswdisnum(char x){
	if('0'<= x && x <= '9'){
		return true;
	}
	return false;
}
bool zswdcmp(char a,char b){
	if(a>b){
		return true;
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	sort(a.begin(),a.end(),zswdcmp);
	long long ii = 0;
	while(!zswdisnum(a[ii])){
		ii++;
	}
	while(zswdisnum(a[ii])){
		cout << a[ii];
		ii++;
	}
	return 0;
}
