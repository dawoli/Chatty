#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a[s.length()+5];//存储数字 
	int flag=1;//数字下标 
	for(int i=0;i<s.length();i++){
		if(s[i]<='9' && s[i]>='0'){//是数字
			a[flag]=s[i]-'0';
			flag++;
		}
	}
	sort(a+1,a+flag,cmp);
	for(int i=1;i<flag;i++) cout << a[i];
	return 0;
}
