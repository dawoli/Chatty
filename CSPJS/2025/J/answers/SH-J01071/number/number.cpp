#include<bits/stdc++.h>
using namespace std;

string s;
int a[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
