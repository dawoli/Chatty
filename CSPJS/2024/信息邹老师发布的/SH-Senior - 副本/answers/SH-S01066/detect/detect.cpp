#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	int T,n,m,L,V,di,vi,ai,dt;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n>>m>>L>>V;
		int car[n][2];
		int ucar[n]={};
		int det[m]={};
		for(int j=0;j<n;j++){
			cin>>di>>vi>>ai;
			float un=di+(V*V-vi*vi)*1.0/2*ai;
			if(ai>0){
				if(un<L*1.0){
				    car[j][0]=di;
				    car[j][1]=(-1);
				}
				else{
				    car[j][0]=int(un);
					car[j][1]=L;
				} 
			}else if(ai=0){
				if(vi>V){
				    car[j][0]=di;
				    car[j][1]=L;
				}
				else{
				    car[j][0]=(-1);
				    car[j][1]=(-1);
				};
			}else{
				if(vi<V){
					car[j][0]=(-1);
				    car[j][1]=(-1);
				}else{
					car[j][0]=di;
					car[j][1]=int(un);
				}
			};
		};
		for(int k=0;k<m;k++){
		    cin>>dt;
		    for(int l=0;l<n;l++){
		    	if(car[l][0]<=dt && car[l][1]>=dt){
				    det[k]++;
				    ucar[l]=1;
				}
			}
		};
		int cnt=0;
		for(int p=0;p<n;p++) cnt+=ucar[p];
		int cut=0;
		for(int o=0;o<m;o++){
		    if(det[o]>1) cut+=det[o]-1;
		};
		cout<<cnt<<' '<<cut;
	};
	
	//cout<<"2149 1605\n2354 1241\n2909 2440\n2266 2263\n2990 2098\n163 9051915 587\n1384 286\n0 2556\n1066 2711\n17388 80637\n16426 70725\n19783 57044\n67559 26319\n53536 63393\n55684 84811\n9911 74680\n8092 80156\n37099 71407\n95747 63156";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
