/**
 * @file main.cpp
 * @author Jeffin Johny K (jeffinjk@umd.edu)
 * @brief Code for RWA1
 * @version 0.1
 * @date 2021-09-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>

/**
 * @brief To check whether input value is positive integer(0 not included) or not
 * 
 * @param Input data as string 
 * @return true 
 * @return false 
 */
bool isNumber(const std::string& str);

/**
 * @brief Get the total number of parts to be placed in boxes
 * 
 * @return unsigned Number of parts entered by the user 
 */
unsigned int get_total_parts();

/**
 * @brief Get the total number of boxes for each type
 * 
 * @param struct box to hold box/part information 
 */
void get_total_boxes(struct box& boxes);

/**
 * @brief Get the number of parts for each box type
 * 
 * @param Struct box to hold box/part information 
 */
void get_part_per_box(struct box& boxess);

/**
 * @brief Fill up boxes using user input
 * 
 * @param struct box to hold box/part information 
 */
void fill_up_boxes(const struct box& boxes);

struct box {
	unsigned int Nx{}; //Number of boxes for XL
	unsigned int Nl{}; //Number of boxes for L
	unsigned int Nm{}; //Number of boxes for M
	unsigned int Ns{}; //Number of boxes for S
	unsigned int Cx{}; //Number of parts for each XL box
	unsigned int Cl{}; //Number of parts for each L box
	unsigned int Cm{}; //Number of parts for each M box
	unsigned int Cs{}; //Number of parts for each S box
	unsigned int Tt{}; //Total number of parts
}BOX; //Structure variable

bool isNumber(const std::string& str) //returns either 0 or 1
{
    return !str.empty() &&
        std::find_if(str.begin(), str.end(), 
            [](unsigned char c) { return !std::isdigit(c); }) == str.end();
} //using findif and isdigit std functions to check whether each character is digit in the array of characters

unsigned int get_total_parts()
{
	std::string total{};
	std::cout <<"How many parts in total?"<<'\n';
	std::getline(std::cin >> std::ws,total);
	 //Not necessary to use getline,can work with basic cin as well 
	
	while((!isNumber(total)) || (std::stoi(total)==0)) //while loop, if data inputed is not a positive integer
	{
		std:: cout<<"Please enter a positive integer"<<'\n';
		std:: getline(std::cin>>std::ws,total);
		if((isNumber(total)) && (std::stoi(total)))  //inputed data is positive integer 
		return std::stoi(total); //return data to main
	}
    return std::stoi(total);
}

void get_total_boxes(box& boxes)
{
std::string XL{};
std::string L{};
std::string M{};
std::string S{};
std::cout << "How many boxes for S/M/L/XL?(Press ENTER after inputing each data)" << '\n';

std::getline(std::cin >> std::ws,S);
while((!isNumber(S)) || (std::stoi(S)==0)) //while loop, if data inputed is not a positive integer
	{
		std:: cout<<"Please enter a positive integer for S"<<'\n';
		std:: getline(std::cin>>std::ws,S);
		if((isNumber(S)) && (std::stoi(S)))
		boxes.Ns= std::stoi(S); //Assigning data to structure 
	}
    boxes.Ns= std::stoi(S);

std::getline(std::cin >> std::ws,M);
while((!isNumber(M)) || (std::stoi(M)==0))
	{
		std:: cout<<"Please enter a  integer for M"<<'\n';
		std:: getline(std::cin>>std::ws,M);
		if((isNumber(M)) && (std::stoi(M)))
		boxes.Nm= std::stoi(M);
	}
    boxes.Nm= std::stoi(M);	

std::getline(std::cin >> std::ws,L);
while((!isNumber(L)) || (std::stoi(L)==0))
	{
		std:: cout<<"Please enter a positive integer for L"<<'\n';
		std:: getline(std::cin>>std::ws,L);
		if((isNumber(L)) && (std::stoi(L)))
		boxes.Nl= std::stoi(L);
	}
    boxes.Nl= std::stoi(L);

std::getline(std::cin >> std::ws,XL);
while((!isNumber(XL)) || (std::stoi(XL)==0))
	{
		std:: cout<<"Please enter a positive integer for XL"<<'\n';
		std:: getline(std::cin>>std::ws,XL);
		if((isNumber(XL)) && (std::stoi(XL)))
		boxes.Nx= std::stoi(XL);
	}
    boxes.Nx= std::stoi(XL);
}

