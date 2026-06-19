#include <bits/stdc++.h>

int d[100001];
int v[100001];
int a[100001];
int p[100001];
bool speedLimitExceeded[100001];
bool detected[100001];
std::pair<int,int> sorted_detectors_sequence[100001]; 
int n,m,L,V;
bool check(int car,int p){
	if(p<d[car]) return false;
	int square_speed=v[car]*v[car]+2*a[car]*(p-d[car]);
	if(square_speed<=0) return false;
	return square_speed>V*V;
}
bool sortFunc(std::pair<int,int> a,std::pair<int,int> b){
	return a.second>b.second;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int used=0;
		int overspeed=0; 
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d",&p[i]);
		}
		for(int i=0;i<n;i++){
			bool flag=false;
			for(int j=0;j<m;j++){
				if(check(i,p[j])) {
					sorted_detectors_sequence[j].first=j;
					sorted_detectors_sequence[j].second++;
					if(!flag){
						flag=true;
						speedLimitExceeded[i]=true;
						overspeed++;
					}
//					break;
				}
			}
		}
		std::sort(&sorted_detectors_sequence[0],&sorted_detectors_sequence[n],sortFunc);
//		for(int i=0;i<m;i++){
//			printf("%d %d\n",sorted_detectors_sequence[i].first,sorted_detectors_sequence[i].second);
//		}
		for(int i=0;i<m;i++){
			if(i>0){
				int max_unique_detections=0;
				int best_detector_index=-1; 
				for(int index=0;index<m;index++){
					if(index==i) continue;
					int matches=0;
					for(int j=0;j<n;j++){
					if(speedLimitExceeded[j]&&!detected[j]&&check(j,p[sorted_detectors_sequence[index].first])){
						for(int k=0;k<n;k++){
							if(check(k,p[sorted_detectors_sequence[index].first])) matches++;
						}
					}
					if(matches>max_unique_detections){
						max_unique_detections=matches;
						best_detector_index=index;
					}
				}
				}
				
				used++;
					for(int k=0;k<n;k++){
						if(check(k,p[sorted_detectors_sequence[best_detector_index].first])) detected[k]=true;
					}
					bool all_detected=true;
					for(int mm=0;mm<n;mm++) if(!detected[mm]) all_detected=false;
					if(all_detected) break;
					if(best_detector_index==-1){
						used--;
						break;
					}
			}
			else{
			
			for(int j=0;j<n;j++){
				if(speedLimitExceeded[j]&&!detected[j]&&check(j,p[sorted_detectors_sequence[i].first])){
					used++;
					for(int k=0;k<n;k++){
						if(check(k,p[sorted_detectors_sequence[i].first])) detected[k]=true;
					}
					break;
				}
//				break;
		}
		}
		}
		printf("%d %d\n",overspeed,m-used);
		memset(speedLimitExceeded,0,sizeof(speedLimitExceeded));
		memset(detected,0,sizeof(detected));
	}
	return 0;
}