#include<bits/stdc++.h>
using namespace std;

const int maxn=15;
int T,n,m;
long long L,V,d[maxn],v[maxn],a[maxn],p[maxn];
vector<pair<int,int>> keep;

/*void update(int start,int end){
	bool flag=false;
	for (auto r : keep){
		auto &left=r.first,&right=r.second;
		if (end<left or start>right) continue;
		left=max(left,start);
		right=min(right,end);
		flag=true;
	}
	if (not flag) keep.push_back({start,end});
}*/

int finddetector(int i){
	int pos=0;
	if (v[i]>V) {
		while (pos<m and p[pos]<d[i]) pos++;
	}
	else {
		while (pos<m and (p[pos]-d[i])*2*a[i]<=V*V-v[i]*v[i]) pos++;
	}
	return pos;
}

void print(){
	sort(keep.begin(),keep.end());
	int cnt=0,prev=-1;
	for (auto r : keep){
		if (r.first<=prev and prev<=r.second) continue;
		prev=r.second;
		cnt++;
	}
	cout<<m-cnt<<'\n';
}

/*void print(){
	int start=0,end=0,k=0;
	while (end<m){
		while (not keep[start]) start++;
		end=start;
		while (keep[end]) end++;
		k++;
		start=end;
	}
	cout<<m-k<<'\n';
}*/

void detect(){
	int cnt=0;
	for (int i=0; i<n; i++){
		//cout<<i<<": "<<a[i]<<' '<<v[i]<<' ';
		if (a[i]>0){
			//cout<<"a>0 ";
			auto detectorpos=finddetector(i);
			//cout<<detectorpos<<' ';
			if (detectorpos<m){
				cnt++;
				keep.push_back({detectorpos,m-1});
			}
		}
		else if (v[i]>V) {
			//cout<<"v>V ";
			int newleft=0,newright=0;
			while (newleft<m and p[newleft]<d[i]) newleft++;
			while (newright<m and (p[newright]-d[i])*2*(-a[i])<v[i]*v[i]-V*V) newright++;
			newright--;
			//cout<<newleft<<' '<<newright<<' ';
			if (newleft<=newright){
				cnt++;
				keep.push_back({newleft,newright});
			}
		}
		//cout<<"done\n";
	}
	cout<<cnt<<' ';
	print();
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	cin>>T;
	for (int i=0; i<T; i++){
		cin>>n>>m>>L>>V;
		for (int j=0; j<n; j++){
			cin>>d[j]>>v[j]>>a[j];
		}
		for (int j=0; j<m; j++){
			cin>>p[j];
		}
		detect();
	}
} 
