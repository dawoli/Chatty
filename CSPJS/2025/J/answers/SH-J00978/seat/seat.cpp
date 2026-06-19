#include<bits/stdc++.h>
using namespace std;
struct stu{
	int score;
	bool isr;
}s[150];
bool cmp(stu a,stu b){
	return a.score>b.score;
}
int n,m;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i].score;
	for(int i=1;i<=n*m;i++)s[i].isr=0;
	s[1].isr=1;
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i].isr==1){
			int r,c;
			for(int k=1;k<=n;k++){
				if(i<=k*n&&i>=k*n-n+1){
					r=k;
					cout<<r<<" ";
					break;
				}
			}
			if(r%2==1){
				for(int k=1;k<=n;k++){
					if((r-1)*n+k==i){
						c=k;
						cout<<c;
						break;
					}
				}
			}
			else{
				for(int k=1;k<=n;k++){
					if((r-1)*n+(n-k+1)==i){
						c=k;
						cout<<c;
						break;
					}
				}
			}
			return 0;
		}
	}
	return 0;
}
