#include<bits/stdc++.h>
using namespace std;
int n,a[1000009];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
//	cout<<n;
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
