#include<cstdio>
#include<cstring>
const int N = 1e6 + 1e4;
char s[N];
int len,tong[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			tong[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(tong[i]>0){
			putchar(i|48);
			tong[i]--;
		}
	}
	printf("\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
