#include<bits/stdc++.h>
using namespace std;
const int N=1000006;
string s;
int a[1009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();++i){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;--i){
		while(a[i]>0){
			a[i]--;
			cout<<i;
		}
	}
	return 0;
}
