#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cs=1;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0' && s[i]<='9'){
			a[cs]=(int)(s[i])-'0';
			cs++;
		}
	}
	sort(a+1,a+cs+1,cmp);
	for (int i=1;i<cs;i++){
		cout<<a[i];
	}
	return 0;
}
