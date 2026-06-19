#include <iostream>
#include <string>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[10]={};
	for(int x=0;x<=s.size();x++){
		if(s[x]>='0' and s[x]<='9'){
			a[s[x]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
