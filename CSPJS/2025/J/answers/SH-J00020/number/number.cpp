#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	int j = 0;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			int x = s[i] - '0';
			a[j] = x;
			j++;
		}
	}
	sort(a , a + j , cmp);
	for(int i = 0 ; i < j ; i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
