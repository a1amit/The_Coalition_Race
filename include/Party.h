#pragma once
#include <string>
#include "vector"

using std::string;

class JoinPolicy;
class Simulation;

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


    //copy Constructor
     Party(const Party &other);

    //copy assignment operator
    Party &operator=(const Party &other);

    //destructor
    ~Party();

    // move constructor
    Party(Party &&other) noexcept;

    //move assignment operator
    Party &operator=(Party &&other)noexcept;
    
    
    // returns the party's current 
    State getState() const;

    // sets the party's state
    void setState(State state);

    // returns the party's number of mandates
    int getMandates() const;

    // invokes the party's step
    void step(Simulation &s);

    // invokes the party's step
    const string &getName() const;

    //returns the partys id
    const int &getId() const;

    //sets the coalition Id
    //if coalitionId = -1, the party doesn't belong to any coalitions
    void setCoalitionId(int coalitionId);

    // returns true if an offer from the coalition was already made and false otherwise
     const bool offerExists(int id) const;

    //gets the coalition Id of the offering agent and the agentId of the offering Agent
    void addOffer(int coalitionId, int agentId);

private:
    void clear();
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int coalitionId;
    int cooldown; // the cooldown starts to count down the number of iterations from the moment a party recieves an offer
    std::vector<int> offersByCoalitionId; // a vector that contains the Agents coalition id that made an offer to this party there's a bijection of Ida between both vectors
    std::vector<int> offersByAgentIndex; // a vector that contains the Agents id of the agents that made an offer to this party
};
