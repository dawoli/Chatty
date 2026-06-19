#include <bits/stdc++.h>
using namespace std;
int a[100005],len,k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0;s[i];i++){
		if(s[i] >= '0' && s[i] <= '9'){
			k++;
			a[k] = s[i]-'0';
			len++;
		}
	}
	sort(a+1,a+len+1);
	for(int i = len;i > 0;i--){
		cout << a[i];
	}
	return 0;
}
