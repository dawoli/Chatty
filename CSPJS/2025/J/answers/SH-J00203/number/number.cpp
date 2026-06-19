#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int x=0;
	char a[1000000];
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='8'){
			a[x]=s[i];
			x++;
		}
		else if(s[i]=='9'){
			cout<<9;
		}
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
