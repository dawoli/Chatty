#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int wei=1;
	int m,a,b,lin;
	cin>>a>>b;
	cin>>m;
	for(int i=1;i<a*b;i++){
		cin>>lin;
		if(lin>m) wei++;
	}
	cout<<(wei+a-1)/a<<" ";
	if(((wei+a-1)/a)%2==0)cout<<b-((wei+a-1)%a);
	else{
		cout<<((wei+a-1)%a+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
