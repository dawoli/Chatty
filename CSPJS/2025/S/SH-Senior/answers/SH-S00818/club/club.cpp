#include<bits/stdc++.h>
using namespace std;
int d1[100005],d2[100005],d3[105005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int e=0;e<t;e++){
		int n,d1x=0,d2x=0,d3x=0,cnt=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int a1,a2,a3;
			scanf("%d %d %d",&a1,&a2,&a3);
			if(a1>=a2){
				if(a2>=a3){
					cnt+=a1;
					d1[d1x]=a1-a2;
					d1x++;
				}else{
					if(a1>=a3){
						cnt+=a1;
						d1[d1x]=a1-a3;
						d1x++;
					}else{
						cnt+=a3;
						d3[d3x]=a3-a1;
						d3x++;
					}
				}
			}else{
				if(a2>=a3){
					cnt+=a2;
					d2[d2x]=a2-max(a1,a3);
					d2x++;
				}else{
					cnt+=a3;
					d3[d3x]=a3-a2;
					d3x++;
				}
			}
			
		}
		if(d1x>(n/2)){
			sort(d1,d1+d1x);
			for(int i=0;i<d1x-(n/2);i++){
				cnt-=d1[i];
			}
		}
		if(d2x>(n/2)){
			sort(d2,d2+d2x);
			for(int i=0;i<d2x-(n/2);i++){
				cnt-=d2[i];
			}
		}
		if(d3x>(n/2)){
			sort(d3,d3+d3x);
			for(int i=0;i<d3x-(n/2);i++){
				cnt-=d3[i];
			}
		}
		printf("%d",cnt);
		cout<<endl;
	}
	return 0;
} 
