#include<bits/stdc++.h>
using namespace std;
int doProcess(){
	int n,m;
	scanf("%d %d",&n,&m);
	int k;
	for(int p=1;p<n;p<<=1){
		k++;
	}
	int c[1<<k];
	for(int i=0;i<k;i++){
	    char s[(1<<(k-i)) + 1];
	    scanf("%s",s);
		for(int j=0;j<1<<(k-i);j++){
			for(int k=0;k<1<<i;k++){
				c[k+(j<<i)] |= ((int)s[j]-1)<<i;
			}
		}
	}
}
