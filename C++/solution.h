#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
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
      start = i - (int)(std::floor((len - 1) / 2));
      end = i + (int)(std::floor(len / 2));
    };
  };
  return str.substr(start, end + 1);
};


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


/* 
#200 -- Number of Islands 

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/


#include <queue>

bool Q200_check_range(int i, int j, int height, int width) {
  if (i > 0 && i < height && j > 0 && j < width) {
    return true;
  };
  return false;
};

void Q200_bfs(std::vector<std::vector<char>>& grid, 
              std::vector<std::vector<bool>>& visited, 
              int i, int j) {
  std::vector<int> X = {-1, 1, 0, 0};
  std::vector<int> Y = {0, 0, -1, 1};

  std::queue<std::pair<int, int>> queue;
  queue.push({i, j});
  visited[i][j] = true;
  while(!queue.empty()) {
    std::pair<int, int> item = queue.front();
    queue.pop();
    for (int k = 0; k < 4; k ++) {
      int new_x = item.first + Y[i];
      int new_y = item.second + X[i];
      if (Q200_check_range(new_y, new_x, grid.size(), grid[0].size())) {
        queue.push({new_y, new_x});
        visited[new_y][new_x] = true;
      };
    };
  };
};

void Q200_dfs(std::vector<std::vector<char>>& grid, 
              std::vector<std::vector<bool>>& visited, 
              int i, int j) {
  std::vector<int> X = {-1, 1, 0, 0};
  std::vector<int> Y = {0, 0, -1, 1};
  if (Q200_check_range(i, j, grid.size(), grid[0].size())) {
    visited[i][j] = true;
    for (int k = 0; k < 4; k ++) {
      int new_y = i + Y[i];
      int new_x = j + X[i];
      Q200_dfs(grid, visited, new_y, new_x);
    };
  };
};

int Q200(std::vector<std::vector<char>>& grid, std::string type) {
  int u = grid.size();
  int v = grid[0].size();
  std::vector<std::vector<bool>> visited(u, std::vector<bool>(v, false));
  int count = 0;
  for (int i = 0; i < u; i ++) {
    for (int j = 0; j < v; i ++) {
      if (grid[i][j] == '1' && !visited[i][j]) {
        count ++;
        if (type == "BFS") { Q200_bfs(grid, visited, i, j); }
        else if (type == "DFS") { Q200_dfs(grid, visited, i, j); }
        else { throw std::invalid_argument("This type is not implemented"); };
      };
    };
  };
  return count;
};



// int q200_bfs(std::vector<std::vector<char>>& grid, int i, int j) {
//   if (0 <= i <= grid.size() && 0 <= j <= grid[0].size() && grid[i][j] == "1" ) {
//     grid[i][j] = "0";
//     std::vector<std::vector<int>> combs = {{i + 1, j}, {i - 1, j}, {i, j - 1}, {i, j + 1}};
//     for (auto comb : combs) {
//       bfs(comb[0], comb[1]);
//     };
//     return 1;
//   };
//   return 0;
// };


// int q200(std::vector<std::vector<char>>& grid) {
//   if (grid.size() == 0) { return 0; };
  
//   int count = 0;
//   for (int u = 0; u < grid.size(); u++) {
//     for (int v = 0; v < grid[0].size(); v++) {
//       int result = q200_bfs(std::vector<std::vector<char>>& grid, u, v);
//       count += result;
//     };
//   };
//   return count;
// };


/*
#207 -- Course Schedule

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
*/

bool Q207_dfs(std::vector<std::vector<int>>& graph, std::vector<int>& visit, int idx) {
  if (visit[idx] == -1) { return false; };
  if (visit[idx] ==  1) { return true; };
  visit[idx] = -1;

  for (int item : graph[idx]) {
    bool result = Q207_dfs(graph, visit, item);
    if (result != false) { return false; };
  };
  visit[idx] = 1;
  return true;
};

bool Q207(int num_courses, std::vector<std::vector<int>> prereq) {
  std::vector<std::vector<int>> graph;
  graph.reserve(num_courses);
  std::vector<int> visit(num_courses, 0);

  for (std::vector<int> item : prereq) {
    int b = item[0];
    int a = item[1];
    graph[b].push_back(a);
  };

  for (int i = 0; i < num_courses; i ++) {
    bool result = Q207_dfs(graph, visit, i);
    if (result != false) {
      return false;
    };
  };

  return true;
};


/*
Q213 -- Rob House

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob 
house 3 (money = 2), because they are adjacent houses.
*/

int Q213_solver(std::vector<int>& vecs) {
  int pnt1 = vecs[0];
  int pnt2 = std::max(vecs[0], vecs[1]);
  for (int i = 2; i < vecs.size(); i ++) {
    int cur = std::max(pnt2, pnt1 + vecs[i]);
    pnt1 = pnt2;
    pnt2 = cur;
  };
  return pnt2;
};

int Q213(std::vector<int>& nums) {
  int len = nums.size();
  if (len == 0) { return 0; };
  if (len == 1) { return nums[0]; };
  if (len == 2) { return std::max(nums[0], nums[1]); };
  std::vector<int> v1, v2;
  for (int i = 0; i < len; i ++) {
    if (i != 0) { v1.push_back(nums[i]); };
    if (i != len - 1) { v2.push_back(nums[i]); };
  };
  
  int result = std::max(Q213_solver(v1), Q213_solver(v2));

  return result;
};
