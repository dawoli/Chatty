#include<bits/stdc++.h>
using namespace std;
string s;
int a[100015],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>=48&&s[i]<=57) {
			a[cnt]=int(s[i])-48;
			cnt++;
		}
	}
	sort(a,a+cnt);
	for (int i=cnt-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
