#include<bits/stdc++.h>
using namespace std;

const long long N=1e6+5;
string s;
long long a[N];
long long num;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[++num]=s[i]-'0';
		}
	}
	sort(a+1,a+num+1,greater<long long>());
	for(long long i=1;i<=num;i++){
		cout<<a[i];
	}
	cout<<"\n";
	return 0;
}
