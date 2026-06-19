#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int t,n;
int lv[100005][4];
int chosenarr[100005];
int diff[100005]; 
int sorteddiff[100005];
int c[4];
int ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int qwerty=1;qwerty<=t;qwerty++){
		for(int i=0;i<=3;i++)c[i]=0;
		ans=0;
		for(int i=0;i<=100000;i++){
			for(int j=1;j<=3;j++){
				lv[i][j]=0;
				
			}
			chosenarr[i]=0;
			diff[i]=0;
			sorteddiff[i]=0; 
		}
		
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> lv[i][j]; 
			}
			int m=max(max(lv[i][1],lv[i][2]),lv[i][3]);
			ans+=m;
			//cout << m << ' ';
			int chosen=0;
			for(int j=1;j<=3;j++){
				if(lv[i][j]==m){
					if(chosen==0)chosen=j;
					else{
						chosen=0;
						break;
					}
				}
			}
			c[chosen]++;
			chosenarr[i]=chosen;
			//cout << chosen << ' ';
			if(chosen!=0){
				int k;
				if(chosen==1){
					k=max(lv[i][2],lv[i][3]);
				}else if(chosen==2){
					k=max(lv[i][1],lv[i][3]);
				}else{
					k=max(lv[i][1],lv[i][2]);
				}
				diff[i]=m-k;
				//cout << m-k << endl;
			}
		}
		for(int i=1;i<=3;i++){
			if(c[i]>(n/2)){
				int countr=1;
				for(int j=1;j<=n;j++){
					if(chosenarr[j]==i){
						sorteddiff[countr]+=diff[j];
						countr++;
					}
				}
				sort(sorteddiff+1,sorteddiff+countr);
				for(int j=1;j<=c[i]-n/2;j++){
					ans-=sorteddiff[j];
				}
				break;
			}
		}
		cout << ans << endl;
	}
	
	
	
	return 0;
} 
