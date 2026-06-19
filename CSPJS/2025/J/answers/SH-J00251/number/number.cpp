#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	int a[10];
	cin>>s;
	memset(a,0,sizeof(a));
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i; 
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
