#include<bits/stdc++.h>
using namespace std;
string str;
int len,a[1000006];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> str;
	for(int i=0;i<str.length();i++){
		if(str[i]>='0' && str[i]<='9')	a[++len]=str[i]-'0';
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
