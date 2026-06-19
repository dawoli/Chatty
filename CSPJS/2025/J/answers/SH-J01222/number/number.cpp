#include<bits/stdc++.h>
using namespace std;
int a[114514],_i=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int n=s[i]-'0';
		if(n<=9&&n>=0){
			a[_i++]=n;
		}
	}
	sort(a,a+_i);
	for(int i=_i-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
