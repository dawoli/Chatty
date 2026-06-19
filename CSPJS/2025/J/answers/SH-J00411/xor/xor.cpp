#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,m[100000],s,x,y;
	cin>>a>>b;
	for(int i=0;i<a;i++)
		cin>>m[i];
	for(int i=0;i<a;i++)
		for(int j=0;j<a;j++)
			if(m[j]<m[j+1]){
				s=m[j];
				m[j]=m[j+1];
				m[j+1]=s;
			}
	if(b==0)
		cout<<a/2;
	for(int i=0;i<a;i++)
		if(m[i]==1)
			x++;
		else y++;
	if(b==1){
		if(x>=y)
			cout<<x-y;
		if(x<y)
			cout<<y-x;
		}
	return 0;
}
