#include<bits/stdc++.h>
using namespace std;
string s;int a[10],n,c;char d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<10;i++) a[i]=0;
	getline(cin,s);
	n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<10){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		c=48+i;
		d=c;
		for(int j=0;j<a[i];j++){
			putchar(d);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
