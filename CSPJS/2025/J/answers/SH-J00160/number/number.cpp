#include<bits/stdc++.h>
using namespace std;
int a[1000005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ji0=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[ji0]=s[i]-'0';
			ji0++;
		}
	}
	sort(a+1,a+ji0);
	for(int i=ji0-1;i>=1;i--){
		cout<<a[i]; 
	}
	cout<<endl;
	return 0;
}
