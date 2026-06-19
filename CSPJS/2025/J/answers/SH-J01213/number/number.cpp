#include<bits/stdc++.h>
using namespace std;
int a[1000004];
void init(){
	string s;
	string b;
	cin>>s;
	int cnt=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt);
	for(int i=cnt-1;i>=1;i--){
		b+=a[i]+'0';
	} 
	cout<<b;
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
