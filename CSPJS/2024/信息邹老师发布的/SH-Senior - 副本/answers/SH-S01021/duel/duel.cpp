#include<bits/stdc++.h>
using namespace std;
int a[100005] = {};
int b[100005] = {0};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,max1 = 0,x;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(long long i = 1;i <= n;i++){
		for(long long j = 1;j <= n;j++) {
			if(a[i] > a[j] && b[j] == 0){
				if(a[j] > max1){
					max1 = a[j];
					x = j;
				}
			}
		}
		b[x] = 1;
	}
	int sum = 0;
	for(int i = 1;i <= n;i++){
		if(b[i] == 0){
			sum++;
		}
	}
	cout <<sum;
	return 0;
}
