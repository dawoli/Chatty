#include<iostream>
#include<cstring>
using namespace std;
char l[2][55];
bool shi(char x,char z){
	for(int i=0;i<55;i++){
		if(x==l[0][i] && z==l[1][i]){
			return false;
		}
	}
	return true;
}
int main(){
	int n,ji=0;
	char y[2];
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	for(int i=0;i<55;i++){
		l[0][i]=' ';
		l[1][i]=' ';
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>y[0];
		cin>>y[1];
		if(shi(y[0],y[1])){
			l[0][i]=y[0];
			l[1][i]=y[1];
			ji++;
		}
	}
	cout<<52-ji;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
