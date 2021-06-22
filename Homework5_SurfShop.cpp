/* Johnny Utah owns a surf shop on the beach called “Point Break Surf Shop”. 
Johnny sells surfboards in 3 three sizes: small (2 meters), medium (3 meters), and large (4 meters).
The cost of one small surfboard is $175.00, one medium is $190.00, and one large is $200.00. 
Write a program that will make the surf shop operational. 
Your program should allow the user to do the following:
1. Buy any surfboard in any sizeand in any quanity.
2. At any time show the total number of surfboards of each size sold.
3. At any time show the total money made.*/


#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>    //this is needed for.... transform(input.begin(), input.end(), input.begin(), toupper); changes input to cap letters
using namespace std;

//CONSTANT VARIBLES= PRICES
const double SMALL_PRICE = 175.00;
const double MEDIUM_PRICE = 190.00;
const double LARGE_PRICE = 200.00;
//for git hub
const double XXXS_PRICE = 50.00;

//'S' entered as selection
void ShowUsage() {		//a function to show the user how to use the program.
	cout << endl;
	cout << "To show program usage 'S'" << endl;
	cout << "To purchase a surdboard press 'P'" << endl;
	cout << "To display current purchases press 'C'" << endl;
	cout << "To display total amout due press 'T'" << endl;
	cout << "To quit press 'Q' " << endl;
	cout << endl;

}

//a function to sell surfboards.
//when 'P' is entered... to make a purchase
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS) {
	//declaring varibles
	string size;
	int quanity = 0;
	cout << "Please enter the quanity and type(S = small, M = medium, L = large, XXXS = Squirrel Surfing) of surfboard you would like to purchase: ";
	//input from user
	cin >> quanity >> size;	
	transform(size.begin(), size.end(), size.begin(), toupper);
	cout << endl;
	// begining of if else statement
	if (size == "S") {
		iTotalSmall = iTotalSmall + quanity;
	}
	else if (size == "M") {
		iTotalMedium = iTotalMedium + quanity;
	}
	else if (size == "L") {
		iTotalLarge = iTotalLarge + quanity;
	}
	else if (size == "XXXS") {
		iTotalXXXS = iTotalXXXS + quanity;
	}

}

//when 'C' is entered
//function to show the number of surfboards of each size sold.
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS) {
	//dispalying total count of boards only if there was a quanity entered
	if (iTotalSmall > 0) {
		cout << "The total number of small surfboards is: " << iTotalSmall << endl << endl;
	}
	if (iTotalMedium > 0) {	//seperate if statment. If else would not print out all 3
		cout << "the total number of medium surfboards is: " << iTotalMedium << endl <<endl;
	}
	if (iTotalLarge > 0) {
		cout << "the total number of large surfboards is: " << iTotalLarge << endl <<endl;
	}
	if (iTotalXXXS > 0) {	//github
		cout << "the total number of large surfboards is: " << iTotalXXXS << endl << endl;
	}
	//when user does not purchase any boards yet
	if ((iTotalLarge <= 0) && (iTotalMedium <= 0) && (iTotalSmall <= 0) && (iTotalXXXS <= 0)) {
		cout << "No purchases made yet." << endl << endl;
	}

}

//a function to show the total amount of money made.
//when 'T' is entered
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS) {
	//calculating totals, using constants
	double smallTotal = iTotalSmall * SMALL_PRICE;
	double mediumTotal = iTotalMedium * MEDIUM_PRICE;
	double largeTotal = iTotalLarge * LARGE_PRICE;
	double xxxsTotal = iTotalXXXS * XXXS_PRICE;
	//displaying only if a value was entered in 'P'
	if (iTotalSmall > 0) {
		cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << setprecision(2) << fixed << smallTotal << endl << endl;	//setting to 2 decimal places
	}
	if (iTotalMedium > 0) {
		cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << setprecision(2) << fixed << mediumTotal << endl <<	endl;
	}
	if (iTotalLarge > 0) {
		cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << setprecision(2) << fixed << largeTotal << endl << endl;
	}
	//github
	if (iTotalXXXS > 0) {
		cout << "The total number of Squirrel surfboards is " << iTotalXXXS << " at a total of $" << setprecision(2) << fixed << xxxsTotal << endl << endl;
	}
	//when user does not purchase any boards yet
	if ((iTotalLarge <= 0) && (iTotalMedium <= 0) && (iTotalSmall <= 0) && (iTotalXXXS <= 0)) {
		cout << "No purchases made yet." << endl << endl;
	}
}





//MAIN FUNCTION. Other functions must be declared before main
int main()
{	//initializing quanity of boards....
	int iTotalSmall = 0; int iTotalMedium = 0; int iTotalLarge = 0;
	int iTotalXXXS = 0;
	//users input
	string selection;
	

	//displaying a header
	cout << setw(80) << setfill('*') << "" << endl;		//this will print out 80 '*'
	cout << setw(60) << setfill('*') << right << "Welcome to my Jonny Utah's PointBreak Surf Shop" << left << setw(20) << setfill('*') << "" << endl;	//centering my text within 80 collumns
	cout << setw(80) << setfill('*') << "" << endl << endl;	//setw() = sets a number of collumns, setfill()= allows you to fill in thoes blank collumns when needed

	ShowUsage(); //calling function

	do // start of do..while loop
	{	//do = always do these functions
		cout << "Please enter selection: ";
		cin >> selection;	//input
		transform(selection.begin(), selection.end(), selection.begin(), std::toupper);	//transforming input into CAPS. this makes it easier to read both lower and cap in loop.

		if (selection == "S") { //so s or S
			ShowUsage();	//calling function
		}
		else if (selection == "P") {
			MakePurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);	//calling function with parameters
		}
		else if (selection == "C") {
			DisplayPurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS); //calling function with parameters
		}
		else if (selection == "T") {
			DisplayTotal(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);	//calling function with parameters
		}
	} while (selection != "Q" );	//do until user enters 'Q' or 'q'
	//end of do...while loop


	cout << "Thank you";	//exiting....
	}




//COMMENTED OUT CODE//
	//if ((selection == "s") || (selection == "S")) {


	//}
	//else if ((selection == "P") || (selection == "p")) {
		//	MakePurchase(TotalSmall, TotalMedium, TotalLarge);
	//}
	
	//while (cin)
//	{ cout << "Please enter selection: ";

	//	if ((selection == "s") || (selection == "S")) {
		//cout << "Please enter selection: ";
		//cin >> selection;
	//	ShowUsage();
	//}