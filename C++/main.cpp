/*
C++ Compile
  g++ sourcefile_name.cpp -o outputfile.exe header1.cpp header2.cpp
  ./outputfile

  g++ main.cpp -o main.exe solution/solution.cpp solution/my_data_structure.cpp
*/

#include <iostream>
#include <string>
// #include "solution/solution.h"
// #include "solution/MyDataStructure.h"
#include <vector>







int main()
{
  int t = 0;
  std::vector<int> nums = {-1,0,1,2,-1,-4};
  
  std::vector<std::vector<int>> a = q15(t, nums);
  // std::cout << a << std::endl;
  // for (auto num : nums) {
  //   for auto
  // }
  // std::cout << q15(t, nums) << std::endl;
  return 0;
};



// ----------------------------------------------------------------
// LinkedList<int> a;
// std::cout << a.get_size() << std::endl;
// a.add_node(5);
// a.add_node(6);
// a.add_node(7);
// a.add_node(8);
// a.add_node(9);
// std::cout << a.get_size() << std::endl;
// a.print_head();


// ----------------------------------------------------------------
// std::string str = "efggthth";
// int e = q3(str);
// std::cout << e << std::endl;


// ----------------------------------------------------------------
// std::vector<std::vector<char>> grid {
//   {"1","1","0","0","0"},
//   {"1","1","0","0","0"},
//   {"0","0","1","0","0"},
//   {"0","0","0","1","1"}
// };

// int r = q200(grid);
// std::cout << r << std::endl;


// ----------------------------------------------------------------
