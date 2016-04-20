/*	Mo Rahman 01/26/2016 - 14:18 04/20/2016 [COMPLETED]
	Com Info 739
	Lab Assignment 9 Chapter 5
	Hotel Occupancy
	Page #294-295*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const short int PERCENTAGE = 100, MISSING_FLOOR = 1; // Need constants to represent the missing floor, and multiply the percentage values 100.
	short hotelFloors = 0, rooms, occupiedRooms, //"unOccupiedRooms" isn't necessary. 
		totalRooms = 0, totalOccupiedRooms = 0, totalUnoccupiedRooms;
	double percentage_of_rooms_occupied;
	
	//Explain to the user what this program is designed to do.
	
	cout << "This program is designed to calculate the occupancy rate for a hotel. \n"
		"NOTE: Each hotel floor must have at least 10 rooms. \n"<< endl;

	//Ask the user how many floors are in the hotel. (Floor values cannot be less than one)

	cout << "How many floors does this hotel contain? \n" "The floors will be counted from top to bottom. \n";
	cin >> hotelFloors;

	if (hotelFloors >= 13)
	{
		hotelFloors += MISSING_FLOOR;
	}						/************************************************************************************************
						     *The total number of hotel floors must still be counted for the math and logic to be correct.	*
							 *With 13th floor iteration is being skipped,													*
							 *a placeholder for the missing floor must go in it's place.									*
							 *However, a "MISSING_FLOOR" doesn't need to be added to any => 13								* 
							 ************************************************************************************************/

	while (hotelFloors <= 1)
	{
		cout << "You must enter a value of floors greater than 1. \n"
			"It doesn't count as a hotel if it only has the ground floor. \n";
		
		cin >> hotelFloors;
		
	}
	
	for (int floorCount = 1; floorCount <= hotelFloors; hotelFloors--)
	{
		if (hotelFloors == 13)
			--hotelFloors;
		//Ask about how many rooms does the floor have? (Room values cannot be less than 10)
		
		cout << "How many rooms does floor No." << hotelFloors << " have? \n";

		cin >> rooms;

		while (rooms < 10)
		{
			cout << "A hotel floor must have at least 10 rooms. \n" "Please try again. \n";
			
			cin.clear();
			cin >> rooms;

		}

		//Ask the user how many of those floors are occupied.

		cout << "How many of these room are occupied? \n";

		cin >> occupiedRooms;

		while (occupiedRooms < 0||occupiedRooms > rooms)
		{
			cout << "INVALID ENTREY: Number of occupied rooms cannot be greater than \n" "the number of actual rooms or negative. \n"
				"please enter a positive or null value for the unoccupied rooms. \n";
			
			cin.clear();
			cin >> occupiedRooms;
		}
		totalOccupiedRooms += occupiedRooms;//The "occupiedRooms" value has limited scope, thus
		totalRooms += rooms;
	}

	//Calculate how many of the room are unoccupied.
	
	totalUnoccupiedRooms = totalRooms - totalOccupiedRooms;

	/*Calculate the percentage of rooms that are unoccupied.
	It is possible to cheat by multiplying the integers by "1.0f"*/

	percentage_of_rooms_occupied = static_cast <double> (totalOccupiedRooms) / static_cast <double> (totalRooms) * PERCENTAGE;

	//cout << setprecision(2) << fixed; //The decimal point is obtrusive to the percent symbol; no "showpoint"

	/*Display to the user how many room the entire hotel has, and how many are occupied, and unoccupied.
	As well as the percentage of rooms that are un occupied.*/

	//system("CLS");

	cout << "Your hotel has " << totalRooms << " rooms. \n"
		<< totalOccupiedRooms << " of those rooms are occupied. \n"
		<< totalUnoccupiedRooms << " of those rooms are unnoccupied: " <<endl
		<<"The percentage of rooms occupied: " << percentage_of_rooms_occupied << "% \n";

	system("pause");
	return 0;
}