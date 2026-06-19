#include<iostream>
using namespace std;
int head,ans;
int qwe,asd;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long int n,t;
	cin>>n;
	if(n>10){
		int a[n]={0},b[n]={0};
		for(int i=0;i<n;i++){
			
			cin>>t;
			for(int j=0;j<i;j++){
				if(a[j]==t){
					b[j]+=1;
					break;
				}else{
					a[head]=t;
					b[head++]+=1;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(b[i]>=ans) ans=b[i];
		}
		cout<<ans;
	}else{
		
		asd=n;
		int mon[n],att[n]={0};
		for(int i=0;i<n;i++){
			cin>>mon[i];
		}
		for(int i=0;i<n;i++){
			for(int j=n-1;j>0;j--){
				if(mon[j]<mon[j-1]){
					qwe=mon[j];
					mon[j]=mon[j-1];
					mon[j-1]=qwe;
				}
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(mon[i]==mon[j]) break;
				if(att[j]==0){
					att[j]=1;
					asd--;
					break;
				}
			}
		}
		cout<<asd;
	}
	return 0;
}
