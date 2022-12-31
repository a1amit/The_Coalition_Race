
#include "JoinPolicy.h"
//Join Policy----------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

JoinPolicy::~JoinPolicy(){}

//-MandatesJoinPolicy------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------
void MandatesJoinPolicy::join(Party& party,std::vector<Coalition> &coalitions,std::vector<Agent> &agents,
     std::vector<int> &offersCoalitionIds, std::vector<int> &offersAgentsIds){
        int maxMandates = -1;
        int mostSuitbleAgent = -1; // the index of the most suitble agent in the list
        int mostSuitlbleCoalition = -1; // the index of the most suitble coalition
        for(unsigned int i = 0; i<offersCoalitionIds.size();i++){ // iterates over the offers
            if(maxMandates < coalitions.at(offersCoalitionIds.at(i)).getMandates()){ // iterates over the coalitions that made an offer 
                maxMandates = coalitions.at(offersCoalitionIds.at(i)).getMandates();
                mostSuitbleAgent = offersAgentsIds.at(i); // the most suitble agent is at this index(there's a bijection correspondence between the two int vectors)
                mostSuitlbleCoalition = offersCoalitionIds.at(i); // the index of the most sutible coalition in the coalition vector
            }
        }
        if((maxMandates != -1 && mostSuitbleAgent != -1 && mostSuitlbleCoalition != -1)){
            coalitions.at(mostSuitlbleCoalition).addPartyToCoalition(party); // adds the party to the coalition
            //clone the desired agent
            agents.push_back(Agent(agents.size(), party.getId(), agents[mostSuitbleAgent]));
            party.setState(Joined);
        }
     }

//Virtuall Constructor idiom-------------------------------------------------
//constructor
MandatesJoinPolicy:: MandatesJoinPolicy(){}
//destructor
MandatesJoinPolicy::~MandatesJoinPolicy(){}
//copy constructor
MandatesJoinPolicy:: MandatesJoinPolicy(const MandatesJoinPolicy &other){}
//virtual constructor
MandatesJoinPolicy* MandatesJoinPolicy::create () const{
    return new MandatesJoinPolicy();
}
//virtual copy constructor
MandatesJoinPolicy* MandatesJoinPolicy::clone() const{
    return new MandatesJoinPolicy(*this);
}


//LastOfferJoinPolicy------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------
     void LastOfferJoinPolicy::join(Party& party,std::vector<Coalition> &coalitions,std::vector<Agent> &agents,
     std::vector<int> &offersCoalitionIds, std::vector<int> &offersAgentsIds){
        int mostSuitlbleCoalition = offersCoalitionIds.at(offersCoalitionIds.size()-1); // the most suitble coalition is the last one that offered
        int mostSuitbleAgent = offersAgentsIds.at(offersAgentsIds.size()-1); // the most suitble agent is the last one that offered
        coalitions.at(mostSuitlbleCoalition).addPartyToCoalition(party);
        agents.push_back(Agent(agents.size(), party.getId(), agents[mostSuitbleAgent]));
        party.setState(Joined);
     }
//Virtuall Constructor idiom-------------------------------------------------
//constructor
LastOfferJoinPolicy:: LastOfferJoinPolicy(){}
//destructor
LastOfferJoinPolicy::~LastOfferJoinPolicy(){}
//copy constructor
LastOfferJoinPolicy:: LastOfferJoinPolicy(const LastOfferJoinPolicy &other){}
//virtual constructor
LastOfferJoinPolicy* LastOfferJoinPolicy::create () const{
    return new LastOfferJoinPolicy();
}
//virtual copy constructor
LastOfferJoinPolicy* LastOfferJoinPolicy::clone() const{
    return new LastOfferJoinPolicy(*this);
}