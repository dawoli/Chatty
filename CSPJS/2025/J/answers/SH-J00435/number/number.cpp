#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","stdin",stdin);
	freopen("number.out","stdout",stdout);
	int n=0,ans[100005];
	char s[100005];
	cin>>s;
	for(int i=0;i<sizeof(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[n]=s[i]-'0';
			n++;
		}
	}
	sort(ans,ans+n);
	for(int i=n-1;i>=0;i--){
		cout<<ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
