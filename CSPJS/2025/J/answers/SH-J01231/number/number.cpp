#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
char ch[MAXN];
int a[MAXN];
bool cmp(int x,int y){return x > y;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int len_ch = 0;
	char ch1;
	while(cin >> ch1) ch[++len_ch] = ch1;
	int pos = 1;
	for(int i = 1;i <= len_ch;i++){
		if(ch[i] >= '0' && ch[i] <= '9')
			a[pos++] = ch[i]-'0';
	} 
	sort(a+1,a+pos+1,cmp);
	for(int i = 1;i < pos;i++) cout << a[i];
	return 0;
}
