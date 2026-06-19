#include <bits/stdc++.h>
using namespace std;
string s;
int cnt=1;
char n[1000010];
bool cmp(char x, char y){
	return (int)(x)>=(int)(y);
}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]-'a'>=0&&'z'-s[i]>=0){
			continue;
		}else{
			n[cnt]=s[i];
			cnt++;
		}
	}
	sort(n+1,n+cnt+1,cmp);
	for(int i=1; i<=cnt; i++){
		cout<<n[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
