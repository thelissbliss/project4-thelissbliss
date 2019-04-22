//****************************************************************************************
//
//	INCLUDE FILES
//
//****************************************************************************************
#include	<iostream>
#include <map>
#include	"GateControl.hpp"

using namespace std;

//****************************************************************************************
//
//	CONSTANT DEFINITIONS
//
//****************************************************************************************

//****************************************************************************************
//
//	CLASSES, TYPEDEFS AND STRUCTURES
AuthorizationMap authMap;
AuthorizationIterator it;
GateControl gc;
AuthorizationVector authorizationVector;
TransactionVector transactionVector;
//****************************************************************************************

//****************************************************************************************
//
//	PUBLIC DATA
//
//****************************************************************************************
extern	string	gCurrentDate;

extern	string	gCurrentTime;

//****************************************************************************************
//
//	PRIVATE DATA
//
//****************************************************************************************

//****************************************************************************************
//
//	FUNCTION PROTOTYPES
//
//****************************************************************************************

//****************************************************************************************
//
//	GateControl::AccessAllowed
//
//****************************************************************************************
bool	GateControl::AccessAllowed(CardNumber number)
{
	//************************************************************************************
	//	LOCAL DATA
	it = authMap.find(number);

	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	if (it == authMap.end()) //number doesn't exist in map
		return false;
	else return true;
		//does number have access
		/*
		if ()
			return true;
		else
			return false;
			*/
}

//****************************************************************************************
//
//	GateControl::AddAuthorization
//
//****************************************************************************************
bool	GateControl::AddAuthorization(CardNumber number, const string& name,
									  const string& startTime, const string& endTime)
{
	//************************************************************************************
	//	LOCAL DATA
	Authorization newAuth(number, name, startTime, endTime);
	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	if (it == authMap.end()) //number doesn't exist in map
		return false;
	else {
		authMap.insert(pair<CardNumber, Authorization>(number, newAuth));
		return true;
	}
	authorizationVector.push_back(newAuth);
}

//****************************************************************************************
//
//	GateControl::ChangeAuthorization
//
//****************************************************************************************
bool	GateControl::ChangeAuthorization(CardNumber number, const string& name,
										 const string& startTime, const string& endTime)
{
	//************************************************************************************
	//	LOCAL DATA
	it = authMap.find(number);
	Authorization changeAuth(number, name, startTime, endTime);
	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	if (it == authMap.end()) //number doesn't exist in map
		return false;
	else {
			authMap[number] = changeAuth;
			return true;
		}
}

//****************************************************************************************
//
//	GateControl::DeleteAuthorization
//
//****************************************************************************************
bool	GateControl::DeleteAuthorization(CardNumber number)
{
	//************************************************************************************
	//	LOCAL DATA
	it = authMap.find(number);
	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	if (it == authMap.end()) //number doesn't exist in map
		return false;
	else {
		authMap.erase (it);
		return true;
	}
}

//****************************************************************************************
//
//	GateControl::GetAllAuthorizations
//
//****************************************************************************************
void	GateControl::GetAllAuthorizations(AuthorizationVector& authorizationVector)
{
	//************************************************************************************
	//	LOCAL DATA
	AuthorizationIterator	iterator;

	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	cout << &authorizationVector;

	return;
}

//****************************************************************************************
//
//	GateControl::GetAllTransactions
//
//****************************************************************************************
void	GateControl::GetAllTransactions(TransactionVector& transactionVector)
{
	//************************************************************************************
	//	LOCAL DATA

	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	cout << &transactionVector;

	return;
}

//****************************************************************************************
//
//	GateControl::GetCardAuthorization
//
//****************************************************************************************
bool	GateControl::GetCardAuthorization(CardNumber number, Authorization& authorization)
{
	//************************************************************************************
	//	LOCAL DATA

	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	if (it == authMap.end()) //number doesn't exist in map
		return false;
	else
		return true;
}

//****************************************************************************************
//
//	GateControl::GetCardTransactions
//
//****************************************************************************************
bool	GateControl::GetCardTransactions(CardNumber number,
										 TransactionVector& transactionVector)
{
	//************************************************************************************
	//	LOCAL DATA

	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	if (it == authMap.end()) //number doesn't exist in map
		return false;
	else
		return true;
}
