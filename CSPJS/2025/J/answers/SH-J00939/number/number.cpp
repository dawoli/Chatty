#include<bits/stdc++.h>
using namespace std;
string s;
int a[17];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
//	cout<<s<<endl;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0 and s[i]-'0'<=9) a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
//		cout<<a[i]<<" ";
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
