#pragma once
#include <string>
#include<Agent.h>

using std::string;

class JoinPolicy;
class Simulation;

//possible party states
enum State 
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    // returns the party's current 
    State getState() const; 

    // sets the party's state
    void setState(State state); 
    
    // returns the party's number of mandates
    int getMandates() const; 
    
    // invokes the party's step
    void step(Simulation &s);  
    
    // returns the party's name
    const string &getName() const; 

    //adds an agent to the end of the agents list
    void addAgent(Agent &agent);

    //returns the number of agents in the party
    const vector<Agent> getAgentsInParty();


private:
    int mId; // party's ID
    string mName; // party's name
    int mMandates; // parties number of mandates
    JoinPolicy *mJoinPolicy; // the party's join policy
    State mState; // represents the current state of the party
    int cooldown; // the cooldown starts to count down the number of iterations from the moment a party recieves an offer 
    vector<Agent> agents; // every party knows it's agents
};
