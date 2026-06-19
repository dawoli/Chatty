#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			t++;
			a[t]=int(s[i]-'0');
		}
	}
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
