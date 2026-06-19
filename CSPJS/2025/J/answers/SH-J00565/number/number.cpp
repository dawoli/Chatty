#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int p=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[p]=(int)s[i]-'0';
			p++;
		}
	}
	sort(a,a+p);
	for(int i=p-1;i>=0;i--)
		cout<<a[i];
	cout<<endl;
	return 0;
}
