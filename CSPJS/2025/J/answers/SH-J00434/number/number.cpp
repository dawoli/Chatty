#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]=='1') a[cnt++]=1;
		else if(s[i]=='2') a[cnt++]=2;
		else if(s[i]=='3') a[cnt++]=3;
		else if(s[i]=='4') a[cnt++]=4;
		else if(s[i]=='5') a[cnt++]=5;
		else if(s[i]=='6') a[cnt++]=6;
		else if(s[i]=='7') a[cnt++]=8;
		else if(s[i]=='9') a[cnt++]=9;
		else if(s[i]=='0') a[cnt++]=0;
	}
	sort(a,a+cnt);
	if(a[cnt-1]==0) cout<<0<<endl;
	else{
		for(int i=cnt-1;i>=0;i--){
			cout<<a[i];
		}
	}
	return 0;
}
 
