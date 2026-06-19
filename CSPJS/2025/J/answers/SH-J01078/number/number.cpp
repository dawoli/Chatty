#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000007];
int p;
int cmp(int c1,int c2){
	return c1 > c2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if(int(s[i] - 48) >= 0 && int(s[i] - 48) <= 9){
			p++;
			a[p] = int(s[i] - 48);
		}
	}
	sort(a + 1,a + p + 1,cmp);
	for(int i = 1;i<=p;i++) cout<<a[i];
	return 0;
} 
