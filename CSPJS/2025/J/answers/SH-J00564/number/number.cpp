#include<bits/stdc++.h>
using namespace std;
string a;int b[1000010],n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			b[n++]=a[i]-'0';
		}
	}
	sort(b,b+n);
	for(int i=n-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
