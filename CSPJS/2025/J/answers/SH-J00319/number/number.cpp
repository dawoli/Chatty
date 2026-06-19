#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
signed main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	for(int i=0;i<s.length();i++) if(s[i]-'0'<10) a[s[i]-'0']++;
	for(int i=9;i>=0;--i){
		while(a[i]) cout<<i,a[i]--;
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
