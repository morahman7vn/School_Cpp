//------------------------------------------------------------------------
#include<iostream>
#include<string>		//To use strings
#include<iomanip>		//For set_precision<>()

struct StudentProfile			//Structure tag: Profile of student
{

public:
	unsigned short int testScore;					//Array of student's testscores
	unsigned int studentID;							//To hold the student's ID number
	std::string studentName;						//String to hold the student's name

};

//Function prototypes

//testScore, studentID, studentName; Pass by Value
void getGrades(StudentProfile *, StudentProfile *, unsigned short int const*);
//Pass by pointer, only the crunchiest
float numCrunch(StudentProfile (&dummy) [4],unsigned short int const&);

//void showResult (StudentProfile, unsigned short int const);

unsigned short int main()
{
	unsigned short int const NUM_TEST_SCORE = 4;	//Number of test scores per student
	unsigned short int const *constPtr = &NUM_TEST_SCORE;
	StudentProfile comSciStu;		//Computer Science Student
	StudentProfile gradesFolder[NUM_TEST_SCORE];
	//StudentProfile *gradesFolder = nullptr, *comSciStuPtr = nullptr;

	float averageTop3 = 0.0f;

	std::cout << "This program generate a student profile. \n";
	std::cout << "It will also generate the student's average test score." << std::endl;

	std::cout << "The size of gradesFolder before it goes into the getGrades function: ";
	std::cout << sizeof(gradesFolder) << " bytes\n and the address is: " << &gradesFolder << std::endl;

	std::cout << "However, the size of the testscore member variable is : ";
	std::cout << sizeof(gradesFolder[0].testScore) << "bytes\n and the address is: " << &gradesFolder[0].testScore << std::endl;

	std::cout << "By the way, the value of the testscore element is: " << gradesFolder[0].testScore << std::endl;

	getGrades(&comSciStu, &gradesFolder[NUM_TEST_SCORE], &NUM_TEST_SCORE);

	std::cout << "Inside the main function. \n";
	std::cout << gradesFolder[0].testScore << std::endl; std::cout << gradesFolder[1].testScore << std::endl;
	std::cout << gradesFolder[2].testScore << std::endl; std::cout << gradesFolder[3].testScore << std::endl;
	
	averageTop3 = numCrunch(gradesFolder, NUM_TEST_SCORE);

	system("pause");
	return 1;
}

//using namespace std;

//Get the info for the student profile
void getGrades(StudentProfile *comSciStu, StudentProfile *gradesFolder, unsigned short int const *NUM_TEST_SCORE)
{
	
	std::cout << "Hurry up and get the user data and do something with it! \n";
	std::cout << "What is the student's name? :\n";
	
	getline(std::cin, (*comSciStu).studentName); std::cout << std::endl;

	std::cout << "What is the student's ID number? :\n";
	std::cin >> comSciStu -> studentID;
	
	for(unsigned short int counter = 0; counter != *NUM_TEST_SCORE; counter++)
	{
		std::cout << "What is grade No."<< counter +1 << " of "
				<< comSciStu ->studentName << "'s "<< counter +1;
		if (counter == 0)
			std::cout << "st test? \n";
		else if (counter == 1)
			std::cout << "nd test? \n";
		else if (counter == 2)
			std::cout << "rd test? \n";
		else
			std::cout << "th test ?\n";
		
		std::cin >> gradesFolder[counter].testScore;

		while (gradesFolder[counter].testScore < 0 || gradesFolder[counter].testScore > 100)
		{
			std::cout << "Grades must range from 0 to 100.\n";
			std::cout << "What is the grade of the test? : ";
			std::cin >> gradesFolder[counter].testScore;

		}

	}
	std::cout << "Inside the getGrades function. \n";
	std::cout << gradesFolder[0].testScore << std::endl; std::cout << gradesFolder[1].testScore << std::endl;
	std::cout << gradesFolder[2].testScore << std::endl; std::cout << gradesFolder[3].testScore << std::endl;
}

float numCrunch(StudentProfile  (&gradesFolder)[4], unsigned short int const &NUM_TEST_SCORE)
{

	std::cout << NUM_TEST_SCORE << std::endl;
	std::cout << gradesFolder[0].testScore;
	
	return 0.0f;
}
/*
void showResult (StudentProfile &comSciStu, unsigned short int const &NUM_TEST_SCORE)
{
	;
}
*/
