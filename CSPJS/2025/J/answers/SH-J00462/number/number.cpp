#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	cout<<'\n';
	return 0; 
}
