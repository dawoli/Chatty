#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	int i=0;
	while(cin>>c){
		if('0'<=c&&c<='9'){
			a[i]=c-'0';
			i++;
		}
	}
	sort(a,a+i);
	for(int j=i-1;j>=0;j--){
		cout<<a[j];
	} 
	return 0;
} 
