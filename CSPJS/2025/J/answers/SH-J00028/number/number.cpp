#include<bits/stdc++.h>
using namespace std;
long long ans = 0;
const int N = 1e6+6;
int l[N];
int ct = 0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			l[ct] = s[i]-48;
			ct++;
		}
	}
	sort(l,l+ct);
	for(int i = ct-1;i>=0;i--){
		cout<<l[i];
	}
	return 0;
} 
