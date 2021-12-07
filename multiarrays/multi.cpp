#include <iostream>

int main()
{
int arr_row = 0,arr_col = 0;
int mul[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
while(arr_row < 3)
{
std::cout << mul[arr_row][arr_col];
arr_col++;
if(arr_col == 3){arr_col = 0; arr_row++; std::cout << std::endl;
}}}
