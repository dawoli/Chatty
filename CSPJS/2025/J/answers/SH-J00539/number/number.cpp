#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll num[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll cnt=0;
	for(ll i=0;i<(ll)s.size();++i){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			num[cnt++]=(ll)(s[i]-'0');
		}
	}
	for(ll i=0;i<cnt;++i){
		cout<<*max_element(num,num+cnt);
		num[distance(num,max_element(num,num+cnt))]=0;
	}
	return 0;
}
