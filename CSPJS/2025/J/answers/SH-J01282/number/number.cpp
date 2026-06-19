#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int an = 0;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int sss = s.length();
	for(int i = 0;i < sss;i++){
		if(s[i] >= '0' && s[i] <= '9')
			a[++an] = s[i]-'0';
	}
	sort(a+1,a+1+an);
	if(a[an] != 0){
		for(int i = an;i >= 1;i--)
			printf("%d",a[i]);
	}
	else
		cout << 0;
		return 0;
}

