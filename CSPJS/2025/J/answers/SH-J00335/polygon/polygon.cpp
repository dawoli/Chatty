#include<bits/stdc++.h>
using namespace std;
int time(int ab){
	int sum1=1;
	for(int q = 0;q<ab;q++){
		sum1*=q;
	}
	return sum1;
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,sumt=0;
	cin >> n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	for(int i = 3;i<=n;i++){
		for(int j = 1;j<=(time(n)/time(i))*i;i++){
			int x[i];
			int s=0;
			for(int p = s;p<s+i+1;p++){
                    x[p]=a[p];
			}
			int max=0,sum=0;
			for(int e=0;e<i;e++){
				if(x[e]>max){
					max=x[e];
				}
				sum+=x[e];
			}
			if(max*2<sum){
				sumt++;
			}
			s++;
		}
	}
	cout << sumt;
	return 0;
}
