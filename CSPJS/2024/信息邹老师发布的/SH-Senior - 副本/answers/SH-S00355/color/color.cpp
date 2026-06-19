#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<set>
using namespace std;

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,cnt=0;
		cin>>n;
		vector<int> num;
		multiset<int> nnn;
		multiset<int> uuu;
		while(n--){
			int a;
			cin>>a;
			num.push_back(a);
			nnn.insert(a);
		}
		int exa=-1,exb=-1;
		for(int i : num){
			if(i==exa){
				cnt += i;
				uuu.insert(i);
				uuu.insert(i);
				exa=-1;
				continue;
			}
			if(i==exb){
				cnt += i;
				uuu.insert(i);
				uuu.insert(i);
				exb=-1;
				continue;
			}
			int ex = nnn.count(i)-uuu.count(i)>1?i:-1;
			if(exa<exb){
				exa=ex;
			}else{
				exb=ex;
			}
//			cout<<exa<<" "<<exb<<endl;
		}
//		set<char>nums;
//		for(int i = 0;i < num.size();i++){
//			char a = num[i];
//			if(nums.count(a)){
//				num.erase(i,1);
//				num.erase(num.find_first_of(a),1);
//				cnt+=a-'0';
//				nums.clear();
//				i-=2;
//			}else{
//				nums.insert(a);
//			}
//		}
//		nums.clear();
//		for(int i = 0;i < num.size();i++){
//			char a = num[i];
//			if(nums.count(a)){
//				num.erase(i,1);
//				num.erase(num.find_first_of(a),1);
//				cnt+=a-'0';
//				nums.clear();
//				i-=2;
//			}else{
//				nums.insert(a);
//			}
//		}
		cout<<cnt<<endl;
	}
	return 0;
}
