#include <iostream>
#include "student.h"

int main(){
	//create objects s0 thru s2
	Student s0;
	Student s1;
	Student s2;

	//declare some variables used for user input
	std::string input;
	char chinput;
	int input2;

	//set the object default values (Just current year and some blank values)
	s0.initialize();
	s1.initialize();
	s2.initialize();

	/*set first name of each object, the char parameter switches between setting first and last name 
	 f is first name l being last name*/
	std::cout << "Enter first name ";
	std::cin >> input;
	s2.set_name('f', input);
	s0.set_name('f', "John");
	s1.set_name('f', "Joseph");

	std::cout << "\nEnter last name ";
	std::cin >> input;
	s2.set_name('l', input);
	s0.set_name('l', "Carpenter");
	s1.set_name('l', "Cerese");
	
	/*set gender var of each object as a singular character (it only asks for male or female, but won't complain if you give it another character)*/
	std::cout << "\nSet gender (m/f) ";
	std::cin >> chinput;
	s2.set_gender(chinput);
	s0.set_gender('m');
	s1.set_gender('m');

	//set birth year as an integer with four digits
	std::cout << "\nSet birth year (yyyy) ";
	std::cin >> input2;
	s2.set_year(input2);
	s0.set_year(2003);
	s1.set_year(2008);

	std::cout << "\nStudent 1:\n" << "Name: " << s0.access_name('f') << " " << s0.access_name('l') << std::endl << "Age: " << s0.calc_age() << "\nBirth year: " << s0.access_year('b') << std::endl;

	std::cout << "\nStudent 2:\n" << "Name: " << s1.access_name('f') << " " << s1.access_name('l') << std::endl << "Age: " << s1.calc_age() << "\nBirth year: " << s1.access_year('b') << std::endl;

	std::cout << "\nStudent 3:\n" << "Name: " << s2.access_name('f') << " " << s2.access_name('l') << std::endl << "Age: " << s2.calc_age() << "\nBirth year: " << s2.access_year('b') << std::endl;
}
