#include <bits/stdc++.h>
using namespace std;
string s;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]-'0'<=9&&s[i]-'0'>=0)	a[s[i]-'0']++;
	}
	bool f=0;
	for(int i=9;i>=1;--i){
		for(int j=1;j<=a[i];++j){
			cout<<i;
			f=1;
		}
	}
	if(f==0&&a[0]>0){
		cout<<"0";
	}
	if(f==1){
		for(int i=1;i<=a[0];++i){
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
