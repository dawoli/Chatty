#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
bool check(char a,char b){
	if(a>='0'&&a<='9'){
		if(b>='0'&&b<='9'){
			return a>b;
		}else{
			return 1;
		}
	}else{
		return 0;
	}
}
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>s;
	sort(s,s+sizeof s,check);
	for(int i=0;i<=1e6+5;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cout<<s[i];
		}else{
			return 0;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
