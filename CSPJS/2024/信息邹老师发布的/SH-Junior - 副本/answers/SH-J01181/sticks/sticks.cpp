#include<iostream>
using namespace std;
int a[15];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	a[2]=1,a[3]=7,a[4]=4,a[5]=2,a[6]=6,a[7]=8,a[8]=10,a[9]=18,a[10]=22,a[11]=20,a[12]=28,a[13]=68;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string s="";
		cin>>x;
		if(x==1){
			cout<<-1;
		}else if(x<13){
			cout<<a[x];
		}else{
			s+=char(a[x%7+7]/10+48);
			s+=char(a[x%7+7]%10+48);
			for(int j=1;j<=x/7-1;j++){
				s+='8';
			}
			cout<<s;
		}
		cout<<endl;
	}
	return 0;
}
