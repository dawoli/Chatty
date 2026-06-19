#include <bits/stdc++.h>
using namespace std;

	char c[1000010];
	int a[1000100];
	int x = 0;
	
	bool cmp(int m,int n){
		return m > n;
	}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c + 1);
	int l = strlen(c + 1);
	for (int i = 1;i <= l;i++){
		if (c[i] >= '0' && c[i] <= '9'){
			a[++x] = c[i] - '0';
		}		
	}
	sort(a + 1,a + x + 1,cmp);
	for (int i = 1;i <= x;i++){
		printf("%d",a[i]);	
	}
	return 0;
}
