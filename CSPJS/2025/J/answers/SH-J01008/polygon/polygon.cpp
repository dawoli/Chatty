#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	int n;
	scanf("%d",&n);
	const int con=n;
	int b[con]={0},a[con],sum=0,cnt=0;
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	while (sum!=n){
		if (sum>=3){
			int stick_sum=0,stick_max=0;
			for (int i=0;i<n;++i){
				if (b[i]){

					stick_sum+=a[i];
					if (a[i]>stick_max){
						stick_max=a[i];
					}
				}
			}

			if (stick_sum>2*stick_max) ++cnt;
		}
		++b[n-1];
		++sum;
		for (int i=n-1;i>0;--i){
			if (b[i]==2){
				b[i]=0;
				++b[i-1];
				--sum;
			}
		}
	}
	
	int stick_sum=0,stick_max=0;
			for (int i=0;i<n;++i){
				if (b[i]){

					stick_sum+=a[i];
					if (a[i]>stick_max){
						stick_max=a[i];
					}
				}
			}

			if (stick_sum>2*stick_max) ++cnt;
	
	printf("%d",cnt);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
