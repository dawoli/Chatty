#include<bits/stdc++.h>
using namespace std;
string s;
int c;
int a[1000005];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[c]=s[i]-'0';
			c++;
		}
	}
	sort(a,a+c,cmp);
	for(int i=0;i<c;i++){
		cout << a[i];
	}
	return 0;
}
