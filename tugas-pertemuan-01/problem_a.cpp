#include "problem_a.hpp"

int *multiply_by_two(int &n)
{
      n *=2;
        return &n;
}

std::string the_third_and_fifth(char *ptr)
{
  std::string hasil;
  hasil += *(&ptr[2]); 
  hasil += *(&ptr[4]);
  
  return hasil;
}

int my_own_strlen(char *ptr)
{
   int length = 0;
  
  while(1){
    if (*(&ptr[length]) == 0){
      break;
    }
    length++;
  }

  return length;
}

void element_swapper(int *ptr1, int *ptr2, int n)
{
  int temp = ptr1[n];
  *&ptr1[n] = *&ptr2[n];
  *&ptr2[n] = temp;
}