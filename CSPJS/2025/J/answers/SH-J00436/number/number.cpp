#include<bits/stdc++.h>
using namespace std;
int a[10000005],t=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
			a[++t]=s[i]-'0';
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
