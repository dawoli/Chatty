#include<bits/stdc++.h>
using namespace std;
int N,M,L,V;
struct car{
	int d,v,a;
	double speed(int pos){
		return sqrt((pos-d)*a*2+v*v);
	}
};
vector<car> cars;
struct detector{
	int pos;
	set<int> detects;
	int v;
	void detect(){
		for(int i = 0;i < cars.size();i++){
			car c = cars[i];
			if(c.d<=pos&&c.speed(pos)>V){
				detects.insert(i);
			}
		}
	}
};
vector<detector> detectors;
bool different(set<int> a,set<int> b){
	for(int i : a){
		if(b.count(i)) return 0;
	}
	return 1;
}
bool cmp(detector a,detector b){
	return a.detects.size()==b.detects.size()?a.v>b.v:a.detects.size()<b.detects.size();
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cars.clear();
		detectors.clear();
		cin>>N>>M>>L>>V;
		multiset<int>detecteds;
		set<int>detecteds_norepeat;
		for(int i = 0;i < N;i++){
			car c;
			cin>>c.d>>c.v>>c.a;
			cars.push_back(c);
		}
		for(int i = 0;i < M;i++){
			detector d;
			cin>>d.pos;
			d.v = 1;
			d.detect();
			detecteds.insert(d.detects.begin(),d.detects.end());
			detecteds_norepeat.insert(d.detects.begin(),d.detects.end());
			detectors.push_back(d);
		}
		int cnt = 0;
		for(int i = 0;i < detectors.size();i++){
			for(int j = i+1;j < detectors.size();j++){
				if(different(detectors[i].detects,detectors[j].detects)){
					sort(detectors.begin(),detectors.end(),cmp);
					detectors[i].detects.insert(detectors[j].detects.begin(),detectors[j].detects.end());
					detectors[i].v+=detectors[j].v;
					detectors.erase(detectors.begin()+j);
				}
			}
		}
		sort(detectors.begin(),detectors.end(),cmp);
		for(int i = 0;i < detectors.size();i++){
			detector d = detectors[i];
			bool can = 1;
			for(int num:d.detects){
				if(detecteds.count(num)<=1){
					can = 0;
					break;
				}
			}
			if(can){
				cnt+=d.v;
				for(int num:d.detects){
					int nu = detecteds.erase(num);
					for(int i = 0;i < nu-1;i++){
						detecteds.insert(num);
					}
				}
			}
			
		}
		cout<<detecteds_norepeat.size()<<" "<<cnt<<endl;
	}
	return 0;
}
