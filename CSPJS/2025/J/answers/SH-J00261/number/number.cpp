#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
string s;
int a[N],j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9') a[++j]=s[i]-'0';
	}
	sort(a+1,a+1+j);
	for(int i=j;i>=1;i--) cout<<a[i];
	return 0;
}
