/*
C++ Compile
  g++ sourcefile_name.cpp -o outputfile.exe header1.cpp header2.cpp
  ./outputfile

  g++ main.cpp -o main.exe solution/solution.cpp solution/my_data_structure.cpp
*/

/*
C++ Interview Resources

https://www.youtube.com/watch?v=QSuBwGmFQqA&list=PLk6CEY9XxSIDy8qVHZV-Nf-r9f2BkRZ6p
https://www.youtube.com/watch?v=Peq4GCPNC5c
https://www.youtube.com/watch?v=bFtkHJy9kIU
*/

#include <iostream>
#include <string>
// #include "MyDataStructure.h"
#include <vector>

#include "solution.h"


int main()
{
  // int t = 0;
  // std::vector<int> nums = {-1,0,1,2,-1,-4};
  // std::vector<std::vector<int>> a = q15(t, nums);

  std::cout << !false << std::endl;
  

  std::vector<std::vector<int>> prereq {{1,0}, {0,1}};
  bool q207 = Q207(2, prereq);
  std::cout << "result Q207: " << q207 << std::endl;
  
  std::vector<int> arr {2,1,1,3,2,5,1};
  int q213 = Q213(arr);
  std::cout << "result Q213: " << q213 << std::endl;

  
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
