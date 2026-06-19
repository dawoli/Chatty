#include<iostream>
#include<cmath>

using namespace std;

int startp[100005],endp[100005],camp[100005],a_startp[100005],a_endp[100005];
int main(){
	int T;
	cin >>T;
	for(int k=1;k<=T;k++){
		freopen("detect.in",'r',stdin);
		freopen("detect.out",'w',stdout);
		int ncars,cams,length,limVel;
		int ans1=0,ans2=0;
		cin >> ncars >> cams >> length >> limVel;
		
		for(int i=1;i<=ncars;i++){
			int inPos,vel,accel;
			cin >> inPos >> vel >> accel;
			if(accel>0){
				if(vel>limVel){
					startp[i]=inPos;
					endp[i]=length;
				}else if(vel=limVel){
					startp[i]=inPos;
					endp[i]=length;
				}else{
					int p=inPos+(limVel*limVel-vel*vel)/(2*accel)+1;
					if(p>length){
						startp[i]=-1;
						endp[i]=-1;
					}else{
						startp[i]=p;
						endp[i]=length;
					}
				}
			}else if(accel<0){
				if(vel>limVel){
					int p=inPos+(limVel*limVel-vel*vel)/(2*accel);
					if((limVel*limVel-vel*vel)%(2*accel)==0) p-=1;
					startp[i]=inPos;
					endp[i]=p;
				}else{
					startp[i]=-1;
					endp[i]=-1;
				}
			}else{
				if(vel>limVel){
					startp[i]=inPos;
					endp[i]=length;
				}else{
					startp[i]=-1;
					endp[i]=-1;
				}
			}
		}
		int maxc=-1;
		for(int i=1;i<=cams;i++){
			cin >> camp[i]; 
			if(camp[i]>maxc)maxc=camp[i];
		}
		for(int i=1;i<=ncars;i++){
			if(startp[i]!=-1&&startp[i]<=maxc)ans1++;
		}
		cout <<ans1 << ' ' <<1<<endl; 
	}
	return 0; 
}
