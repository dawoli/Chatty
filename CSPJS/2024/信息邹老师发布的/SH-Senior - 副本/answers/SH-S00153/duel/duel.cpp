#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct name{
	ll num,leave;
};
name ans[100009];
ll n,a[100009],j=1; 
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a,a+n+1);
	ll t=a[1];
	ans[1].leave=1;
	ans[1].num=1;
	for(int i=2;i<=n;i++){
		if(a[i]==t){
			ans[j].leave++;
			ans[j].num++;	
		}
		else{
			j+=1;
			ans[j].leave++;
			ans[j].num++;
			t=a[i];				
		}
	}
	int flag=0;
	for(int i=1;i<=j-1;i++){
		if(flag==1)
			break;
		int k=i+1;		
		while(1){
			if(ans[k].leave>=ans[i].num){
				ans[k].leave-=ans[i].num;	
				ans[i].num=0;
				break;			
			}
			else if(k>=j){
				ans[i].num-=ans[k].leave;
				flag=1;
				break;						
			}
			else{
				ans[i].num-=ans[k].leave;	
				ans[k].leave=0;	
				k++;						
			}
		}
	}
	ll sum=0;
	for(int i=1;i<=j;i++)	
		sum+=ans[i].num;
	cout<<sum;
	return 0;
} 
