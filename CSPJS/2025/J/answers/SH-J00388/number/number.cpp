#include<bits/stdc++.h>
using namespace std;
char c;
int tmp[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	c=getchar();
	while((c>='0'&&c<='9')||(c>='a'&&c<='z')){
		if(c>='0'&&c<='9'){
			tmp[c-'0']++;
		}
		c=getchar();
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tmp[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
