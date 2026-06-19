#include <iostream>
using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;s[i];i++){
		if(s[i]<='9' && s[i]>='0')
		    a[s[i]-'0']++;
	}
	bool f=1;
	for(int i=9;i>=1;i--){
	    while(a[i]--){
	        cout << i;
	        f=0;
		}
	}
	if(f){
		cout << 0;
	}
	else{
		while(a[0]--){
			cout << 0;
		}
	}
	return 0;
}
