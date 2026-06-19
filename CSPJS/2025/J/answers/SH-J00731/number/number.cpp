#include<bits/stdc++.h>
using namespace std;
string s;
int tot,a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			tot++;
			a[tot]=s[i]-'0';
		}
	}sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--){
		printf("%d",a[i]);
	}return 0;
}
