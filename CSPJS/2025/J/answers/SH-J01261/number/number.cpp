#include<bits/stdc++.h>
using namespace std;
string s;
int b=1;
char a[1145141];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(!isalpha(s[i])){
			//cout<<s[i]<<endl;
			a[b++]=s[i];
		}
	}
	sort(a+1,a+b,cmp);
	for(int i=1;i<b;i++){
		cout<<a[i]; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
