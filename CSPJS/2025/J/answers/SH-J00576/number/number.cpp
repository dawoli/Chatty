#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
vector<ll> vNum;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9'){
			ll num=s[i]-'0';
			vNum.push_back(num);
		}
	sort(vNum.begin(),vNum.end(),greater<ll>() );
	for(int i=0;i<vNum.size();i++) cout<<vNum[i];
	return 0;
}
