#include<bits/stdc++.h>
using namespace std;
int len,cnt[10];//分别记录0-9每个数字的个数 
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')cnt[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
