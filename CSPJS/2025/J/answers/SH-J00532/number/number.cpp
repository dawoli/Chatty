#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10; 
int a[N],cnt=1;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt,greater<int>());
	for(int i=1;i<cnt;i++){
		cout<<a[i];
	} 
	return 0;
}
