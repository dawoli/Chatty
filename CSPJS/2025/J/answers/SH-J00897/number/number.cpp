#include<bits/stdc++.h>
using namespace std;
int n;
char a[1000015];
bool cmp(int x,int y){
	return x>y;
}
int cnt[15];
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c=getchar();
	while((!(c>='a'&&c<='z'))&&(!(c>='0'&&c<='9'))){
		c=getchar();
	}
	while((c>='a'&&c<='z')||(c>='0'&&c<='9')){
		a[n++]=c;
		c=getchar();
	}
	for(int i=0;i<n;i++){
	 	if(a[i]>='0'&&a[i]<='9'){
			cnt[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			write(i);
		}
	}
	return 0;
}
