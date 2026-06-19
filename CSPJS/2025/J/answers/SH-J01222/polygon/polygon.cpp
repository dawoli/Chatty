#include<bits/stdc++.h>
using namespace std;
int a[11451],cnt,n;
vector<int> v;
void check(){
	int sum=0,ma=-1;
	for(auto c:v){
		sum+=c;
		ma=max(ma,c);
	}
	if(ma*2<sum){
		cnt++;
		//for(auto c:v){
		//	cout<<c<<' ';
		//}cout<<endl<<ma<<' '<<sum<<endl;
	}
	return ;
}
void f(int s,int c){
	if(s==0){
		check();
		return ;
	}
	for(int i=c;i<=n;i++){
		if(a[i]!=0){
			int n=a[i];
			v.push_back(a[i]);
			a[i]=0;
			f(s-1,i);
			a[i]=n;
			v.pop_back();
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		f(i,0);
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
