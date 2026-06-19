#include <bits/stdc++.h>
using namespace std;
bool a[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,temp;
	char s1,s2;
	int cnt = 0;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> s1 >> s2;
		if (s1=='D'){
			temp = 0;
		}
		else if (s1=='C'){
			temp = 1;
		}
		else if (s1=='H'){
			temp = 2;
		}
		else if (s1=='S'){
			temp = 3;
		}
		if (s2=='A'){
			temp = temp+0;
		}
		else if ('2'<=s2 && s2<='9'){
			temp = temp+(s2-'0')*4-4;
		}
		else if (s2=='T'){
			temp = temp+36;
		}
		else if (s2=='J'){
			temp = temp+40;
		}
		else if (s2=='Q'){
			temp = temp+44;
		}
		else if (s2=='K'){
			temp = temp+48;
		}
		a[temp] = true;
	}
	for (int i=0;i<=51;i++){
		if (a[i]){
			cnt++;
		}
	}
	cnt = 52-cnt;
	cout << cnt;
	return 0;
}
