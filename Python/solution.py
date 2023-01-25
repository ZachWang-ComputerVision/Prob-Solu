"""
This file is my solutions in Python to some of the Medium and Hard level questions from LEECODE

"""

import my_data_structure as ds
import math

# for type declaration practice
from typing import TypeVar, Generic, Callable, NewType, List, Dict
T = TypeVar('T')
U = TypeVar('U')
V = TypeVar('V')

"""
Although Python is a dynamic typing language, the type declaration is an important feature
when developing a large Python project, because errors will be caught in the compile time.
Next four functions are for practicing Python in a functional programming style with static typing.
"""

def f1():
  func: Callable[[T, T], T] = lambda x, y: x + y
  return func

def f2(x: T, y: Callable[[T], U] = lambda f: f(x)):
  return y(x)

#a = f2(5, lambda y: y + 1)
#print(a)

def f3(x: T):
  func: Callable[[T], U] = lambda y: y(x)
  return func

#a = f3(10)
#b = a(lambda z: z + 1)
#print(b)

def f4(arg1: T, arg2: U, arg3: Callable[[T, U], V] = lambda z: z(x, y)):
  return arg3(arg1, arg2)


""" ---------------------------------------------------------
LEECODE Practice Start
--------------------------------------------------------- """

""" 
#2 -- Add Two Numbers


"""
link1 = ds.LinkedList(2)
link1.add(3)
link1.add(4)

link2 = ds.LinkedList(5)
link2.add(6)
link2.add(7)

def q2(link_a, link_b):
  a = 0
  b = 0
  curr1 = link_a.head
  curr2 = link_b.head

  multi1 = 1
  while curr1 != None:
    a += curr1.value * multi1
    curr1 = curr1.next
    multi1 = multi1 * 10

  multi2 = 1
  while curr2 != None:
    a += curr2.value * multi2
    curr2 = curr2.next
    multi2 = multi2 * 10

  return a + b

#print(q2(link1, link2))


""" 
#3 -- Longest Substring Without Repeating Characters
Input: s = "abcabcbb"
Output: 3

The core idea is to check if a char has been counted in the dictionary. Then, count the
length of the dictionary
"""
def q3(string: str) -> int:
  dic = {}
  dic_len = 0
  count = 0
  for i in range(len(string)):
    dic_len += 1
    if s in arr:
      count = max(count, len(arr))
      if pre_index == len(arr): arr = []
      else: arr = arr[index + 1 : -1]
    arr.append(s)
  return max(count, len(arr))
    
#print(q3("wfgtrthd"))


""" 
#5 -- Longest Substring Without Repeating Characters

Input: s = "babad"
Output: "bab"

The idea is to check "--aba--" or "--abba--". Then, compare the length.
"""
def q5(string: str) -> str:
  if len(string) < 2:
    return ""
  start = 0
  end = 0
  for i in range(0, len(string)):
    len1 = q5_helper(string, i, i)
    len2 = q5_helper(string, i, i + 1)
    length = max(len1, len2)
    if length > (end - start + 1):
      start = i - math.floor((length - 1) / 2)
      end = i + math.floor(length / 2)
  return string[start : end + 1]

def q5_helper(string, left, right):
  l = left
  r = right 
  while l >= 0 and r < len(string) and string[l] == string[r]:
    l -= 1
    r += 1 
  return r - l - 1

""" 
#6 -- ZigZag Conversion


"""
def q6(string: str, n_row: int) -> str:
  arr = ["" for n in range(n_row)]
  order = True
  index = 0
  for i in string:
    arr[index] = arr[index] + i
    if order:
      index += 1
    else:
      index -= 1    
    if index > n_row - 1:
      order = False
      index -= 2
    elif index < 0: 
      order = True
      index += 2
  new_str = ""
  for word in arr:
    new_str = new_str + word
  return new_str

#print(q6("PAYPALISHIRING", 3))


""" #11 -- Container With Most Water """
def q11 (arr: List[int]) -> int:
  if len(arr) < 2: return 0
  s = 0
  e = len(arr) - 1
  area = 0
  while s < e:
    area = max(area, (e - s) * min(arr[s], arr[e]))
    if arr[s] <= arr[e]: s += 1
    else: e -= 1
  return area

#print(q11([5,3,7,2]))


