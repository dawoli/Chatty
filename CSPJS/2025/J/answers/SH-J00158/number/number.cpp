#include<bits/stdc++.h>
using namespace std;
char s[1000010];
char num[1000010];
bool mycmp(char a,char b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int index=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>=48&&s[i]<=57){
			num[index]=s[i];
			index++;
		}
	}
	sort(num,num+index,mycmp);
	if(num[0]=='0'){
		cout<<0<<endl;
		return 0;
	}else{
		for(int i=0;i<index;i++){
			cout<<num[i];
		}
		cout<<endl;
		return 0;
	}
	return 0;
}
//number(0-9):48-57
