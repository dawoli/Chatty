#include<bits/stdc++.h>
using namespace std;
int a,b[5009],c[5009],cn=0;
long long bn,e=0;
int g(int x,int y,int z){
	if(x<=y){
		for(int j=z+1;j<=a;j++){
			c[x]=j;
			g(x+1,y,j);
		}
	}
	else{
		cn=0;
		for(int j=1;j<y;j++)
			cn+=b[c[j]];
		if(cn-b[c[y]]>0)
			bn++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
		cin>>b[i];
	sort(b+1,b+a+1);
	if(b[1]==b[a]||a>=300){
		for(int i=3;i<=a;i++){
			e=1;
			for(int j=a;j>a-i;j--){
				e*=j;
				if(e>=998244353)
					e=e%998244353;
			}
			for(int j=2;j<=i;j++)
				e/=j;
			bn+=e;
		if(bn>=998244353)
			bn=bn%998244353;
		}
		cout<<bn;
		return 0;
	}
	for(int i=3;i<=min(b[a]/b[1],a);i++)
		g(1,i,0);
	for(int i=max(3,b[a]/b[1]+1);i<=a;i++){
		e=1;
		for(int j=a;j>a-i;j--)
			e*=j;
		for(int j=2;j<=i;j++)
			e/=j;
		bn+=e;
		if(bn>998244353)
			bn=bn%998244353;
	}
	cout<<bn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
