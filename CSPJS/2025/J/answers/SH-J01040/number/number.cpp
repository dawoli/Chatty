#include<bits/stdc++.h> 
using namespace std;
string s;
int a[1000005],n;
bool cmp(int a, int b){
	if(a>b){
		return true;
	}
	return false;
}
int main(){
	freeopen("number.in","r","stdin");
	freeopen("number.out","w","stdout");
	cin>>s;
	for(int i=0; i<s.length(); i++){
		if(s[i]-'0'>=0 && s[i]-'1'<9){
			a[n]=s[i]-'1'+1;
			n++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0; i<n; i++){
		cout<<a[i];
	}
	return 0;
}
