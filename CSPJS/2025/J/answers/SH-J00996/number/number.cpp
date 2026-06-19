#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
int a[N];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	cnt--;
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--)cout<<a[i];
	return 0;
}