""" #15 -- 3Sum """
def q15 (target: int, nums: List[int]) -> List[List[int]]:
  if len(nums) < 3: return None
  nums.sort()
  results = []
  for i in range(len(nums)):
    if i > 0 and nums[i - 1] == nums[i]:
      continue
    mid = i + 1
    right = len(nums) - 1

    while mid < right:
      sums = nums[i] + nums[mid] + nums[right]
      if sums < target:
        mid += 1
      elif sums > target:
        right -= 1
      else:
        results.append([nums[i], nums[mid], nums[right]])
        while mid < right and nums[mid] == nums[mid + 1]:
          mid += 1
        while mid < right and nums[right] == nums[right - 1]:
          right -= 1
        mid += 1
        right -= 1
  return results


""" 
#22 -- Generate Parentheses

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
"""
def q22 (n: int) -> List[str]:
  stack = []

  def recursion (left=0, right=0, buff=[]):
    if len(buff) == 2 * n:
      stack.append("".join(buff))
      return
    if left < n:
      buff.append("(")
      recursion (left + 1, right, buff)
      buff.pop()
    if right < left:
      buff.append(")")
      recursion(left, right + 1, buff)
      buff.pop()
  
  recursion()
  return stack

#print(q22(3))


""" 
#39 -- Combination Sum

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
"""
def q39(nums: List[int], target: int) -> List[List[int]]:
  arr = []
  if target < 0 or len(nums) == 0: return arr
  sort_nums = sorted(nums)

  def recursion(summ, path, list_nums):
    for i in range(len(list_nums)):
      new_sum = list_nums[i] + summ
      new_path = path + [list_nums[i]]
      if new_sum == target:
        arr.append(new_path)
        return
      if new_sum > target:
        return
      recursion(new_sum, new_path, list_nums[i:])
  
  recursion(0, [], sort_nums)
  return arr

#print(q39([2,3,5], 8))


""" 
#46 -- Permutation

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
"""
def q46 (nums: List[int]) -> List[List[int]]:
  arr = []

  def recursion (collection, new_nums):
    inner_arr = []

    for i in range(len(new_nums)):
      inner_arr.append([nums[i]])

    for j in inner_arr:
      pass


  return arr


""" 
#54 -- Spiral Matrix

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
"""
def q54 (nums: List[List[int]]) -> List[int] :
  arr = []

  def recursion (new_nums, left_to_right):
    if left_to_right:
      arr + new_nums[0]
      for i in range(1, len(new_nums)):
        arr.append(new_nums[i][-1])
      matrix = new_nums[1 : ][ : -1]
      return matrix
    else:
      arr + list(reversed(new_nums[-1]))
      for i in range(len(new_nums) - 2, -1):
        arr.append(new_nums[i][0])
      matrix = new_nums[ : -1][ 1 : ]
      return matrix

  new_matrix = nums
  left_to_right = True
  for i in range(len(nums)):
    print(new_matrix)
    new_matrix = recursion(new_matrix, left_to_right)
    print(left_to_right)
    left_to_right = not left_to_right

  return arr

#print(q54([[1,2,3],[4,5,6],[7,8,9]]))

""" 
#56 -- Merge Intervals

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
"""
def q56 (intervals: List[List[int]]) -> List[List[int]]:
  arr = []
  index = 0
  for interval in intervals:
    if len(arr) == 0:
      arr.append(interval[0])
      arr.append(interval[1])
    else:
      start = interval[0]
      while start <= arr[index]:
        if index > 0:
          index -= 1
        else:
          break
      arr = arr[ : index + 1]

      end = interval[1]
      if (index + 1) % 2 != 0:
        arr.append(end)
        index += 1
      else:
        arr.append(start)
        arr.append(end)
        index += 2
  result = []
  for i in range(0, len(arr), 2):
    result.append([arr[i], arr[i + 1]])
  return result

#print(q56([[1,3],[2,6],[8,10],[15,18]]))


"""
#64 -- Minimum Path Sum
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7

"""
def q64(grid: List[List[int]]) -> int:
  m = len(grid) - 1
  n = len(grid[0]) - 1
  store = [[0 for i in range(m)] for j in range(n)]
  
  def recurs(i, j):
    if store[i][j] > 0:
      return store[i][j]
    count = 0
    if i > 0 and j > 0:
      left = recurs(i, j - 1)
      up = recurs(i - 1, j)
      count = grid[i][j] + min(left, up)
    elif i == 0:
      count = grid[i][j] + recurs(i, j - 1)
    elif j == 0:
      count = grid[i][j] + recurs(i - 1, j)
    else:
      count = grid[i][j]
    store[i][j] = count
    return count

  return recurs(m, n)

def q64_topdown():
  return

