#include<iostream>
#include<algorithm>
using namespace std;
struct number{
	int idx;
	int cnt;
	double value;
};
number digits[10]={{0,6,0},{1,2,0.5},{2,5,0.4},{3,5,0.6},{4,4,1},{5,5,1},{6,6,1},{7,3,2.3},{8,7,1.4},{9,6,1.5}};
int t;
int n;
int ans[100010],z=0;
bool cmp(number a,number b){
	if(a.cnt!=b.cnt){
		return a.cnt>b.cnt;
	}
	return a.value<b.value;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	sort(digits,digits+10,cmp);
	cin>>t;
	while(t--){
		z=0;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n==6){
			cout<<6<<endl;
			continue;
		}
		while(n>0){
			if(n<=7){
				for(int i=0;i<10;i++){
					if(digits[i].cnt==n){
						ans[z++]=digits[i].idx;
						n-=digits[i].cnt;
						break;
					}
				}
			}else if(n>=14){
				ans[z++]=8;
				n-=digits[0].cnt;
			}else{
				if(n==8){
					ans[z++]=0;
					ans[z++]=1;
				}else if(n==9){
					ans[z++]=8;
					ans[z++]=1;
				}else if(n==10){
					ans[z++]=2;
					ans[z++]=2;
				}else if(n==11){
					ans[z++]=0;
					ans[z++]=2;
				}else if(n==12){
					ans[z++]=8;
					ans[z++]=5;
				}else{
					ans[z++]=8;
					ans[z++]=6;
				}
				break;
			}
		}
		for(int i=z-1;i>=0;i--){
			cout<<ans[i];
		}
		cout<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
