#include  <bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int top;
bool cmp(const char x,const char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[top++]=s[i];
		}
	}
	sort(a,a+top,cmp);
	if(a[0]=='0'){
		cout<<0;
		return 0;
	}
	for(int i=0;i<top;i++){
		cout<<a[i];
	}
	return 0;
}
