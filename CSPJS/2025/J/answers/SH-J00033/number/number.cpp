#include<bits/stdc++.h>
using namespace std;
string s;
const int N=19;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9') a[(int)s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)cout<<i; 
	}
	return 0;
}
