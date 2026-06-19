#include<bits/stdc++.h>
using namespace std;
int a[11]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	int cnt=0;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		else{
			for(int m=1;m<=10000000;m++){
				int m_copy=m;
				while(m>0){
					cnt+=a[m%10];
					m=(m-m%10)/10;
				}
				m=m_copy;
				if(cnt==n){
					cout<<m<<endl;
					break;
				}
				cnt=0;
			} 
		}
	} 
	return 0;
}
