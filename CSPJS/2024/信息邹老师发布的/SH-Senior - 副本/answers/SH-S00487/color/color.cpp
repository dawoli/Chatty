#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int ar[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	long long n,sum=0;
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		sum = 0;
		for(int i=1;i<=a;i++){
			cin >> ar[i];
		}
		for(int i=1;i<=a;i++){
			if(ar[i] == ar[i+1]){
				sum+=ar[i];
				ar[i] = 0;
				ar[i+1] = 0;
			}
		}
	    sort(ar+1,ar+a+1,cmp);
	    for(int i=1;i<=a;i++){
			if(ar[i] == ar[i+1]){
				sum+=ar[i];
				ar[i] = 0;
				ar[i+1] = 0;
			}
		}
		cout << sum <<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
