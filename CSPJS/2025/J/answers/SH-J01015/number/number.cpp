#include<bits/stdc++.h>
using namespace std;
string s;
int a[15]; 
int main(){
	//½â×¢ÊÍ£¡£¡£¡£¡£¡£¡£¡ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		//cout<<a[i]<<" ";
		for(int j=0;j<a[i];j++) printf("%d",i); 
	}
	return 0;
}
