/*
 ██████╗ █████╗ ██████╗ ██████╗ ██╗   ██╗
██╔════╝██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝
██║     ███████║██████╔╝██████╔╝ ╚████╔╝ 
██║     ██╔══██║██╔══██╗██╔══██╗  ╚██╔╝  
╚██████╗██║  ██║██║  ██║██║  ██║   ██║   
 ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   
*/

#include<stack>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#include<deque>
#include<vector>
#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<iomanip>
#include<bitset>
using namespace std;
//--------------------------------------
struct MSET{
    multiset<int>mset;
    void add(int k) {
        mset.insert(k);
    }
    int getmin() {
        return *mset.begin();
    }
    int getmax() {
        return *prev(mset.end());
    }
    int lower(int k) {//小于等于k的最大的数
        if (mset.size() == 0)return -1;
        if (k < getmin())return -1;
        if (mset.count(k))return k;
        auto it = mset.lower_bound(k);
        return *prev(it);
    }
    int uper(int k) {//大于等于k的最大的数
        if (mset.size() == 0)return -1;
        auto it = mset.lower_bound(k);
        if (it == mset.end())return -1;
        return *it;
    }
    void erase(int k) {
        mset.erase(mset.find(k));
    }
    void clear() {
        mset.clear();
    }
    int size() const {
        return mset.size();
    }
}st;