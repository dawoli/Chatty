#include<bits/stdc++.h>
using namespace std;
int a,b,c[500009],d[500009],cn=0,n;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
		cin>>c[i];
	for(int i=1;i<=a;i++)
		d[i]=0;
	for(int i=0;i<a;i++)//²î 
		for(int j=1;j<=a-i;j++){//Ê¼ 
			n=0;
			if(i==0)
				if(c[j]==b){
					cn++;
					d[j]=1;
				}
			if(i!=0){
				for(int k=j;k<=j+i;k++)
					if(d[k]==1)
						n=1;
				if(n!=1&&(c[j+i]-c[j]==b||c[j]-c[j+i]==b||c[j+i]+c[j]==b)){
					cn++;
					for(int k=j;k<=j+i;k++)
						d[k]=1;
				}
			}
		}	
	cout<<cn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
