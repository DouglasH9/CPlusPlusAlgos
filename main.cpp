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
//bird counter hacker rank

int migratory_birds(const vector<int> &arr) {
    vector<int> count_arr(6, 0);
    int bird_id{0};

    for(const auto &id: arr) {
        count_arr[id]++;
        if(count_arr[id] > count_arr[bird_id]) {
            bird_id = id;
        }
        else if(count_arr[id] == count_arr[bird_id]) {
            bird_id = (id > bird_id) ? bird_id : id;
        }
    }
    return bird_id;
}

//running sum leetcode.
vector<int> running_sum(const vector<int> &nums) {
    vector<int> sum_vec{nums[0]};
    for (int i = 1; i < nums.size(); ++i)
        sum_vec.push_back(sum_vec.back() + nums[i]);
    return sum_vec;
}

/*Find pivot index LeetCode. Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of
 all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This
 also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.*/
int pivot_index(const vector<int> &nums) {
    int left_sum{0}, sum{0};
    for(int i : nums) { sum += i;}
    for(int j = 0; j < nums.size(); ++j) {
        if(left_sum == sum - nums[j] - left_sum) {
            return j;
        }
        left_sum += nums[j];
    }
    return -1;
}

int main() {

    vector<int> vec {10, 20, 20, 10, 10, 30, 50, 10, 20};
    cout << pivot_index({1, 2, 3}) << endl;


    return 0;
}
