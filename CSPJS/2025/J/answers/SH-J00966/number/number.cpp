#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000001];
	int c[1000001],d=0;
	cin>>a;
	int b=strlen(a);
	for(int i=0;i<b;i++){
		if(a[i]>='0'&&a[i]<='9'){
			c[d]+=int(a[i]-'0');
			d++;
		}
	}
	sort(c,c+d+1);
		for(int i=d;i>0;i--){
			cout<<c[i];
		}
	
	return 0;
}
