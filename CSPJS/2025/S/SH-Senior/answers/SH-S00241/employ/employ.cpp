#include<iostream>
#include<cstring>
using namespace std;
int n,m;
string l;
int a[1145];
int slv(int x){
	long long as1=1;
	for(int i=2;i<=x;i++){
		as1*=i;
		as1%=998244353;
		cout<<as1<<endl;
	}
	return as1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>l;
	int q=n;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]==0)
	q--;
    }
    if(m==n||m>18)
    cout<<0;
    else if(m==1) 
    cout<<slv(n-1)*q%998244353;	
	else
	cout<<slv(n);   
}
