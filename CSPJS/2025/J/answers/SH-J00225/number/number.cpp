#include<bits/stdc++.h>
using namespace std;
char c;
int cnt=1,a[100009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if(c-'0'>=0&&c-'0'<=9){
			a[cnt]=c-'0';
			cnt++;
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
