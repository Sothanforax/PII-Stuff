#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]){
	int rn;
	srand(time(0));
	if(argc == 2){
		int inpt = atoi(argv[1]);
	for(int i = 0; i < inpt; i++){		
		rn = std::rand() % 100;
		std::cout << rn << " ";
		if(i == inpt - 1){
			std::cout << std::endl;
		}
	}
	}
	else{
		std::cerr << "Invalid argument, or missing argument \nexample usage: ./rs 90\n";
	}
}
