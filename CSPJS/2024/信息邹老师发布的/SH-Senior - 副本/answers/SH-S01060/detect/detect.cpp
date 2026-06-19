#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<iterator>
#include<cmath>
using namespace std;
struct Car {
	int start,v,a;
};
vector<Car> cars;
vector<int> detecter;
int find_pos_to_lim(int k,int v,int a,int start) {
	return start+ceil((double)(k*k-v*v)/(double)(2*a));
}
bool to_first_faster(int k,int v,int a,int start,int detecter_pos) {
	int s=detecter_pos-start;
	return (k*k < v*v+2*a*s);
}
bool cmp(Car a,Car b) {
	return a.start<b.start;
}
void init() {
	cars.clear();
	detecter.clear();
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		init();
		int n,m,len,v_lim;
		scanf("%d%d%d%d",&n,&m,&len,&v_lim);
		for(int i=0; i<n; i++) {
			Car input;
			scanf("%d%d%d",&input.start,&input.v,&input.a);
			cars.push_back(input);
		}
		for(int i=0; i<m; i++) {
			int a;
			scanf("%d",&a);
			detecter.push_back(a);
		}
		sort(cars.begin(),cars.end(),cmp);
		sort(detecter.begin(),detecter.end());
		int ans1=0,ans2=0;
		for(vector<Car>::iterator it=cars.begin(); it!=cars.end(); it++) {
			vector<int>::iterator detecter_pos;
			if(*lower_bound(detecter.begin(),detecter.end(),it->start)<it->start)
				detecter_pos=upper_bound(detecter.begin(),detecter.end(),it->start);
			else
				detecter_pos=lower_bound(detecter.begin(),detecter.end(),it->start);
			if(it->a<=0) {
				if(to_first_faster(v_lim,it->v,it->a,it->start,*detecter_pos)&&detecter_pos!=detecter.end()) {
					ans1++;
				}
			} else {
				int pos_to_lim=find_pos_to_lim(v_lim,it->v,it->a,it->start);
				if(upper_bound(detecter.begin(),detecter.end(),pos_to_lim)!=detecter.end());
				ans1++;
			}
		}
		printf("%d ",ans1 );
		vector<int> vec_copy=detecter;
		for(int i=0;i<detecter.size();i++) 
		{
			vector<int>::iterator not_read =detecter.begin();
			advance(not_read,i);
			detecter.erase(not_read);	
			int ans_t=0;
			for(vector<Car>::iterator it=cars.begin(); it!=cars.end(); it++) {
				vector<int>::iterator detecter_pos;
				if(*lower_bound(detecter.begin(),detecter.end(),it->start)<it->start)
					detecter_pos=upper_bound(detecter.begin(),detecter.end(),it->start);
				else
					detecter_pos=lower_bound(detecter.begin(),detecter.end(),it->start);
				if(it->a<=0) {
					if(to_first_faster(v_lim,it->v,it->a,it->start,*detecter_pos)&&detecter_pos!=detecter.end()) {
						ans_t++;
					}
				} else {
					int pos_to_lim=find_pos_to_lim(v_lim,it->v,it->a,it->start);
					if(upper_bound(detecter.begin(),detecter.end(),pos_to_lim)!=detecter.end());
					ans_t++;
				}
			}
			if(ans_t==ans1)
				ans2++;
			detecter=vec_copy;
		}
		printf("%d",ans2);
	}

	return 0;
}
