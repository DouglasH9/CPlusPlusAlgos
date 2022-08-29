#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <climits>

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
//____________________________________________________________
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
//___________________________________________________________________________
/* Isomorphic strings Leetcode.
 * Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.*/

bool is_isomorphic(const string &s, const string &t) {
    unordered_map<char, char> map_st{};
    unordered_map<char, char> map_ts{};

    if(s.size() != t.size()) {return false;}

    for(int i = 0; i < s.size(); i++) {
        map_st[s[i]] = t[i];
        map_ts[t[i]] = s[i];
    }

    if(map_ts.size() != map_st.size()) {return false;}

    for(int j = 0; j < s.size(); j++) {
        if(map_st[s[j]] != t[j]) {
            return false;
        }
    }
    return true;
}
//____________________________________________________________________________________________________
/*Is subsequence algo Leetcode...
 *Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some
 (can be none) of the characters without disturbing the relative positions of the remaining characters.
 (i.e., "ace" is a subsequence of "abcde" while "aec" is not). */

bool is_subsequence(const string &s, const string &t) {
    //counter for matches
    int match_count {0};
//    initialize pointers
    int left_p {0}, right_p{0};

    while(left_p < s.length() && right_p < t.length()) {
        if(s[left_p] == t[right_p]) {
            match_count += 1;
            left_p += 1;
        }
        right_p += 1;
    }
    return match_count == s.length();
}
//___________________________________________________________________________
/*Merge two sorted linked lists Leetcode
 * You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.*/
//Node and list definition...
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val{0}, next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//recursive solution...
ListNode* merge_two_lists_recursive(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr) {return list2;}
    if(list2 == nullptr) {return list1;}

    if (list1->val <= list2->val) {
        list1 -> next = merge_two_lists_recursive(list1 -> next, list2);
        return list1;
    }
    else {
        list2 -> next = merge_two_lists_recursive(list1, list2 -> next);
        return list2;
    }
}
//merge two lists iterative...
ListNode* merge_two_lists_iterative(ListNode* list1, ListNode* list2) {
    auto* head = new ListNode(-1);
    auto* tail = head;

    while(list1 != nullptr && list2 != nullptr) {
        //compare heads of both lists
        if(list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1 == nullptr ? list2 : list1;

    head = head->next;
    return head;
}
//___________________________________________________________________
/*Reversing a linked list Leetcode
 * Given the head of a singly linked list, reverse the list, and return the reversed list.*/

ListNode* reverse_list(ListNode* head) {
    ListNode* prev_node = nullptr;
    ListNode* curr_node = head;

    while(curr_node != nullptr) {
        ListNode* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    return prev_node;
}
//_______________________________________________________________________

/*Middle of linked list Leetcode
 * Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.*/

ListNode* find_middle_node(ListNode* head) {
    int length{1};
    ListNode* return_node = head;
    while(head->next != nullptr) {
        head = head->next;
        length += 1;
    }
    for(int i = 0; i < length/2; i++) {
        return_node = return_node->next;
    }
    return return_node;
}

//________________________________________________________________
/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.*/

ListNode* detect_cycle(ListNode* head) {
    unordered_map<ListNode*, int> visited;

    ListNode *node = head;

    while(node != nullptr) {
        if(visited[node] > 1) {
            return node;
        }
        visited[node] += 1;
        node = node->next;
    }
    return nullptr;
}
//________________________________________________________________
/*Best time to buy and sell stock Leetcode
 *
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example:
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.*/

//Brute force solution, nested loops...
int max_profit(const vector<int> &prices) {
    int largest_dif{0};
    for(int i = 0; i < prices.size(); i++)
        for(int j = i + 1; j < prices.size(); j++) {
            if(prices[j] - prices[i] > largest_dif)
                largest_dif = prices[j] - prices[i];
        }
    return largest_dif;
}
//One pass through...
int max_profit_fast(const vector<int> &prices) {
    int largest_profit{0};
    int lowest_price{INT_MAX};
    for(int i = 0; i < prices.size(); i++) {
        if(prices[i] < lowest_price)
            lowest_price = prices[i];
        else if(prices[i] - lowest_price > largest_profit) {
            largest_profit = prices[i] - lowest_price;
        }
    }
    return largest_profit;
}

//_________________________________________________________________
/*Longest palindrome Leetcode.
 * Given a string s which consists of lowercase or uppercase letters,
 * return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 Example 1:

    Input: s = "abccccdd"
    Output: 7
    Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.*/

int longest_palindrome(const string &str) {
    unordered_map<char, int> char_count{};
    int pal_count{0};

    for(char c: str)
        char_count[c] += 1;

    for(pair<char, int> letter: char_count)
        if(letter.second % 2 == 0)
            pal_count += letter.second;
        else if (letter.second % 2 == 1)
            pal_count += letter.second / 2 * 2;

    if(pal_count < str.length())
        pal_count += 1;

    return pal_count;
}

/*BINARY SEARCH non leetcode with recursion...
 .*/

int bin_search(const vector<int> &nums, int target, int left_idx, int right_idx) {
    int middle = (left_idx + right_idx) / 2;

    if(left_idx > right_idx)
        return -1;
    else {
        if (nums[middle] == target)
            return middle;
        else if(target < middle)
            return bin_search(nums, target, left_idx, middle -1);
        else if(target > middle)
            return bin_search(nums, target, middle + 1, right_idx);
        else
            return -1;
    }
}
/*BINARY SEARCH leetcode
 ** Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
 * If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity*/

int leet_bin_search(const vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int middle = (left + right) / 2;


    while(right >= left) {
        middle = left + (right - left) / 2;
        if(target == nums[middle])
            return middle;
        else if(target < nums[middle])
            right = middle - 1;
        else if(target > nums[middle])
            left = middle + 1;
    }
    return -1;
}


int main() {
    vector<int> num_vec = { -1, 0, 3, 5, 9, 12 };

    cout << leet_bin_search(num_vec , 99) << endl;

    return 0;
}
