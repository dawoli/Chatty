#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006],l,cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--){
		printf("%d",a[i]);
	}
	return 0;
}
