#include<bits/stdc++.h>
using namespace std;
int s[1007];
int a[1007];
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int cnt = 0;
	for(int i = 1;i <= s.size();i++){
		cin >> s[i];
		if(s[i] >= 1 && s[i] <= 9){
			a[i] = s[i];
			cnt++;
		}
	}
	for(int i = 1;i <= cnt;i++){
		if(a[i+1] > a[i]){
			sort(a[i+1],a[i]);
		}
	}
	for(int i = 1;i <= cnt;i++){
		cout << a[i];
	}
	return 0;
}
