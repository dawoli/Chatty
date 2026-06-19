#include <iostream>
using namespace std;
int t,n,a1[100005],a2[100005],a3[100005],chosen[100005];
int inp1,inp2,inp3;
int cnt1,cnt2,cnt3;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	//this is a O(t*n*n) algorithm
	//but the constants are small
	//so actually its more like a O(n^2) one
	//not to mention if there were no dept. with over half ppl
	//then the average would be even lower
	//so id expect around 60+ for this one
	while(t--){
		cin>>n;
		//initialization all over again
		for(int i=0;i<100005;i++){
			chosen[i]=0;
		}
		ans=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		//input
		for(int i=0;i<n;i++){
			cin>>inp1>>inp2>>inp3;
			a1[i]=inp1;
			a2[i]=inp2;
			a3[i]=inp3;
			if(inp1>inp2){
				if(inp1>inp3){
					cnt1++;
				}
				else{
					cnt3++;
				}
			}
			else{
				if(inp2>inp3){
					cnt2++;
				}
				else{
					cnt3++;
				}
			}
		}
		//actually all three ifs are basically the same
		//except that they were operated on different lists
		//i shouldve used vectors but whatever now
		if((cnt1>n/2)||(cnt2>n/2)||(cnt3>n/2)){
			if(cnt1>n/2){
				for(int i=0;i<n/2;i++){
					int maxind=0;
					while(chosen[maxind]==1){
						maxind++;
					}
					for(int j=0;j<n;j++){
						if(chosen[j]==0){
							if(a1[j]-max(a2[j],a3[j])>a1[maxind]-max(a2[maxind],a3[maxind])){
								maxind=j;
							}
						}
					}
					ans+=a1[maxind];
					chosen[maxind]=1;
				}
				for(int i=0;i<n;i++){
					if(chosen[i]==0){
						ans+=max(a2[i],a3[i]);
					}
				}
			}
			if(cnt2>n/2){
				for(int i=0;i<n/2;i++){
					int maxind=0;
					while(chosen[maxind]==1){
						maxind++;
					}
					for(int j=0;j<n;j++){
						if(chosen[j]==0){
							if(a2[j]-max(a1[j],a3[j])>a2[maxind]-max(a1[maxind],a3[maxind])){
								maxind=j;
							}
						}
					}
					ans+=a2[maxind];
					chosen[maxind]=1;
				}
				for(int i=0;i<n;i++){
					if(chosen[i]==0){
						ans+=max(a1[i],a3[i]);
					}
				}
			}
			if(cnt3>n/2){
				for(int i=0;i<n/2;i++){
					int maxind=0;
					while(chosen[maxind]==1){
						maxind++;
					}
					for(int j=0;j<n;j++){
						if(chosen[j]==0){
							if(a3[j]-max(a2[j],a1[j])>a3[maxind]-max(a2[maxind],a1[maxind])){
								maxind=j;
							}
						}
					}
					ans+=a3[maxind];
					chosen[maxind]=1;
				}
				for(int i=0;i<n;i++){
					if(chosen[i]==0){
						ans+=max(a1[i],a2[i]);
					}
				}
			}
		}
		//this is what we would do if there were
		//no department that had more than
		//half of members willing to go to
		else{
			for(int i=0;i<n;i++){
				ans+=max(a1[i],max(a2[i],a3[i]));
			}
		}
		//give out the answer
		cout<<ans<<endl;
	}
	return 0;
}
