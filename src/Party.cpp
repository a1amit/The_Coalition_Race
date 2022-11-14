#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), cooldown(3)
{
    // You can change the implementation of the constructor, but not the signature!
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

void Party::addAgent(Agent &agent){
    agents.push_back(agent);
}

const vector<Agent> Party::getAgentsInParty(){
    return agents;
}



void Party::step(Simulation &s)
{
    // TODO: implement this method
    if(mState == CollectingOffers){ // in case the party already received and offer
        cooldown--; // reduces the cooldown by one when step is called
        if(cooldown == 0){ // when cooldown reaches zero the party needs to decide based on it's policy who to join
            // this->mJoinPolicy.join() TODO: implement joinPolicy 
            mState = Joined;
            // we also need to clone the agent and add it to the party
        }
    }
}
