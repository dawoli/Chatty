#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int ss=0;
int num[1000010];
int nn=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(s,'.',sizeof(s));
	cin>>s;
	while(s[ss+1]!='.'){
		if(s[ss]>='0'&&s[ss]<='9'){
			nn++;
			num[nn]=s[ss]-'0';
		}
		ss++;
	}
	sort(num+1,num+nn+1,cmp);
	for(int i=1;i<=nn;i++){
		cout<<num[i];
	}
	return 0;
} 
