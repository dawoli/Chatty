#include<bits/stdc++.h>
using namespace std;
struct c{
	int num;
	bool color;
};
int T,n,x;
vector<c> A;
vector<int> C;
bool cmp(c x,c y){
	return x.num<y.num;
}
int score(){
	sort(A.begin(),A.end(),cmp);
	int sco=0;
	for(int i=0;i<n-1;i++)
		if(A.at(i).num==A.at(i+1).num)
			sco+=A.at(i).num;
	return sco;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		A.resize(n);
		for(int j=0;j<n;j++){
			cin>>x;
			A.at(j).num=x;
		}
		C.push_back(score());
	}
	for(int i:C)
		cout<<i<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
