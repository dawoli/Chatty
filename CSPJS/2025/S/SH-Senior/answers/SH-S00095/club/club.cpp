#include <bits/stdc++.h>
using namespace std;
long long t,ma,mb,mc,maxn,ju,sum,ja = 1,jb = 1,jc = 1;
long long n,a1[100010],b[100010],c[100010],a[100010][5];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i<=t;i++){
		cin >>n;
		ju = n/2;
		for(int i = 1;i<=n;i++){
			cin >> a[i][1] >>a[i][2] >>a[i][3];
		}
		for(int i = 1;i<=n;i++){
			a1[i] = a[i][1];
			b[i] = a[i][2];
			c[i] = a[i][3];
		}
		sort(a1+1,a1+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i = 1;i<=n;i++){
			if(a[i][2] == 0 && a[i][3] == 0){
				if( ma < ju){
					ma+=1;
					sum += a[i][1];
					ja += 1;
				}
				
			}
		}
		for(int i = 1;i<=n;i++){
			maxn = max(max(a[i][1],a[i][2]),a[i][3]);
			if(maxn == a[i][1] ){
				if(ma <= ju){
					sum+=a[i][1];
					ma += 1;
				}
				else if(a[i][2] > a[i][3] && mb <= ju){
					if(a[i][2] > b[jb] || mc == ju){
						sum += a[i][2];
						mb += 1;
					}
					else{
						jb+=1;
						sum+=a[i][3];
						mc += 1;
					}
					
				}
				
			}
			else if(maxn ==a[i][2] ){
				if(mb <= ju){
					sum+=a[i][2];
					mb += 1;
				}
				else if(a[i][1] > a[i][3] && ma <= ju){
					if(a[i][1] > a1[ja] || mc == ju){
						sum += a[i][1];
						ma += 1;
					}
					else{
						ja += 1;
						sum+=a[i][3];
						mc += 1;
					}
					
				}
			}
			else{
				if(mc <= ju){
					sum+=a[i][3];
					mc += 1;
				}
				else if(a[i][1] > a[i][2] && ma <= ju){
					if(a[i][1] > a1[ja] || mb  == ju){
						sum += a[i][1];
						ma += 1;
					}
					else{
						ja +=1;
						sum+=a[i][2];
						mb += 1;
					}
				}
			}
			
		}
		ma = mb = mc = 0;
		
		cout << sum<<endl;
		sum = 0;
	}
	
	
	return 0;
} 
