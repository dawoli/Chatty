#include <bits/stdc++.h>
using namespace std;
long long a[1000008];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int b=0;
	for(int i=0;i<s.size();++i){
		if(s[i]<'a'){
			b++;
			a[b]=char(s[i]-'40');
		}
	}
	sort(a+1,a+1+b);
	for(int i=b;i>0;--i){
		cout<<a[i];
	}
	return 0;
}
