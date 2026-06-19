#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char c,r[1000001];int i,j,n[128];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(;;){
		c=getchar();
		if(c=='\n'||c=='\0')break;
		if(c>='0'&&c<='9')n[c]++;
	}
	for(i='9';i>='0';i--)
	    for(j=1;j<=n[i];j++)cout<<char(i);
	return 0;
}
