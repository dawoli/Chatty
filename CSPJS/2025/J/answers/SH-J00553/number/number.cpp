#include <iostream>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	bool check=false;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}for(int i=9;i>=1;i--){
		for(int j=a[i]-1;j>=0;j--){
			cout<<i;
			a[i]--;
			check=true;
		} 
	}if(check==true){
		for(int i=1;i<=a[0];i++){
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
} 
