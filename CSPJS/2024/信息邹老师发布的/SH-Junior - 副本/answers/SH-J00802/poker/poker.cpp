#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[1000][1000];
int b[4]={int('D'),int('H'),int('C'),int('S')};
int d[13]={int('A'),2+'0',3+'0',4+'0',5+'0',6+'0',7+'0',8+'0',9+'0',int('T'),int('J'),int('Q'),int('K')};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	char c[3];
	for(int i = 1;i<=n;++i){
		cin>>c[1]>>c[2];
		a[c[1]][c[2]] = 1;
	}
	for(int i = 0;i<4;++i)
		for(int j = 0;j<13;++j){
			if(a[b[i]][d[j]]==0)
				ans++;
		}
	cout<<ans;
	return 0;
}
