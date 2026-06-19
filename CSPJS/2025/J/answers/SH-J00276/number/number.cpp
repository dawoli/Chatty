#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int b[100007];
	int w=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			b[w]=s[i]-'0';
			w++;
		}
	}
	sort(b,b+w,cmp);
	for(int i=0;i<w;i++){
		cout << b[i];
	}
	return 0;
}
