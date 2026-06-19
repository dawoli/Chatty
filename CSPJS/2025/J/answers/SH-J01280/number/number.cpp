#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a[100000] = {};
	int n = 0;
	for(int i = 0;i < s.length();i+=1){
		if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
			n+=1;
			if(s[i] == '0'){
				a[n] = 0;
			}else if(s[i] == '1'){
				a[n] = 1;
			}else if(s[i] == '2'){
				a[n] = 2;
			}else if(s[i] == '3'){
				a[n] = 3;
			}else if(s[i] == '4'){
				a[n] = 4;
			}else if(s[i] == '5'){
				a[n] = 5;
			}else if(s[i] == '6'){
				a[n] = 6;
			}else if(s[i] == '7'){
				a[n] = 7;
			}else if(s[i] == '8'){
				a[n] = 8;
			}else if(s[i] == '9'){
				a[n] = 9;
			}
		}
	}
	
	int mx = -1;
	int ans = 0;
	int d;
	for(int i = 1;i <= n;i+=1){
		mx = -1;
		for(int j = 1;j <= n;j+=1){
			if(a[j] > mx){
				mx = a[j];
				d = j;
			}
		}
		a[d] = -1;
		ans*=10;
		ans+=mx;
	}
	cout << ans << endl;
	return 0;
}
