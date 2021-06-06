#include "problem_a.hpp"

bool is_prime(int n)
{
    if (n <= 1) {
        return false;
    }

    else {
        for (int i = 2; i <= n/2; i++) {
            if (n % i == 0) {
                return false;
                break;
            }
        }

        return true;
    }
}

unsigned int factorial(unsigned int n)
{
    if (n < 1)
    {
        return 1;
    }

    int f = 1;
    for (int i = n; i >= 1; i--)
    {
        f *= i;
    }

    return f;
}

void inplace_sort(size_t n, int arr[])
{
  for(size_t i = 0; i < n - 1; i++)
  {
    for(size_t j = 0; j < n - i - 1; j++)
    {
      if(arr[j+1] < arr[j])
      {
        std::swap(arr[j+1], arr[j]);
      }
    }
  }
}

void inplace_reverse_str(std::string &str)
{
  for(size_t i = 0; i < str.size() / 2; i++)
  {
    std::swap(str[i], str[str.size() - i - 1]);
  }
}

std::string reverse_str(const std::string &str)
{
 std::string tempt = str;

  for(size_t i = 0; i < tempt.size() / 2; i++)
  {
    std::swap(tempt[i], tempt[tempt.size() - i - 1]);
  }

  return tempt;
}