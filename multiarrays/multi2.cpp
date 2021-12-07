#include <iostream>

int main()
{
int arr_row = 0,arr_col = 0;
char mul[3][3]; //3 char arrays with 3 cells
while(arr_row < 3)
{
std::cin >> mul[arr_row][arr_col];
arr_col++;
if(arr_col == 3){arr_col = 0; arr_row++; std::cout << std::endl;}
}
std::cout << std::endl;
arr_col = 0;
arr_row = 0;
while(arr_row < 3)
{
std::cout << mul[arr_row][arr_col];
arr_col++;
if(arr_col == 3){arr_col = 0; arr_row++; std::cout << std::endl;}
}
}
