import math
def solution(m):
  row_sum = [sum(i) for i in m]
  if sum(row_sum) == 0:
    return [0]
  size = len(m)
  temp = [[0,0]] * size

  # row = which state it is curently in
  # pre_prob = previous probability in current state
  # track = track previous states it has been to
  def helper(row, pre_prob, track):
    for col in range(size):
      num = m[row][col]
      den = row_sum[row]
      # check if the numerator is not 0
      if num != 0:
        cur_prob = [num * pre_prob[0], den * pre_prob[1]]
        # simplify the form
        com_div = gcd(cur_prob[0], cur_prob[1])
        cur_prob = [int(cur_prob[0] / com_div), int(cur_prob[1] / com_div)]
        # check if targeting row is a stable state
        if row_sum[col] == 0:
          # check if there is another probability to reach this state
          if temp[col] == [0,0]:
            temp[col] = cur_prob
          else:
            temp[col] = sum_fraction(temp[col], cur_prob)
        else:
          # check if it has been in the target state
          if col not in track:
            track.append(col)
            helper(col, cur_prob, track)
  
  helper(0, [1,1], [0])

  # remove the ones that will 
  # red_arr = [i for i in temp if i != [0,0]]

  # all_num = [i[0] for i in red_arr]
  # all_den = [i[1] for i in red_arr]
  
  # create a numerator array
  all_num = []
  idx = 1
  for i in range(1, len(row_sum) - 1):
    if row_sum[i] == 0:
      if temp[i][0] == 0:
        all_num.append(0)
      else:
        all_num.append(temp[i][0])
        idx = i
        break

  # normalize all the numerators
  while idx < (len(row_sum) - 1):
    if row_sum[idx] == 0:  # check if current state is stable
      prt = idx + 1
      den1 = temp[idx][1]
      den2 = temp[prt][1]
      while row_sum[prt] != 0 or den2 == 0:  # check if we have [..., 0, n, 0, ...] situation
        if den2 == 0:
          all_num.append(0)
        prt += 1
        if prt < len(row_sum):
          den2 = temp[prt][1]
        else:
          break

      if den1 != 0 and den2 != 0 and prt < len(row_sum) and row_sum[prt] == 0:
        lcd = lcm(den1, den2)
        num_mul = int(lcd / den1)
        all_num = [j * num_mul for j in all_num]
        all_num.append(temp[prt][0] * int(lcd / den2))
        temp[prt][1] = int(lcd)
          
    idx += 1  

  den = sum(all_num)  # the final denominator

  all_num.append(den)
  return all_num
    
# 
def gcd(a, b):
  if (a == 0):
    return b
  return gcd(b % a, a)

# least common denominator
def lcm(a, b):
  return (a * b) / gcd(a, b)
 
 
def sum_fraction(arr1, arr2):
  num1, den1 = arr1
  num2, den2 = arr2         

  lcd = lcm(den1, den2)
    
  num1 *= (lcd / den1)
  num2 *= (lcd / den2)

  res_num = num1 + num2
  return [int(res_num), int(lcd)]
  
#a = [[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
a = [[1, 1, 1, 1, 1,],  [0, 0, 0, 0, 0,], [1, 1, 1, 1, 1,], [0, 0, 0, 0, 0,], [1, 1, 1, 1, 1,] ]
print(solution(a))