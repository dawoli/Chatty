#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
int a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--)cout<<a[i];
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
