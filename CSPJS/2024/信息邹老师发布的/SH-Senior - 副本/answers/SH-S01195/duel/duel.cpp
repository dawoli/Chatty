#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,r[N],bi=1,sum,zt[N],l1,r1;
bool all12(){
	for(int i=1;i<=n;i++)if(r[i]>2)return 0;
	return 1;
}
void s12(){
	int s1=0,s2=0;
	for(int i=1;i<=n;i++){
		if(r[i]==1)s1++;
		else s2++;
	}
	cout<<abs(s2-s1)+s2<<endl; 
} 
int main(){
	freopen("duel.in","t",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>r[i],zt[i]=1;
	sort(r+1,r+n+1);
	if(all12()==1){
		s12();
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(r[j]>r[i]&&zt[j]==1){
				sum++;
				zt[j]=0;
			}
		}
	}	
	cout<<n-sum<<endl;		
} 
