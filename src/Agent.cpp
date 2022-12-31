
#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy),coalitionId(-1),mState(Active)
{
    // You can change the implementation of the constructor, but not the signature!
}

//-----------------------------------------------------rule of 5-------------------------------------------
//copy constructor
Agent::Agent(const Agent& other)
: mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy->clone()), coalitionId(other.coalitionId),mState(other.mState)
{
}
 //destructor
 Agent::~Agent(){
    clear();
}
 //copy assignment
 Agent& Agent:: operator=(const Agent &other){
    if(this!=&other){
        clear();
        mAgentId=other.mAgentId;
        mPartyId=other.mPartyId;
        mSelectionPolicy=other.mSelectionPolicy->clone();
        coalitionId=other.coalitionId;
        mState=other.mState;
    };
    return *this;
}
 //move constructor
 Agent::Agent(Agent &&other) noexcept
    :mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), coalitionId(other.coalitionId), mState(other.mState)
 {
    other.mSelectionPolicy=nullptr;
 }
 
 //move assignment
Agent& Agent::operator=(Agent &&other)noexcept{
    clear();
    mAgentId=other.mAgentId;
    mPartyId=other.mPartyId;
    mSelectionPolicy=other.mSelectionPolicy;
    coalitionId=other.coalitionId;
    mState=other.mState;
    return *this;
}


//_----------------------------------------------------------------------------
//clone constructor
Agent::Agent(int agentId, int partyId, Agent &other)
    :mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(other.mSelectionPolicy->clone()), coalitionId(other.coalitionId), mState(Active)
{
}
//-----------------------------------------------------------------------
 void Agent::clear(){
     delete mSelectionPolicy;
 }

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::setCoalitionId(int id){
    coalitionId = id;
}

const int Agent::getCoalitionId() const{
    return coalitionId;
}

AgentState &Agent::getAgentState(){
    return mState;
}
void Agent::changeStateToIdle(){
        mState = Idle;
}




void Agent::step(Simulation &sim)
{
    //sim.getGraph(),*this
    mSelectionPolicy->select(sim.getGraph(),*this);
}
