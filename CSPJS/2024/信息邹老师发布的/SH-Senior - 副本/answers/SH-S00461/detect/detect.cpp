#include<iostream>
#include<algorithm>
using namespace std;
struct information{
	int startp,initspeed,addition;
};
bool comparison(pair<int,int> a,pair<int,int> b){
	if(a.first!=b.first)return a.first<b.first;
	return a.second<b.second;
}
int upb(int arr[],int len,double val){
	if(val<arr[0])return arr[0];
	int start=0,end=len-1;
	int mid=len;
	while(start<=end){
		mid=(start+end)/2;
		if(val==arr[mid])return arr[mid];
		else if(val<arr[mid]){
			end=mid-1;
		}
		else start=mid+1;
	}
	return arr[start];
}
int lwb(int arr[],int len,double val){
	if(val>arr[len-1])return arr[len-1];
	int start=0,end=len-1;
	int mid=len;
	while(start<=end){
		mid=(start+end)/2;
		if(val==arr[mid])return arr[mid];
		else if(val<arr[mid]){
			end=mid-1;
		}
		else start=mid+1;
	}
	return arr[end];
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int inquiry;
	cin>>inquiry;
	int vehicles,tests,length,limit;
	while(inquiry--){
		cin>>vehicles>>tests>>length>>limit;
		struct information info[vehicles];
		for(int i=0;i<vehicles;i++){
			cin>>info[i].startp>>info[i].initspeed>>info[i].addition;
		}
		int testpoints[tests];
		for(int i=0;i<tests;i++){
			cin>>testpoints[i];
		}
		int exceeded=0;
		pair<int,int> ranges[vehicles];
		int index=0;
		for(int i=0;i<vehicles;i++){
			if(info[i].addition==0){
				if(info[i].initspeed>limit){
					int spoint=upb(testpoints,tests,info[i].startp);
					int epoint=lwb(testpoints,tests,length);
					if(spoint<=epoint){
						ranges[index]=make_pair(spoint,epoint);index++;
						exceeded++;
					}
				}
			}
			else if(info[i].addition>0){
				if(info[i].initspeed>limit){
					int spoint=upb(testpoints,tests,info[i].startp);
					int epoint=lwb(testpoints,tests,length);
					if(spoint<=epoint){
						ranges[index]=make_pair(spoint,epoint);index++;
						exceeded++;
					}
				}
				else{
					double _3S=(limit*limit-info[i].initspeed*info[i].initspeed)/2.0/info[i].addition;
					if(info[i].startp+_3S<length){
						int spoint=upb(testpoints,tests,(double)info[i].startp+_3S);
						int epoint=lwb(testpoints,tests,length);
						if(spoint<=epoint){
							ranges[index]=make_pair(spoint,epoint);index++;
							exceeded++;
						}
					}
				}
			}
			else{
				double _3S=(limit*limit-info[i].initspeed*info[i].initspeed)/2.0/info[i].addition;
				if(info[i].startp+_3S<length){
					int spoint=upb(testpoints,tests,info[i].startp);
					int epoint=lwb(testpoints,tests,(double)info[i].startp+_3S);
					if(spoint<=epoint){
						ranges[index]=make_pair(spoint,epoint);index++;
						exceeded++;
					}
				}
			}
		}
		cout<<exceeded<<' ';
		sort(ranges,ranges+index,comparison);
		int req=0;
		for(int i=0;i<index-1;i++){
			if(ranges[i].second>=ranges[i+1].first){
				req++;
				ranges[i+1]=make_pair(ranges[i+1].first,ranges[i].second);
			}
		}
		cout<<tests-req<<endl;
	}
	return 0;
}

