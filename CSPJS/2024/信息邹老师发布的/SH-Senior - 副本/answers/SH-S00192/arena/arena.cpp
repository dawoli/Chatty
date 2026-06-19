#include<bits/stdc++.h>
using namespace std;
int n,m,T;
int x0,x1,x2,x3;
int mult(int x,int y){
	int s=1;
	for(int i=0;i<y;i++)
		s*=x;
	return s;
}
int arena(){
	
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n);
	vector<int> c(m);
	for(int i=0;i<n;i++)
		cin>>a.at(i);
	for(int i=0;i<m;i++)
		cin>>c.at(i);
	int K=ceil(log(n));
	vector<vector<int>> R(K,vector<int>(mult(2,K-1)));
	for(int i=0;i<K;i++)
		for(int j=0;j<mult(2,K-i);j++)
			cin>>R[i][j];
	cin>>T;
	vector<int> A(t);
	for(int i=0;i<T;i++){
		cin>>x0>>x1>>x2>>x3;
		A.at(i)=arena();
	}
	for(int i=0;i<T;i++)
		cout<<A.at(i)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
