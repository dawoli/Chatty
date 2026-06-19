#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100009];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cout<<-1<<endl;
		}
		else if(a[i]==2){
			cout<<1<<endl;
		}
		else if(a[i]==3){
			cout<<7<<endl;
		}
		else if(a[i]==4){
			cout<<4<<endl;
		}
		else if(a[i]==5){
			cout<<2<<endl;
		}
		else if(a[i]==6){
			cout<<6<<endl;
		}
		else if(a[i]==7){
			cout<<8<<endl;
		}
		else if(a[i]==10){
			cout<<22<<endl;
		}
		else if(a[i]==12){
			cout<<28<<endl;
		}
		else{
			ll ans[10009],j=1;
			while(a[i]>=1){
				if(a[i]==2){
					ans[j]=2;
					j++;
					break;
				}
				else if(a[i]==3){
					ans[j]=7;
					j++;
					break;
				}
				else if(a[i]==4){
					ans[j]=4;
					j++;
					break;
				}
				else if(a[i]==5){
					ans[j]=2;
					j++;
					break;
				}
				else if(a[i]==6){
					ans[j]=0;
					j++;
					break;
				}
				else if(a[i]==7){
					ans[j]=8;
					j++;
					break;
				}
				else if(a[i]==8){
					ans[j]=0;
					j++;
					ans[j]=1;
					break;
				}
				else if(a[i]==9){
					ans[j]=1;
					j++;
					ans[j]=8;
					break;
				}
				else if(a[i]==10){
					ans[j]=0;
					j++;
					ans[j]=4;
					break;
				}
				else if(a[i]==11){
					ans[j]=0;
					j++;
					ans[j]=2;
					break;
				}
				else if(a[i]==12){
					ans[j]=0;
					j++;
					ans[j]=0;
					break;
				}
				else if(a[i]==13){
					ans[j]=0;
					j++;
					ans[j]=8;
					break;
				}
				else if(a[i]==14){
					ans[j]=8;
					j++;
					ans[j]=8;
					break;
				}
				else if(a[i]==15){
					ans[j]=0;
					j++;
					ans[j]=1;
					j++;
					ans[j]=8;
					break;
				}
				else if(a[i]>=16){
					ans[j]=8;
					j++;
					a[i]-=7;
				}
			}
			ll xx;
			sort(ans+1,ans+j+1);
			if(ans[1]==0){
				for(int x=1;x<=j;x++){
					if(ans[x]!=0){
						xx=ans[x];
						ans[1]=xx;
						ans[x]=0;
						break;
					}
				}	
			}
			for(int x=1;x<=j;x++){
				cout<<ans[x];
			}
			cout<<endl;
		}
	}
	return 0;
}
