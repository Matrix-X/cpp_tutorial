// https://www.youtube.com/watch?v=Rub-JsjMhWY

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int guessNumber() {
	/* code */
	string numberGuessed;
	int intNumberGuessed = 0;

	do{
		cout << "Guess between 1 and 10: ";
		getline(cin, numberGuessed);
		intNumberGuessed = stoi(numberGuessed);
		std::cout << intNumberGuessed << '\n';

	}while(intNumberGuessed !=4 );

	cout << "You win" << endl;

	return 0;
}

int happyBirthday() {
	/* code */

	char happyArray[6] = {'H','a','p','p','y','\0'};
	string strBirthday = " Birthday";

	std::cout << happyArray + strBirthday << endl;

	return 0;
}

int vectorOutput() {
	/* code */
	vector <int>	lotteryNumVect(10);
	int lotteryNumArray[5] = {4, 13, 14, 24, 34};
	// cout << lotteryNumVect << endl;
	lotteryNumVect.insert(lotteryNumVect.begin()+5, lotteryNumArray, lotteryNumArray+3);
	cout << lotteryNumVect.at(5) << endl;

	// lotteryNumVect.push_back(64);
	// std::cout << "final value:" << lotteryNumVect.back() << '\n';

	lotteryNumVect.pop_back();
	std::cout << "first value:" << lotteryNumVect.front() << '\n';
	std::cout << "size value:" << lotteryNumVect.size() << '\n';
	std::cout << "empty is:" << lotteryNumVect.empty() << '\n';

	return 0;
}

int saveStringToFile() {
	/* code */
	string steveQuote = "A day without sunshine is like, you konw, night";
	ofstream writer("steveQuote.txt");

	if(!writer){
		cout << "Error opening file" << endl;
		return -1;
	}else{
		writer << steveQuote << endl;
		writer.close();
	}

	// appending strings
	ofstream writer2("steveQuote.txt", ios::app);
	if(!writer2){
		cout << "Error opening file" << endl;
		return -1;
	}else{
		writer2 << "\n - steve martin" << endl;
		writer2.close();
	}

	char letter;
	ifstream reader("steveQuote.txt");
	if(!reader){
		std::cout << "Error opening file" << '\n';
		return -1;
	}else{
		for(int i; !reader.eof(); i++ ){
			reader.get(letter);
			cout << letter;
		}
		cout << endl;
		reader.close();
	}

	return 0;
}

int pointerOnCPP() {
	/* code */
	int myAge = 36;
	char myGrade = 'A';

	std::cout << "Size of int "<< sizeof(myAge) << '\n';
	std::cout << "Size of char "<< sizeof(myGrade) << '\n';

	std::cout << "myAge is locate at " << &myAge << '\n';

	return 0;
}

int makeMeYoung(int* age) {
	/* code */
	std::cout << "I used to be " << *age << '\n';
	*age = 21;

	return 0;
}

int actYourAge(int& ageRef) {
	/* code */
	ageRef = 39;

	return 0;
}



class Animal{
	private:
			// which shoulld be change by methods
			int height;
			int weight;
			string name;

			// this is shared by any object of animal that is ever created
			static int numOfAnimals;

	public:
			int getHeight(){return height;}
			int getWeight(){return weight;}
			string getName(){return name;}
			void setHeight(int cm){ height = cm; }
			void setWeight(int km){ weight = km; }
			void setName(int animalName){ name = animalName; }

			// void setAll(int, int , string );
			Animal(int, int , string );

			~Animal();
			Animal();

			static int getNumOfAnimals(){
				return numOfAnimals;
			}

			void toString();
};

int Animal::numOfAnimals = 0;
Animal::Animal(int height, int weight, string name){
	this->height = height;
	this->weight = weight;
	this->name = name;
	Animal::numOfAnimals++;
}
Animal::~Animal(){
	std::cout << "Animal " << this->name << " destoried" << '\n';
}

Animal::Animal(){
	Animal::numOfAnimals++;
}

void Animal::toString(){
	std::cout << this->name << " is " << this->height
	<< "cms tall and " << this->weight << "kgs in weight" <<  '\n';
}




class Dog : public Animal{
private:
	string sound = "Woof";

public:
	void getSound() {std::cout << sound << '\n';}
	Dog(int, int, string, string);
	Dog() : Animal(){};
	void toString();
};

Dog::Dog(int height, int weight, string name, string bark) : Animal(height, weight, name){
	this->sound = bark;
}
void Dog::toString(){
	std::cout << this->getName() << " is " << this->getHeight()
	<< "cms tall and " << this->getWeight() << "kgs in weight and says "
	<< this->sound <<  '\n';
}


int main(){

	cout << "hello world" << endl;

	// const double PI = 3.1415926535;
	// char myGrade = 'A';
	// bool isHappy = true;
	int myAge = 36;
	// float fNum = 3.14;
	// double fOtherNum = 1.618;
	//
	// cout << "Favorite Number " << fNum << endl;
	// cout << "Size of int " << sizeof(myAge) << endl;
	// cout << "Size of char " << sizeof(myGrade) << endl;
	// cout << "Size of bool " << sizeof(isHappy) << endl;
	// cout << "Size of float " << sizeof(fNum) << endl;
	// cout << "Size of double " << sizeof(fOtherNum) << endl;

	// Other types includes
	// short int: At least 16 bits
	// long int: At least 32 bits
	// long long int: At least 64 bits
	// unsigned int: same size as asigned  version
	// long double: Not less than double

	// int largestInt = 2147483647;
	// // largestInt = 2147483648;
	// cout << "Largest Number " << largestInt << endl;


	// cout << "5 + 2 = " << 5+2 << endl;
	// cout << "5 * 2 = " << 5*2 << endl;
	// cout << "5 - 2 = " << 5-2 << endl;
	// cout << "5 / 2 = " << 5/2 << endl;
	// cout << "5 % 2 = " << 5%2 << endl;

	// guessNumber();
	// happyBirthday();
	// vectorOutput();
	// saveStringToFile();

	// pointerOnCPP();
	// makeMeYoung(&myAge);
	// std::cout << "I'm " << myAge << " years old now" << '\n';
	// int& ageRef = myAge;
	// std::cout << "myAge : " << myAge << '\n';
	// ageRef++;
	// std::cout << "myAge : " << myAge << '\n';
	// actYourAge(ageRef);
	// std::cout << "myAge : " << myAge << '\n';

	Animal fred(33, 10, "Fred");
	Animal tom(36, 15, "Tom");
	Dog spot(38, 16, "Spot", "Woof");


	fred.toString();
	tom.toString();
	spot.toString();
	spot.getSound();

	return 0;
}
