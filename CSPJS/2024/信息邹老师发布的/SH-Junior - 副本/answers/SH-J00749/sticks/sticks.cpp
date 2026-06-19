#include <bits/stdc++.h>
using namespace std;
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
int t,c=0,d=0,i=0,j;
long long n[60],b[60];
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	cin >> t;
	for (int i=0;i<t;i++){
		cin >> n[i];
	}
	for (int i=0;i<t;i++){
		for (int e=1;e<1000;i++){
			b[0]=i/100;
			b[1]=i%100/10;
			b[2]=i%100%10;
			if(c!=n[i]){
				c=-1;
			}else if(b[0]==0){
				c=a[b[1]]+a[b[2]];
				if(b[1]==0){
					c=a[b[2]];
				}
			}else c=a[b[0]]+a[b[1]]+a[b[2]];
		}
		cout << c << endl;	
	}
	return 0;
}
