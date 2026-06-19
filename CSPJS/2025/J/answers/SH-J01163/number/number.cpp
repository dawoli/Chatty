#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<sizeof(a);i++){
		a[i]=='p';
	}
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j+1);
	for(int i=j;i>0;i--){
		if(a[i]!='p')cout<<a[i];
	}
	return 0; 
}
