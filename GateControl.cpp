//****************************************************************************************
//
//	INCLUDE FILES
//
//****************************************************************************************
#include	<iostream>
#include <map>
#include	"GateControl.hpp"
#include <algorithm>
using namespace std;

//****************************************************************************************
//
//	CONSTANT DEFINITIONS
//
//****************************************************************************************

//****************************************************************************************
//
//	CLASSES, TYPEDEFS AND STRUCTURES

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
AuthorizationMap::iterator it = authorizationMap_.find(number);

	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	if (authorizationMap_.find(number) == authorizationMap_.end()) { //non-existant
			Transaction newT(number, it->second.name_, gCurrentDate, gCurrentTime, false);
				transactionVector_.push_back(newT);
			return false;
	}

	else if ( (it->second.startTime_ < gCurrentTime) && (it->second.endTime_ > gCurrentTime) ) {
			Transaction newT(number, it->second.name_, gCurrentDate, gCurrentTime, true);
				transactionVector_.push_back(newT);
			return true;
	}

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
	if (authorizationMap_.find(number) == authorizationMap_.end()){ //number doesn't exist in map
		authorizationMap_[number] = newAuth;
		return true;
	} else {
		return false;
	}

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

	Authorization changeAuth(number, name, startTime, endTime);
	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	if (authorizationMap_.find(number) == authorizationMap_.end()) //number doesn't exist in map
		return false;
	else {
			authorizationMap_[number] = changeAuth;
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

	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	if (authorizationMap_.find(number) == authorizationMap_.end()) //number doesn't exist in map
		return false;
	else {
		authorizationMap_.erase (authorizationMap_.find(number));
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
	for (auto elem : authorizationMap_)
		authorizationVector.push_back(elem.second);

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
	for (auto elem : transactionVector_)
		transactionVector.push_back(elem);

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
AuthorizationMap::iterator it = authorizationMap_.find(number);
	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	if (authorizationMap_.find(number) == authorizationMap_.end()) //number doesn't exist in map
		return false;
	else {
		if (AccessAllowed(number) == true) {
			authorization = it->second;
			return true;
		} else { return false; }

	}

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
TransactionVector::iterator it = find (transactionVector_.begin(),
																	transactionVector_.end(), number);
	//************************************************************************************
	//	EXECUTABLE STATEMENTS

	if (it != transactionVector_.end()) {
		transactionVector = transactionVector_;
		return true;
	} else { //number doesn't exist
		return false;
	}
}
