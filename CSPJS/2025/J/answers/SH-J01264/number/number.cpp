#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>47&&s[i]<58){
			a[++cnt]=s[i]-48;
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
