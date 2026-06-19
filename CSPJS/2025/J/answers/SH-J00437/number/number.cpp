#include<bits/stdc++.h>
using namespace std;
#define N 1000005
string s;
int a[N],an;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(unsigned int i=0;i<s.length();i++){
		char c=s[i];
		if('0'<=c&&c<='9'){
			a[++an]=c-'0';
		}
	}
	sort(a+1,a+an+1);
	for(int i=an;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
