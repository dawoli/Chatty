#include<cstdio>
using namespace std;
char c;
int a[10] , i , j;
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	c = getchar();
	for (; (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ; c = getchar()){
		if (c >= '0' && c <= '9'){
			a[c - '0']++;
		}
	}
	for (i = 9 ; i >= 0 ; i--){
		for (j = 1 ; j <= a[i] ; j++){
			putchar(i + 48);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
