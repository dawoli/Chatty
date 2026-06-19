#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cur;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++cur]=s[i]-'0';
	}
	sort(a+1,a+cur+1);
	for(int i=cur;i>=1;i--)
		cout<<a[i];
	cout<<endl;
	return 0;
}
