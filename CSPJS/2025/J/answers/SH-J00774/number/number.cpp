#include<bits/stdc++.h>
using namespace std;
string s;
int top,c[1000009],mx;
bool cmp(const int&a,const int&b){
	return a>b;
}//我是miyachn，洛谷uid1295276，想上迷惑行为大赏qwq 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') c[++top]=int(s[i]-'0'),mx=max(mx,c[top]);
	}
	sort(c+1,c+1+top,cmp);
	if(mx==0){
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=1;i<=top;i++) cout<<c[i];
	return 0;
}

