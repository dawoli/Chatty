# include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w", stdout);
	long long int n; //多少个小怪兽
	cin >> n;
	long long int left=n; //剩下了多少个 
	int mList[n]; //怪兽数值list
	for (int i=0;i<n;i++){
		cin>>mList[i];
	} 
	sort(mList, mList+n);
	int left_ind = 0;
	int right_ind = 0;
	while (right_ind<n-1){
		right_ind += 1;
		if  (mList[right_ind]>mList[left_ind]){
			//cout<<"before:   left"<<left_ind<<" right"<<right_ind<<" left"<<left<<endl;
			left_ind += 1;
			left-=1;
			//cout<<"after:   left"<<left_ind<<" right"<<right_ind<<" left"<<left<<endl;

			continue;}
		//cout<<"nothingbefore:   left"<<left_ind<<"  right"<<right_ind<<"  left"<<left<<endl;
		//cout<<"nothingafter:   left"<<left_ind<<"  right"<<right_ind<<"  left"<<left<<endl;

	}
	
	//for (int j=0;j<n;j++){
	//	cout<<mList[j]<<' ';
	//}
	cout<<left;
	return 0;
} 
