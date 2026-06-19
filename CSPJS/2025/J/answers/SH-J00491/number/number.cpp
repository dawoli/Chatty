#include<bits/stdc++.h>
using namespace std;
map <int , int> a;
bool cmp(int a , int b){
	return a > b;
}
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			int c = (int)s[i] - '0';
			a[c] = a[c] + 1;
	    }
	}
	for(int i = 9;i >= 0;i --){
		for(int j = 0;j < a[i];j ++){
			cout << i;
		}
	}
	return 0;
} 