void get_part_per_box(box& boxess)
{
std::string XL{};
std::string L{};
std::string M{};
std::string S{};
std::cout << "How many parts per box for S/M/L/XL?(Press ENTER after inputing each data)" << '\n';

std::getline(std::cin >> std::ws,S);
while((!isNumber(S)) || (std::stoi(S)==0))
	{
		std:: cout<<"Please enter a positive integer for S"<<'\n';
		std:: getline(std::cin>>std::ws,S);
		if((isNumber(S)) && (std::stoi(S)))
		boxess.Cs= std::stoi(S);
	}
    boxess.Cs= std::stoi(S);

std::getline(std::cin >> std::ws,M);
while((!isNumber(M)) || (std::stoi(M)==0))
	{
		std:: cout<<"Please enter a  integer for M"<<'\n';
		std:: getline(std::cin>>std::ws,M);
		if((isNumber(M)) && (std::stoi(M)))
		boxess.Cm= std::stoi(M);
	}
    boxess.Cm= std::stoi(M);	

std::getline(std::cin >> std::ws,L);
while((!isNumber(L)) || (std::stoi(L)==0))
	{
		std:: cout<<"Please enter a positive integer for L"<<'\n';
		std:: getline(std::cin>>std::ws,L);
		if((isNumber(L)) && (std::stoi(L)))
		boxess.Cl= std::stoi(L);
	}
    boxess.Cl= std::stoi(L);

std::getline(std::cin >> std::ws,XL);
while((!isNumber(XL)) || (std::stoi(XL)==0))
	{
		std:: cout<<"Please enter a positive integer for XL"<<'\n';
		std:: getline(std::cin>>std::ws,XL);
		if((isNumber(XL)) && (std::stoi(XL)))
		boxess.Cx= std::stoi(XL);
	}
    boxess.Cx= std::stoi(XL);

	if( !((boxess.Cs<boxess.Cm) && (boxess.Cm<boxess.Cl) && (boxess.Cl<boxess.Cx)) ) 
	{
		std::cout <<"The values are not in ascending order" << '\n';
		get_part_per_box(BOX); //only activates when the inputed values are not in the prescribed condition
	}	
}

void fill_up_boxes(const box& boxes)
{
	int j{0};
	int t;
	t=boxes.Tt;
	std::cout<<"Boxes that can be built with "<<t<<" pegs" << '\n';
	for(int i{1};i<=boxes.Nx;i++) //loop for filling box XL type
	{
		if(boxes.Cx<=t) //condition for filling
		{
			t=t-boxes.Cx;
			j++;
		}
	}
	std::cout<<"XL box ("<<boxes.Nx<<" x "<<boxes.Cx<<" max): "<<j<<"-- remaining parts: "<<t<<'\n';

	j=0; //reinitialising j=0

	for(int i{1};i<=boxes.Nl;i++) //for filling box of L type
	{
		if(boxes.Cl<=t)
		{
			t=t-boxes.Cl;
			j++;
		}
	}
	std::cout<<"L box ("<<boxes.Nl<<" x "<<boxes.Cl<<" max): "<<j<<"-- remaining parts: "<<t<<'\n';

	j=0;

	for(int i{1};i<=boxes.Nm;i++) //for filling box of M type
	{
		if(boxes.Cm<=t)
		{
			t=t-boxes.Cm;
			j++;
		}
	}
	std::cout<<"M box ("<<boxes.Nm<<" x "<<boxes.Cm<<" max): "<<j<<"-- remaining parts: "<<t<<'\n';

	j=0;

	for(int i{1};i<=boxes.Ns;i++) //for filling box of S type
	{
		if(boxes.Cs<=t)
		{
			t=t-boxes.Cs;
			j++;
		}
	}
	std::cout<<"S box ("<<boxes.Ns<<" x "<<boxes.Cs<<" max): "<<j<<"-- remaining parts: "<<t<<'\n';

	std::cout<<"Parts not in boxes : "<<t<<'\n';
}

int main()
{
	unsigned int T;
	T=get_total_parts();
	BOX.Tt=T; //assigning T to structure
	get_total_boxes(BOX);
	get_part_per_box(BOX);
	fill_up_boxes(BOX);
}