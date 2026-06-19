#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
    template <typename T> class Stack
    {
    private:
        vector<T> a;
    public:
        typedef T value_type;
        typedef typename vector<T>::size_type size_type;
        size_t push(char c)
        {
            a.push_back(c);
            return a.size();
        }
        int pop()
        {
            a.pop_back();
            return a.size();
        }
        char& operator[](int pos)
        {
            return a.at(a.size()-pos);
        }
        char& top()
        {
            return a.back();
        }
        size_t size()
        {
            return a.size();
        }
        bool empty()
        {
            return a.empty();
        }
    };
}