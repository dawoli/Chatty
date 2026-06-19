#include<bits/stdc++.h>
using namespace std;
int n,A[2020],T;
long long C[2010][2010];
bool V[2010][2010];
long long solve1(int red,int blue){
	int i=max(red,blue)+1;
	if(i>n) return 0;//
	long long Red,Blue;
	if(V[i][blue]==false){
		Red=solve1(i,blue);
		V[i][blue]=true;
		C[i][blue]=Red;
	}else Red=C[i][blue];
	if(V[red][i]==false){
		Blue=solve1(red,i);
		V[red][i]=true;
		C[red][i]=Blue;
	}else Blue=C[red][i];
	if(A[i]==A[red]) Red+=A[i];
	if(A[i]==A[blue]) Blue+=A[i];
	return max(Red,Blue);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		memset(V,0,sizeof V);
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>A[i];
		if(n<=2000)
			cout<<solve1(1,2)<<endl;
		else return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
