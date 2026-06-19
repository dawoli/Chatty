#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100010],a2[100010],a3[100010],tot1,tot2,tot3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=0;i<t;++i){
		cin>>n;
		for (int j=0;j<n;++j){
			cin>>a1[j]>>a2[j]>>a3[j];
			if (a1[j]>a2[j]){
				if (a1[j]>a3[j]){
					tot1+=a1[j]; 
				}else{
					tot3+=a3[j];
				}
			}
			if (a2[j]>a1[j]){
				if (a2[j]>a3[j]){
					tot2+=a2[j];
				}else{
					tot3+=a3[j];
				}
			}
			if (a3[j]>a1[j]){
				if (a3[j]>a2[j]){
					tot3+=a2[j];
				}else{
					tot2+=a2[j];
				}
			}
		}
		cout<<tot1+tot2+tot3;
	}
	return 0; 
}
