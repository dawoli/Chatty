#include<bits/stdc++.h>
using namespace std;
int b[1000005]={0},t=0;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int cn=a.size();
	for(int i=0;i<cn;i++){
		if(a[i]>='0'&&a[i]<='9'){
			t++;
			b[t]=a[i]-'0';
		}
	}
	sort(b+1,b+t+1);
	for(int i=t;i>=1;i--){
		cout<<b[i];
	}
	return 0;
} 
