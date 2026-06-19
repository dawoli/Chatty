#ifndef OI_TEMPLATES_CHT_HPP
#define OI_TEMPLATES_CHT_HPP
#include <deque>

// 单调斜率优化（Convex Hull Trick）模板
struct Line { long long m,b; Line(long long _m=0,long long _b=0):m(_m),b(_b) {} long double interX(const Line &o) const { return (long double)(o.b-b)/(m-o.m); } long long eval(long long x) const { return m*x+b; } };
struct CHT { std::deque<Line> dq; void add(long long m,long long b) { Line ln(m,b); while(dq.size()>=2) { auto &l1=dq[dq.size()-2],&l2=dq[dq.size()-1]; long double x1=l1.interX(l2); long double x2=l2.interX(ln); if(x2<=x1) dq.pop_back(); else break; } dq.push_back(ln); } long long query(long long x) { while(dq.size()>=2&&dq[0].eval(x)<=dq[1].eval(x)) dq.pop_front(); return dq.front().eval(x); } };

#endif // OI_TEMPLATES_CHT_HPP
