//CCFÌ«ÉÆÁ¼ÁË 
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string s;
char a[1000005];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.length();
	for(long long i=0;i<n;i++){
		a[i]=s[i];
	}
	sort(a,a+n,cmp);
	for(long long i=0;i<n;i++){
		if(int(a[i])>=48&&int(a[i])<=58){
			cout<<a[i];
		}
	}
	return 0;
}
