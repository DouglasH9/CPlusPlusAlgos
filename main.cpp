#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//xor string hacker rank
string strings_xor(string s, string t) {
    string res{};

    for (size_t i = 0; i < s.size(); ++i) {
        if(s[i] == t[i])
            res += '0';
        else
            res += '1';
    }
    return res;
}
//___________________________________________________________________


//sock merchant algo, hacker rank
int sock_merchant(int n, const vector<int> &arr) {
    int count {0};
    unordered_map<int, int> num_map{};
    for(int i = 0; i < n; ++i) {
        num_map[arr[i]] += 1;
    }
    for(auto socks_and_counts : num_map) {
        count += socks_and_counts.second/2;
    }
    return count;
}
//_________________________________________________


int main() {

    vector<int> vec {10, 20, 20, 10, 10, 30, 50, 10, 20};
    cout << sock_merchant(9, vec) << endl;

    return 0;
}
