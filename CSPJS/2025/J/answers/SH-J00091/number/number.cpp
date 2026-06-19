#include <bits/stdc++.h>
using namespace std;
char b[100010];
long long c[100010];
long long n = 0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	long long a = s.size();
	for(int i = 0;i<a;i++){
		if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3'||s[i] == '4'||s[i] == '5'||s[i] == '6'||s[i] == '7'||s[i] == '8'||s[i] == '9'){
			b[n] = s[i];
			n+=1;
		}
	}
	for(int i = 0;i<n;i++){
		if(b[i] == '0'){
			c[i] = 0;
		}
		else if(b[i] == '1'){
			c[i] = 1;
		}
		else if(b[i] == '2'){
			c[i] = 2;
		}
		else if(b[i] == '3'){
			c[i] = 3;
		}
		else if(b[i] == '4'){
			c[i] = 4;
		}
		else if(b[i] == '5'){
			c[i] = 5;
		}
		else if(b[i] == '6'){
			c[i] = 6;
		}
		else if(b[i] == '7'){
			c[i] = 7;
		}
		else if(b[i] == '8'){
			c[i] = 8;
		}
		else{
			c[i] = 9;
		}
	}
	long long maxn = 1e9+5;
	sort(c,c+n,cmp);
	for(int i = 0;i<n;i++){
		cout << c[i];
	}
	return 0;
} 
