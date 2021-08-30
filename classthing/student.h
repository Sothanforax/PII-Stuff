class Student{
	private:
	std::string fnam, lnam;
	char gend;
	int year[2];

	public:
	void initialize(){
		fnam = "";
		lnam = "";
		gend = ' ';
		year[0] = 2021;
	}

	void set_gender(char input){
		gend = input;
	}

	int access_gender(){
		return gend;
	}

	std::string access_name(char opt){
		if(opt == 'f'){
			return fnam;
		}
		else if(opt == 'l'){
			return lnam;
		}
		return 0;
	}

	void set_name(char opt, std::string input){
		if(opt == 'f'){
			fnam = input;
		}
		else if(opt == 'l'){
			lnam = input;
		}
	}
	int access_year(char input){
		if(input == 'c'){
			return year[0];
		}
		else if(input == 'b'){
			return year[1];
		}
		return 0;
	}

	void set_year(int input){
		year[1] = input;
	}

	int calc_age(){
		int age = year[0] - year[1];
		return age;
	}

};
