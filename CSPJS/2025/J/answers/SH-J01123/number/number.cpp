#include<bits/stdc++.h>
using namespace std;
char a;
int c[1000005];
int b=1,t=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=1000005;i++){
		c[i]=10;
	}
	for(int i=1;i<=1000005;i++){
		cin>>a;
		if(a == '1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'||'0'){
			c[b]=a;
			b++;
		}else{
			break;
		}
	}
	sort(c+1,c+1000006);
	while (c[t]!=10){
		cout<<c[t];
		t++;
	}
	return 0;
	
}
 
