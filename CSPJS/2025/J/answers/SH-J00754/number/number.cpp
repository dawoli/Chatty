#include<bits/stdc++.h>
using namespace std;
char a[10000];
int b[10000],o;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<len;++i){ 
		if(a[i]>='0'&&a[i]<='9'){
			b[o]=a[i]-'0';
			++o;
		}
	}
	sort(b,b+o,greater<int>());
	for(int i=0;i<o;++i){
		cout<<b[i];
	}
	return 0;
}
