#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,b,c;
	cin >>a;
	if(a<10){
		cout << a;
	}else{
		b=a/10;
		c=a%10;
		if(b>c){
	 	cout <<b<<c; 
	 }else{
	 	cout <<c<<b;
	 }
	}
	 fclose(stdin);
	 fclose(stdout); 
return 0;	
}  
