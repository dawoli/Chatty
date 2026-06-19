#include<bits/stdc++.h>
using namespace std;
int n,m,me;
bool cmp (int a,int b){
	return a>b;
}
int cell(double a){
	int t=floor(a);
	if(a!=t)
	return t+1;
	else return t;
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;int N=n*m;
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	me=a[0];
	
	sort(a.begin(),a.end(),cmp);
	
	/*for(int i=0;i<N;i++){
		cout<<a[i]<<" ";
	}*/
	
	for(int i=0;i<N;i++){
		if(a[i]==me){
			i+=1;
			
			
			
			int c,r,g=i%n;//cÁÐrÐÐ 
			
			if(g!=0){
				c=i/n+1;
			}else {
				c=i/n;
			}	
			
			int t=c*n-i;
			//cout<<i<<" "<<t<<"\n";
			if(c%2==1){
				r=n-t;
			}else{
				int t1=n-t;
				int t2=n-t1+1;
				r=t2;
			}
			
			
			cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
}
