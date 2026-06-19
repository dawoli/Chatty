#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[1000099];
bool cmp(const int &a,const int &b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)cout<<a[i];
	return 0;
}

