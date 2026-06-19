#include<bits/stdc++.h>
#define N 1000009
using namespace std;
char ch;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int id=0;
	while(cin>>ch){
		if(ch>='0'&&ch<='9'){
			a[id]=ch-'0';
			id++;
		}
	}
	int n=id;
	sort(a,a+n);
	reverse(a,a+n);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
