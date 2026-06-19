#include<iostream>
using namespace std;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int l2[1000000]={0};
		int k,ji,mx=0,mi=0;
		cin>>k;
		int l[k];
		for(int j=0;j<k;j++){
			cin>>l[j];
			l2[l[j]]++;
		}
		for(int j=0;j<1000000;j++){
			if(l2[j]*j>mx){
				mi=mx;
				mx=l2[j]*j;
			}
			else if(l2[j]*j>mi){
				mi=l2[j]*j;
			}
		}
		cout<<mx+mi<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}



