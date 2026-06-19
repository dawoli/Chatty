#include<bits/stdc++.h> 
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	cin >> s;
	int cnt = 0;
	int num = strlen(s);
	for(int i = 0;i < num;i++){
		int t = int(s[i])-48;
		if(t >= 0 && t <= 9){
			cnt += 1;
			a[cnt] = t;
		}
	}
	sort(a+1,a+cnt+1);
	for(int i = cnt;i >= 1;i--){
		cout << a[i];
	}
	return 0;
}
