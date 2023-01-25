#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
//#include "my_algorithm.h"


/*
#3 -- Longest Substring Without Repeating Characters

Input: s = "abcabcbb"
Output: 3
*/
int q3(std::string str)
{
  std::map<char, int> dict;
  int dict_len = 0;
  int count = 0;

  for (auto cha : str)
  {
    dict_len ++;
    dict[cha] ++;

    if (dict[cha] > 1)
    {
      count = std::max(count, dict_len - 1);
      dict.clear();
      dict[cha] = 1;
      dict_len = 1;
    }
  }
  return count;
}


/*
#5 -- Longest Palindromic Substring

Input: s = "babad"
Output: "bab"
*/
std::string q5(std::string str)
{
  if (str.length() < 2 ) return "";
  int start = 0;
  int end = 0;
  for (int i = 0; i < str.length(); i++)
  {
    int len1 = q5_helper(str, i, i);
    int len2 = q5_helper(str, i, i + 1);
    int len = std::max(len1, len2);
    if (len > (end - start + 1))
    {
      start = i - std::static_cast<int>(std::floor((len - 1) / 2));
      end = i + std::static_cast<int>(std::floor(len / 2));
    }
  }
  return str.substr(start, end + 1);
}

int q5_helper(std::string str, int left, int right)
{
  int l = left;
  int r = right;
  while(l >= 0 && r < str.length() && str[l] == str[r])
  {
    l --;
    r ++;
  };
  return r - l - 1;
}

/*
#6 -- ZigZag Conversion

P   A   H   N
A P L S I I G      ====>     "PAHNAPLSIIGYIR"
Y   I   R
*/
std::string q6(std::string str, int num_row)
{
  
  return str;
}



/* #15 3Sum */
std::vector<std::vector<int>> q15(int target, std::vector<int>& nums) {
  std::vector<std::vector<int>> results;

  if (nums.size() < 3) { return results; };
  std::sort(nums.begin() , nums.end());

  for (int i = 0; i < nums.size(); i ++) {
    if (i > 0 && nums[i - 1] == nums[i]) {
      continue;
    };

    int mid = i + 1;
    int right = nums.size() - 1;
    while (mid < right) {
      int sum = nums[i] + nums[mid] + nums[right];
      if (sum < target) { mid ++; }
      else if (sum > target) { right --; }
      else {
        results.push_back({nums[i], nums[mid], nums[right]});
        while (mid < right && nums[mid] == nums[mid + 1]) { mid ++; };
        while (mid < right && nums[right] == nums[right - 1]) { right --; };
        mid ++;
        right --;
      };
    };
  };
  return results; 
}

// vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin() , nums.end());     //Sorted Array
//         if(nums.size() < 3){                // Base Case 1
//             return {};
//         }
//         if(nums[0] > 0){                    // Base Case 2
//             return {};
//         }
//         unordered_map<int , int> hashMap;
//         for(int i = 0 ; i < nums.size() ; ++i){     //Hashing of Indices
//             hashMap[nums[i]] = i;
//         }
//         vector<vector<int>> answer;
//         for(int i = 0 ; i < nums.size() - 2 ; ++i){     //Traversing the array to fix the number.
//             if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
//                 break;
//             }
//             for(int j = i + 1 ; j < nums.size() - 1 ; ++j){     //Fixing another number after first number
//                 int required = -1*(nums[i] + nums[j]);    //To make sum 0, we would require the -ve sum of both fixed numbers.
//                 if(hashMap.count(required) && hashMap.find(required)->second > j){ //If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet.
//                     answer.push_back({nums[i] , nums[j] , required});
//                 }
//                 j = hashMap.find(nums[j])->second; //Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
//             }
//             i = hashMap.find(nums[i])->second;     //Update i to last occurence of 1st fixed number to avoid duplicate triplets.
//         }
//         return answer;  //Return answer vector.
//     }


/* #200 -- Number of Islands */

int q200_bfs(std::vector<std::vector<char>>& grid, int i, int j) {
  if (0 <= i <= grid.size() && 0 <= j <= grid[0].size() && grid[i][j] == "1" ) {
    grid[i][j] = "0";
    std::vector<std::vector<int>> combs = {{i + 1, j}, {i - 1, j}, {i, j - 1}, {i, j + 1}};
    for (auto comb : combs) {
      bfs(comb[0], comb[1]);
    };
    return 1;
  };
  return 0;
};


int q200(std::vector<std::vector<char>>& grid) {
  if (grid.size() == 0) { return 0; };
  
  int count = 0;
  for (int u = 0; u < grid.size(); u++) {
    for (int v = 0; v < grid[0].size(); v++) {
      int result = q200_bfs(std::vector<std::vector<char>>& grid, u, v);
      count += result;
    };
  };
  return count;
};







