#include<bits/stdc++.h>
using namespace std;
int b,a,c[109],d,e,x=1,y=0;//hang,lie
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>b>>a;
	for(int i=1;i<=b*a;i++)
		cin>>c[i];
	d=c[1];
	sort(c+1,c+1+b*a);
	for(int i=b*a;i>0;i--)
		if(c[i]==d)
			e=b*a-i+1;
	while(e>b+b){
		x+=2;
		e-=(b+b);
	}
	if(e>b){
		x++;
		y=b+b-e+1;
	}
	else
		y=e;
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
