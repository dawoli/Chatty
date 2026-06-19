#include<bits/stdc++.h>
using namespace std;
long long c[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long num=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			num++;
			c[num]=s[i]-'0';
		}
	}
	sort(c+1,c+num+1);
	for(long long i=num;i>=1;i--){
		cout<<c[i];
	}
	return 0;
}