"""
#75 -- Sort Colors / Dutch Flag
Input: colors = [1, 0, 0, 2, 1]
Output: colors = [0, 0, 1, 1, 2]

"""
def q75(nums: List[int]) -> List[int]:
  arr = nums
  low = 0
  mid = 0
  high = len(arr) - 1
  
  while(mid <= high):
    if(arr[mid] == 0):
      arr[low], arr[mid] = arr[mid], arr[low]
      low += 1
      mid += 1
    elif(arr[mid] == 1):
      mid += 1
    else:
      arr[mid], arr[high] = arr[high], arr[mid]
      high -= 1
  return arr


"""
#79 -- Word Search
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

"""
def q79 (board: List[List[str]], word: str) -> bool:
  
  for i in range (0, len(board)):
    for j in range (0, len(board[0])):
      if q79_helper(board, i, j, word, 0):
        return True 
  return False

def q79_helper(board, i, j, word, letter_idx):
  
  if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] != word[letter_idx]:
    return False
  
  board[i][j] = "*"
  idx = letter_idx + 1
  if idx == len(word):
    return True
  
  a = q79_helper(board, i - 1, j, word, idx)
  b = q79_helper(board, i + 1, j, word, idx)
  c = q79_helper(board, i, j - 1, word, idx)
  d = q79_helper(board, i, j + 1, word, idx)
  
  return (a or b or c or d)


"""
#96 -- Unique Binary Search Trees / Catalan Number
Input: n = 3
Output: 5

"""
# (2n C n) / (n + 1)
def q96(n: int) -> int:
  a = 2 * n
  count = 1
  
  for i in range(0, n):
    count *= (a - i)
    count /= (i + 1)
    
  return int(count / (n + 1))

# DP Tabulation
def q96_Tab(n: int) -> int:
  arr = [0] * (n)
  arr[0], arr[1] = 1, 1
  
  for i in range(2, n + 1):
    for j in range(0, i):
      arr[i] += arr[j] * arr[i - j - 1]
  return arr[n]
  
# DP Memoization
def q96_Mem(n: int) -> int:
  arr = [-1] * (n + 1)
  
  def recurs(n):
    if n <= 1: return 1
    if arr[n] != -1: return arr[n]
    count = 0
    for i in range(0, n):
      count += (recurs(i) * recurs(n - i - 1))
    arr[n] = count
    return count
  return recurs(n)


"""
#98 & #105
"""

def build_tree(arr: List[int]) -> bool:
  length = len(arr)
  def recurs(i):
    node = ds.TreeNode(arr[i])
    left_idx = 2 * i + 1
    right_idx = 2 * i + 2
    if left_idx < length:
      node.left = recurs(left_idx)
    if right_idx < length:
      node.right = recurs(right_idx)      
    return node
  tree = recurs(0)
  return tree


"""
#139 -- Word Break

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
"""
def q139(string, words):
  s_length = len(string)
  dic = [False for i in range(s_length + 1)]
  dic[s_length] = True
  for i in range(s_length - 1, -1, -1):
    s = string[i:]
    for w in words:
      if len(s) >= len(w):
        if w == s[0:len(w)] and dic[i + len(w)]:
          dic[i] = True
  return dic[0]


"""
#200 -- Number of Islands

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
"""
def q200(grid):
  if len(grid) == 0:
    return 0
  def bfs(i, j):
    if 0 <= i < len(grid) and 0 <= j < len(grid[i]) and grid[i][j] == '1':
      grid[i][j] = '0'
      map(bfs, (i+1, i-1, i, i), (j, j, j+1, j-1))
      return 1
    return 0
  return sum(bfs(i, j) for i in range(len(grid)) for j in range(len(grid[i])))


""" 
#207 -- Course Schedule

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
"""
def q207(numCourses, prerequisites):
  graph = [[] for _ in range(numCourses)]
  visit = [0 for _ in range(numCourses)]
  
  for c_set in prerequisites:
    b, a = c_set
    graph[b].append(a)
  
  for i in range(numCourses):
    if not dfs(graph, visit, i):
      return False
  
  def dfs(graph, visit, idx):
    if visit[idx] == -1:
      return False
    if visit[idx] == 1:
      return True
    visit[idx] = -1
    
    for edge in graph[idx]:
      if not dfs(graph, visit, edge):
        return False
    visit[idx] = 1
    return True

  return True


"""
#221 -- Maximal Square

Input: matrix = [["1","0","1","0","0"],
                 ["1","0","1","1","1"],
                 ["1","1","1","1","1"],
                 ["1","0","0","1","0"]]
Output: 4
"""
def q221(matrix):
  return