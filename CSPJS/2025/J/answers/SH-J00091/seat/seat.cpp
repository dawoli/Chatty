#include <bits/stdc++.h>
using namespace std;
long long n,m,a1,b1,b,im,b2;//a1为列，b1为行 
long long a[1010];

bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin >> n >> m;
	b = n*m;
	for(int i = 1;i<=b;i++){
		cin >> a[i];
	}
	im = a[1];
	sort(a+1,a+1+b,cmp);
	for(int i = 1;i<=b;i++){//i为第几顺位 
		if(a[i] == im){
			b2 = i;
		}
	}
	if(b2 % n == 0){
			if((b2/n) %2 !=0){
				
				printf("%d %d",b2/n,n);
			}
			else{
				
				printf("%d %d",b2/n,1);
			}
			
		}
		else{
			a1 = b2/n+1;
			if(a1 % 2 !=0){
				b1 = b2-b2/n*n;
			}
			else{
				b1 = n-(b2-b2/n*n) +1;
			}
			
			printf("%d %d",a1,b1);
		}
	return 0;
} 
