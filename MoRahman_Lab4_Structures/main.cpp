//---------------------Mo Rahman 11/08/2016 11:35------------------------
#include<iostream>
#include<string>		//To use strings
#include<iomanip>		//For set_precision<>()

unsigned short int const NUM_TEST_SCORE = 4;		//The number of test scores per student

//Global constant variables are the exception to the rule! ;)

struct StudentProfile			//Structure tag: Profile of student
{
	unsigned short int testScore[NUM_TEST_SCORE];	//Array of student's testscores
	unsigned int studentID;							//To hold the student's ID number
	std::string studentName;						//String to hold the student's name
};

//FUNCTION PROTOTYPES

//testScore, studentID, studentName; Pass by Pointer
void getGrades(StudentProfile *);
//Pass by value, only the crunchiest
float numCrunch(StudentProfile&);
//Pass by value, pass the object and average
void showResult (StudentProfile, float);

using namespace std;

unsigned short int main()
{
	StudentProfile comSciStu;		//Computer Science Student
	char tryAgain;
	float averageTop3 = 0.0f;		//For the numCrunch function

	cout << "This program generate a student profile. \n";
	cout << "It will also generate the student's average test score; \n"
		<< "based on their three highest scores." << endl;
	do
	{
		//--------------------------------------------------------------------

		getGrades(&comSciStu);

		//-------------------------------------------------------------------

		averageTop3 = numCrunch(comSciStu);

		//-------------------------------------------------------------------

		showResult(comSciStu, averageTop3);

		//-------------------------------------------------------------------
		//Ask the user if they want to try again, and
		cout << "Would you like to try again? \n";
		cout << "Please enter Y or N: \n";
		cin >> tryAgain;
		while (toupper(tryAgain) != 'Y' && toupper(tryAgain) != 'N')
		{
			cout << "Please enter Y or N: \n";
			cin >> tryAgain;
		}
	} while (toupper(tryAgain) == 'Y');

	//system("pause");
	return 1;
}

//Get the info for the student profile
void getGrades(StudentProfile *comSciStu)
{
	
	std::cout << "Hurry up and get the user data and do something with it! \n";
	std::cout << "What is the student's name? :\n";
	
	getline(std::cin, (*comSciStu).studentName); std::cout << std::endl;

	cout << "What is " << comSciStu->studentName << "'s ID number? :\n";
	cin >> comSciStu -> studentID;

	while (comSciStu->studentID >= 4294967295)
	{
		cout << "ID number too great. \n";
		cout << "What is the grade of the test? : ";

		cin >> comSciStu->studentID;
	}
	
	for(unsigned short int counter = 0; counter != NUM_TEST_SCORE; counter++)
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
		
		std::cin >> (*comSciStu).testScore[counter];

		while (comSciStu->testScore[counter] < 0 || comSciStu->testScore[counter] > 100)
		{
			cout << "Grades must range from 0 to 100.\n";
			cout << "What is the grade of the test? : ";

			cin >> comSciStu->testScore[counter];
		}
	}
	std::cout << "Inside the getGrades function. \n";
	for (short counter = 0; counter < NUM_TEST_SCORE; counter++)
	{
		comSciStu->testScore[counter];
	}

}

//Calculate the average of the three highest scores
float numCrunch(StudentProfile &comSciStu)
{
	unsigned short int lowestScore, subTotal = 0;
	
	lowestScore = comSciStu.testScore[0];

	for (short counter = 1; counter < NUM_TEST_SCORE; counter++)
	{
		if (comSciStu.testScore[counter] < comSciStu.testScore[counter + 2])
		{
			lowestScore = comSciStu.testScore[counter];
		}
	}

	for (short counter = 0; counter < NUM_TEST_SCORE; counter++)
	{
		subTotal += comSciStu.testScore[counter];
	}
	
	short total = (subTotal - lowestScore);

	float average = static_cast<float>(total)/(NUM_TEST_SCORE - 1);

	return average;
}

//Display all of the data gathered
void showResult (StudentProfile comSciStu, float avg)
{
	cout << "Name of student: \t \t \t " << comSciStu.studentName <<endl;
	cout << "ID # of student: \t \t \t " << comSciStu.studentID << endl;
	cout << "Test grades of student:\t\t\t" << comSciStu.testScore[0] << " "
		<< comSciStu.testScore[1] << " " << comSciStu.testScore[2] << " "
		<< comSciStu.testScore[3] << " " << endl;
	cout << "The average of the three higest test scores: ";
	cout << setprecision(2) << fixed << avg <<endl;
	cout << "------------------------------------------------- \n";
}