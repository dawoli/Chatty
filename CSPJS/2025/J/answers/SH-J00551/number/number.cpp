#include <bits/stdc++.h> 
using namespace std;

string s;
int num[2000006];
int cnt = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.length();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cnt++;
			num[cnt] = (int)s[i] - 48;
		}
	}
	sort(num+1,num+cnt+1);
	for(int i = cnt;i >= 1;i--){
		cout << num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
