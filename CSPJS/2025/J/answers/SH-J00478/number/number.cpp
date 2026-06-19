#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
string c;
char a[maxn];
int b[maxn];
bool cmp(int x,int y){
	if(b[x]>=b[y]) return y>x;
	else return y<x;  
}
int ans;
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>c;
	
	for(int i=0;i<c.length();i++){

		if(c[i]!='0'&&c[i]!='1'&&c[i]!='2'&&c[i]!='3'&&c[i]!='4'&&c[i]!='5'&&c[i]!='6'&&c[i]!='7'&&c[i]!='8'&&c[i]!='9'){
			c[i]-=c[i];
			b[i]=c[i];
			sort(b,b+1,cmp);
			if(b[i]=='1'||b[i]=='2'||b[i]=='3'||b[i]=='4'||b[i]=='5'||b[i]=='6'||b[i]=='7'||b[i]=='8'||b[i]=='9') b[i]-=48;
			 
			
		}
		else{
			b[i]=c[i];
			b[i]-=48;
			sort(b,b+1,cmp);
			
		}
		
		//ans=max(c[i],c[i+1]);
		cout<<b[i];
	}
	
	return 0;
}
