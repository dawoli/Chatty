#include <bits/stdc++.h>
using namespace std;
#define L 1000100
#define N 100100
#define pb push_back
int n , m , l , velocityLimit;
inline int read(){
	int res = 0;
	bool negative = false;
	char getChar = getchar();
	for( ; getChar < '0' || getChar > '9' ; getChar = getchar()){
		if(getChar == '-')
			negative = true;
	}
	for( ; getChar >= '0' && getChar <= '9' ; getChar = getchar()){
		res = (res << 1) + (res << 3) + (getChar ^ '0');
	}
	return negative ? -res : res;
}
inline void p(int x){
	cout << x << " ";
}

inline void p1(string str , int x){
	cout << str << ":" << x << " ";
}
inline void pd(string str , double x){
	cout << str << ":" << x << " ";
}
bool arr[L];
int monitors[L]; //摄像头-前缀和
struct node{
	int ov;
	vector<int > cars;
}overspeed[L];
struct Cars{
	int enterLocation , v , a; 
}car[N];
stack<int> sta;
stack<int> aux;
int main(){
	freopen("detect5.in" , "r" , stdin);
	freopen("detect.out" , "w" , stdout);
	int t = read();
	while(t--){
		int ans1 = 0 , ans2 = 0;
		memset(arr , 0 , sizeof(arr));
		memset(monitors , 0 , sizeof(monitors));
		memset(overspeed , 0 , sizeof(overspeed));
		memset(car , 0 , sizeof(car));
		while(!sta.empty()) sta.pop();
		
		n = read() , m = read() , l = read() , velocityLimit = read();
		for(int i = 1 ; i <= n ; ++i){
			car[i].enterLocation = read();
			car[i].v = read();
			car[i].a = read();
		}
		for(int i = 1 ; i <= m ; ++i){
			int location;
			location = read();
			arr[location] = true;
		}
		for(int i = 1 ; i <= l + 2 ; ++i) monitors[i] = monitors[i-1] + arr[i];
		for(int i = 1 ; i <= n ; ++i){
			int jiasudu = car[i].a;
			int velocity = car[i].v;
			int enterLocation = car[i].enterLocation;
			if(jiasudu == 0){
				if(velocity <= velocityLimit) continue;
				else{
					if(monitors[l+1] - monitors[enterLocation - 1] > 0){
						++ans1;
						++overspeed[enterLocation].ov;
						--overspeed[l+1].ov;
						overspeed[enterLocation].cars.pb(i);
						overspeed[l+1].cars.pb(-i);
						//p(velocity) , p(jiasudu) , p(enterLocation) , p(velocityLimit) , putchar('\n');
					}
				}
			}
			else if(jiasudu > 0){
				bool flag = false;
				int startPoint = enterLocation;
				if(velocity > velocityLimit){
					if(monitors[l+1] - monitors[enterLocation - 1] > 0)
						flag = true;
				}
				else if(velocity == velocityLimit){
					startPoint++;
					enterLocation = min(enterLocation , l+1);
					if(monitors[l+1] - monitors[enterLocation] > 0)
						flag = true;
				}
				else{
					int LimitPoint;//���� 
					double weiyi = 1.0 * (velocityLimit * velocityLimit - velocity * velocity) / (2 * jiasudu);
					LimitPoint = enterLocation + (int)weiyi + 1;
					startPoint = LimitPoint;
					LimitPoint = min(LimitPoint , l+1);
					//p1("v0" , velocity) , p1("vt" , velocityLimit) , p1("a" , jiasudu) , pd("x" , weiyi) , putchar('\n');	
					if(monitors[l+1] - monitors[LimitPoint - 1] > 0)
						flag = true;
				}
				if(flag){
					++ans1;
					++overspeed[startPoint].ov;
					--overspeed[l+1].ov;
					overspeed[startPoint].cars.pb(i);
					overspeed[l+1].cars.pb(-i);
					//p(velocity) , p(jiasudu) , p(enterLocation) , p(velocityLimit) , putchar('\n');				
				}
			}
			else{//匀减速
				if(velocity <= velocityLimit) continue;
				else{
					int exitLocation; // v = veloLimit
					double weiyi = 1.0 * (velocityLimit * velocityLimit - velocity * velocity) / (2 * jiasudu);
					//p1("v0" , velocity) , p1("vt" , velocityLimit) , p1("a" , jiasudu) , pd("x" , weiyi) , putchar('\n');	
					//if((int)weiyi - weiyi == 0.0) exitLocation = enterLocation + weiyi + 1;
					//else 
					exitLocation = enterLocation + weiyi;
					exitLocation = min(exitLocation , l+1);
					//p(exitLocation) , putchar('\n');
					if(monitors[exitLocation] - monitors[enterLocation - 1] > 0){
						++ans1;
						++overspeed[enterLocation].ov;
						--overspeed[exitLocation].ov;
						overspeed[enterLocation].cars.pb(i);
						overspeed[exitLocation].cars.pb(-i);
						//p(velocity) , p(jiasudu) , p(enterLocation) , p(velocityLimit) , putchar('\n');
					}
				}
				
			}
		}
		ans2 = m;
		for(int i = 1 ; i <= l+1 ; ++i){
			if(overspeed[i].ov != 0){
				for(int j = overspeed[i].cars.size() - 1 ; j >= 0 ; --j){
					int target = overspeed[i].cars[j];
				//	p(target);
					if(target > 0){
						sta.push(target);
						continue;
					}
					while(!aux.empty()) aux.pop();
					if(!sta.empty() && sta.top() == -target) ans2--; 
					while(!sta.empty() && sta.top() != -target){
						//p(sta.top());
						aux.push(sta.top());
						sta.pop();
						if(!sta.empty() && sta.top() == -target) ans2--; 
					}
					while(!sta.empty()) sta.pop();
					while(!aux.empty()){
						sta.push(aux.top());
						aux.pop();
					}
				}
				
				
			}
		}
		//putchar('\n');
		/*
		bool cur = sta.top();
		sta.pop();
		while(!sta.empty()){
			if(cur && !sta.top()) ans2-- , sta.pop();
			cur = sta.top() , sta.pop();
		}*/
		printf("%d %d\n" , ans1 , ans2);
	}

    return 0;
}
