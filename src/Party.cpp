#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"
#include <vector>

Party::Party(int id, string name, int mandates, JoinPolicy *jp) 
: mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),coalitionId(-1),cooldown(3),offersByCoalitionId(),offersByAgentIndex()
{
    // You can change the implementation of the constructor, but not the signature!
}
void Party::clear(){
    delete mJoinPolicy;
}
//copy Constructor
Party::Party(const Party &other)
    : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState),
    coalitionId(other.coalitionId),cooldown(other.cooldown),offersByCoalitionId(other.offersByCoalitionId),offersByAgentIndex(other.offersByAgentIndex)
{
}

// copy assignment operator
Party& Party::operator=(const Party &other){
    if(this != &other){
        clear();
        mJoinPolicy=other.mJoinPolicy->clone();
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mState = other.mState;
        coalitionId = other.coalitionId;
        cooldown = other.cooldown;
        offersByCoalitionId = other.offersByCoalitionId;
        offersByAgentIndex = other.offersByAgentIndex;
    }
    return *this;
}

//destructor
Party::~Party(){
   clear();
}


 //move constructor
 Party::Party(Party &&other) noexcept
    :mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), 
    mState(other.mState),coalitionId(other.coalitionId),cooldown(other.cooldown),offersByCoalitionId(other.offersByCoalitionId),
    offersByAgentIndex(other.offersByAgentIndex)
 {
    other.mJoinPolicy=nullptr;
 }

//move assignment
Party& Party::operator=(Party &&other)noexcept{
    clear();
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy=other.mJoinPolicy;
    other.mJoinPolicy=nullptr;
    mState = other.mState;
    coalitionId = other.coalitionId;
    cooldown = other.cooldown;
    offersByCoalitionId = other.offersByCoalitionId;
    offersByAgentIndex = other.offersByAgentIndex;
    return *this;
}


State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

const int & Party::getId() const
{
    return mId;
}

void Party::setCoalitionId(int coalitionId){
    coalitionId = coalitionId;
}


 const bool Party::offerExists(int id) const{
    if(offersByCoalitionId.empty()){ // if the vector is empty
        return false;
    }
    for(unsigned int i = 0; i < offersByCoalitionId.size();i++){ 
        if(offersByCoalitionId.at(i) == id){ //if an agent from this coalition already made an offer
            return true;
        }
    }
    return false;
}

void Party::addOffer(int coalitionId, int agentID){
        offersByCoalitionId.push_back(coalitionId);
        offersByAgentIndex.push_back(agentID);
    }

void Party::step(Simulation &s)
{
    // TODO: implement this method
    if(mState == CollectingOffers){
        cooldown--;
        if(cooldown == 0){ // when cooldown reaches zero the party needs to decide based on it's policy who to join
            mJoinPolicy->join(*this,s.getCoalitions(),s.getAgents(),offersByCoalitionId,offersByAgentIndex);
        }
    }
}
