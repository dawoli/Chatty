#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath> 
using namespace std;

int t,n;
int a[200086];
bool c[200086];
int solve(int pos){//±©Á¦ 
	if(pos >n)return 0;
	int d1 = 0,d2 = 0;
	c[pos] = 0;
	for(int i = pos-1; i >0; --i){
		if(c[i]==0){
			if(a[i] == a[pos]){
				d1 = a[i];
				break;
			}
		}
	}
	d1 +=solve(pos+1);
	c[pos] = 1;
	for(int i = pos-1; i >0; --i){
		if(c[i]==1){
			if(a[i] == a[pos]){
				d2 = a[i];
				break;
			}
		}
	}
	d2 +=solve(pos+1);
	c[pos] = 0;
	return max(d1,d2);
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	for(int i = 1; i <=t; ++i){
		scanf("%d",&n);
		for(int i = 1; i <=n; ++i){
			scanf("%d",&a[i]);
		}
		printf("%d\n",solve(1));
	}
	return 0; 
} 
