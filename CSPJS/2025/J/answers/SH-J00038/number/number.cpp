#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],num;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i]-'0' >= 0 && s[i]-'0' <= 9){
			a[num]=s[i] - '0';
			num++;
		}
	}
	sort(a,a+num,cmp);
	
	for(int i = 0;i < num;i++){
		cout << a[i];
	}
	return 0;
} 
