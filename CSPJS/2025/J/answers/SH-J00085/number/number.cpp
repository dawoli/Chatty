#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return (a-'0')>(b-'0');
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000010];
	cin>>s;
	int p=0;
	for(int i=0;i<strlen(s);i++){
		if(!(s[i]>='0'&&s[i]<='9')){
			p++;
			s[i]='0'; 
		}
	}
	sort(s,s+strlen(s),cmp); 
	for(int i=0;i<strlen(s)-p;i++){
		cout<<s[i];
	}
//	int num[10]={0};
//	for(int i=0;i<strlen(s);i++){
//		if(s[i]>='0'&&s[i]<='9'){
//			num[s[i]-'0']++;
//		}
//	} 
//	for(int i=9;i>=0;i--){
//		while(num[i]){
//			cout<<i;
//			num[i]--;
//		} 
//	}
	return 0;
} 
