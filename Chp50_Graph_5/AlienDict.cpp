#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

string findOrder(vector<string>& dict, int N) {
    unordered_map<char, set<char>> adj;
    unordered_map<char, int> indegree;

    // Initialize characters
    for (auto& word : dict) {
        for (char c : word) {
            indegree[c] = 0;
        }
    }

    // Build graph
    for (int i = 0; i < N - 1; i++) {
        string w1 = dict[i], w2 = dict[i + 1];
        int len = min(w1.size(), w2.size());
        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                if (adj[w1[j]].count(w2[j]) == 0) {
                    adj[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                break;
            }
        }
    }

    // Topological sort using Kahn's algorithm
    queue<char> q;
    for (auto& [ch, deg] : indegree) {
        if (deg == 0)
            q.push(ch);
    }

    string order;
    while (!q.empty()) {
        char curr = q.front();
        q.pop();
        order += curr;
        for (char neigh : adj[curr]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0)
                q.push(neigh);
        }
    }

    // Check for cycle (invalid order)
    if (order.size() != indegree.size())
        return "";

    return order;
}

int main()
{
    vector<string>dict = {
            "wrt", "wrf", "er", "ett", "rftt", "te", "tg", "tgg", "tgh", "tgi", "tgj",
            "aa", "ab", "ac", "ad", "ae", "af", "ag", "ah", "ai", "aj", "ak", "al", "am",
            "an", "ao", "ap", "aq", "ar", "as", "at", "au", "av", "aw", "ax", "ay", "az",
            "ba", "bb", "bc", "bd", "be", "bf", "bg", "bh", "bi", "bj", "bz"
    };

    string ans = findOrder(dict, dict.size());

    cout << ans << " " << ans.size() << endl;
    return 0;
}