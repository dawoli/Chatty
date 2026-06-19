#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;
int n,m;
int lst = 0;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		int nw = 0;
		for(int j = i;j > lst;j--){
			nw = nw ^ a[j];
			//printf("nw:%d\n",nw);
			if(nw == m){
				cnt++;
				lst = i;
				break; 
			}
		} 
		//printf("%d\n",lst);
	}
	
	printf("%d\n",cnt);
	return 0;
}
//ÄÃ¸ö±©Á¦·Ö 
