#include<bits/stdc++.h>
#define ll long long
using namespace std;

int b[1000001]={-1};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a=' ';
	string c;
	cin>>c;
	for(int i=1;i<=c.length();i++){
	a=c[i-1];
	if(a-'0'<=9 && a-'0'>=0){
		b[i]=(a-'0');

	}
	else{
		b[i]=-1;

	}
}
	sort(b+1,b+1+c.length());
	for(int i=c.length();i>=1;i--){
		if(b[i]==-1){
			break;
		}
		cout<<b[i];
	}
	return 0;
}
