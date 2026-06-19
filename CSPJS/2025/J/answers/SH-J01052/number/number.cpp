#include <bits/stdc++.h>
using namespace std;
int a[1000086];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[cnt]=s[i]-'0'; 
			cnt++;
		}
	}
	string ans;
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		char x=a[i]+'0';
		ans+=x;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
