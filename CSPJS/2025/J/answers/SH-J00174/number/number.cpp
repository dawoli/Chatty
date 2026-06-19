#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e6+10;
int a[N];
bool cmp(int x,int y){
	return x > y;
}

int main(){
	
	freopen64("number.in","w",stdin);
	freopen64("number.in","r",stdin);
	freopen64("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt = 1;
	for (long unsigned int i = 0; i < s.length(); i++){
		if ('0' <= s[i] && s[i] <= '9'){
			a[cnt] = s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for (int i = 1;i < cnt;i++){
		cout << a[i];
	}
	cout << endl;
	return 0;
}
