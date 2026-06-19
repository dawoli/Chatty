#include<bits/stdc++.h>
using namespace std;
long long a[1111111],c=0;
string b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(int i=0;i<b.size();i++){
		if(b[i]>=48&&b[i]<=57){
			a[c++]=b[i]-48;
		}
	}
	sort(a,a+c);
	for(int i=c-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
