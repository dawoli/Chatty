#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006];
int cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
