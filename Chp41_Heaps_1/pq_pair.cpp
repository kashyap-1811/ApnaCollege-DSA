#include <bits/stdc++.h>

using namespace std;

struct ComparePair{
    bool operator () (const pair<string,int>&p1, const pair<string,int>&p2) {
        return p1.second < p2.second;
    }
};

int main()
{
    priority_queue<pair<string,int>, vector<pair<string,int>>, ComparePair>pq; //max heap on second

    pq.push(make_pair("kashyap", 95));
    pq.push(make_pair("Henil", 90));
    pq.push(make_pair("Jasmita", 85));
    pq.push(make_pair("Diya", 80));
    pq.push(make_pair("Shrujal", 75));

    while(pq.size() > 0){
        cout<<pq.top().first <<" , "<< pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}