#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 
//#Shang4Shan3Ruo6Shui4
