#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	
	
	int a[1000005],aa=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[++aa]=int(s[i]-'0');
		}
	}
	sort(a+1,a+aa+1,cmp);

	for(int i=1;i<=aa;i++){
		cout<<a[i];
	}
	return 0;
}
