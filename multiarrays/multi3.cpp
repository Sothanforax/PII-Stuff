#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
int arr_row = 0,arr_col = 0;
int args[3];
args[1] = atoi(argv[1]);
args[2] = atoi(argv[2]);
char mul[args[1]][args[2]]; //3 char arrays with 3 cells
while(arr_row < args[1])
{
std::cin >> mul[arr_row][arr_col];
arr_col++;
if(arr_col == args[2]){arr_col = 0; arr_row++; std::cout << std::endl;}
}
std::cout << std::endl;
arr_col = 0;
arr_row = 0;
while(arr_row < args[1])
{
std::cout << mul[arr_row][arr_col];
arr_col++;
if(arr_col == args[2]){arr_col = 0; arr_row++; std::cout << std::endl;}
}
}
