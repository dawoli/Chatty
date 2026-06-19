#include<bits/stdc++.h>
using namespace std;
int T=0,n,m,L,V,cam[100010]={0},car_start,car_speed_count=0,car_speed_count_detected=0,powerfull_cam=0;
int car_start_whenspeed[100010]={0};
double car_speed[100010]={0};
bool car_slow[100010]={0};
int car_start_whenspeed_d[100010]={0};
double car_speed_d[100010]={0};
bool car_slow_d[100010]={0};
bool Road[1000010]={0};
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	cin>>T;
	int car_start_V=0,car_a=0,temp=0;
	for(int T_num=0;T_num<T;T_num++){
		cin>>n>>m>>L>>V;
		powerfull_cam=0;
		for(int i=0;i<n;i++){
			cin>>car_start>>car_start_V>>car_a;
			if(car_a<0){
				if(car_start_V<=V) {
				continue;
				}
				else {
					car_speed[car_speed_count]=car_start+double(V*V-car_start_V*car_start_V)/2/car_a;
					car_start_whenspeed[car_speed_count]=car_start;
					car_slow[car_speed_count]=true;
					car_speed_count++;
				}
			}
			if(car_a==0){
				if(car_start_V<=V) continue;
				else {
					car_speed[car_speed_count]=car_start;
					car_start_whenspeed[car_speed_count]=car_start;
					car_slow[car_speed_count]=false;
					car_speed_count++;
				}
			}
			if(car_a>0){
				temp=car_start+double(V*V-car_start_V*car_start_V)/2/car_a;
				if(temp>L) continue;
				else {
					car_speed[car_speed_count]=temp;
					car_start_whenspeed[car_speed_count]=car_start;
					car_slow[car_speed_count]=false;
					car_speed_count++;
				}
			}		
		}
		for(int i=0;i<m;i++){
			cin>>cam[i];
		}
		for(int i=0;i<car_speed_count;i++){
			if(car_slow[i]){
				for(int j=0;j<m;j++){
					if(car_speed[i]>cam[j]&&car_start_whenspeed[i]<=cam[j]){
						car_speed_d[car_speed_count_detected]=car_speed[i];
						car_start_whenspeed_d[car_speed_count_detected]=car_start_whenspeed[i];
						car_slow_d[car_speed_count_detected]=car_speed[i];
						car_speed_count_detected++;
						break;
					}
				}
			}
			else{
				for(int j=0;j<m;j++){
					if(car_speed[i]<cam[j]){
						car_speed_d[car_speed_count_detected]=car_speed[i];
						car_start_whenspeed_d[car_speed_count_detected]=car_start_whenspeed[i];
						car_slow_d[car_speed_count_detected]=car_speed[i];
						car_speed_count_detected++;
						break;
					}
				}
			}
		}
		int temp_camer=0,temp=0;
		for(int y=0;y<m;y++){
			temp_camer=cam[y];
			cam[y]=-1;
			for(int i=0;i<car_speed_count_detected;i++){
				if(car_slow_d[i]){
					for(int j=0;j<m;j++){
						if(car_speed_d[i]>cam[j]&&car_start_whenspeed_d[i]<=cam[j]){
							temp++;
							break;
						}
					}
				}
				else{
					for(int j=0;j<m;j++){
						if(car_speed_d[i]<cam[j]){
							temp++;
							break;
						}
					}
				}
			}
			if(temp==car_speed_count_detected) continue;
			else{
				powerfull_cam++;
				cam[y]=temp_camer;
			}
		}
		cout<<car_speed_count_detected<<" "<<powerfull_cam-1;
	}
	return 0;
} 
