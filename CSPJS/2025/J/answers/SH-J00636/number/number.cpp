#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c[1000005],num[1000005];
	cin>>c;
	for(int i=9;i>=0;--i){
		for(int j=0;j<strlen(c);++j){
			if(c[j]==i+48){
				num[strlen(num)]+=c[j];
			}
		}
	}
	cout<<num;
	return 0;
}
