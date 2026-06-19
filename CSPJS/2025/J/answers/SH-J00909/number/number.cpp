#include<bits/stdc++.h>
using namespace std;
int b[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a;
	long long cnt=1;
	while(cin>>a){
		if(a=='0'){
			b[cnt]=0;
			cnt++;
		}
		if(a=='1'){
			b[cnt]=1;
			cnt++;
		}
		if(a=='2'){
			b[cnt]=2;
			cnt++;
		}
		if(a=='3'){
			b[cnt]=3;
			cnt++;
		}
		
		if(a=='4'){
			b[cnt]=4;
			cnt++;
		}
		if(a=='5'){
			b[cnt]=5;
			cnt++;
		}
		if(a=='6'){
			b[cnt]=6;
			cnt++;
		}
		if(a=='7'){
			b[cnt]=7;
			cnt++;
		}
		if(a=='8'){
			b[cnt]=8;
			cnt++;
		}
		if(a=='9'){
			b[cnt]=9;
			cnt++;
		}
	}
	sort(b,b+cnt);
	for(int i=cnt-1;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}
