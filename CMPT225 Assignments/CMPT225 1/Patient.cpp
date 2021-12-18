/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: Harry Preet Singh
 * Date: 19th Januatry 2019
 */

// You can add #include statements if you wish.


#include <iostream>
#include <string>
#include "Patient.h"

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() {

// You need to complete this method.
	careCard = "0000000000";
	email = "To be entered";
	address = "To be entered";
	patientName = "To be entered";
	phone = "To be entered";
	

}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {

// You need to complete this method.
	if (aCareCard.length() < 10)
		careCard = "0000000000";
	else
		careCard = aCareCard;

	email = "To be entered";
	address = "To be entered";
	patientName = "To be entered";
	phone = "To be entered";



}

// Getters and setters -> You need to implement these methods.

string Patient::getAddress() const 
{
	return address;
}

string Patient::getCareCard() const
{
	return careCard;
}

string Patient::getAddress()const
{
	return address;
}

string Patient::getName() const
{
	return patientName;
}

string Patient::getPhone() const
{
	return phone;
}

void Patient::setAddress(const string anAddress )
{
	address = anAddress;
}

void Patient::setEmail(const string anEmail)
{
	email = anEmail;
}

void Patient::setPhone(const string aPhone)
{
	phone = aPhone;
}

void Patient::setName(const string aName)
{
	patientName = aName;
}

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard == rhs.getCareCard();
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard > rhs.getCareCard();
	
} // end of operator >


// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {
	
// You need to complete this method.   
	cout << p.careCard << " - Patient: " << p.patientName << ", " << p.address << ", " << p.phone << ", " << p.email;
	return os;

} // end of operator<<

// end of Patient.cpp