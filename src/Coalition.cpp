#include "Coalition.h"
#include <vector>


//constructor
Coalition::Coalition(int id): mId(id),mandates(0),parties()
{
}


//copy Constructor
Coalition::Coalition(const Coalition &other) = default;

//copy assignment operator TODO: might wanna change it from default
Coalition& Coalition::operator=(const Coalition &other) = default;

//destructor
Coalition::~Coalition() = default;


/*
adds the partyId to the coalition parties vector and updates the number
of mandates in the coalition
*/
void Coalition::addPartyToCoalition(Party &party){
    parties.push_back(party.getId());
    mandates += party.getMandates();
}

std::vector<int>& Coalition::getParties(){
    return parties;
}

//returns the coalition Id, it's also it's placement in the main coalition vector(added to improve search time)
 int Coalition::getId() const{
    return mId;
}

const int Coalition::getMandates() const{
    return mandates;
}
