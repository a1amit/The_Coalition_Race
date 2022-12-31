#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include "Graph.h"


class SelectionPolicy;

enum AgentState
{
    Active,
    Idle
};


class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

   //------------------------------rule of 5------------------------------
    //copy constructor
    Agent(const Agent &other);
    //destructor
    ~Agent();
    //copy assignment
    Agent &operator=(const Agent &other);
    //move constructor
    Agent(Agent &&other) noexcept;
    //move assignment
    Agent &operator=(Agent &&other)noexcept;
    
    
    
    //clone constructor
    Agent(int agentId, int partyId, Agent &other);

    //returns agents' party ID
    int getPartyId() const;

    // returns agents ID
    int getId() const;

    //Perfomrs agents' step
    void step(Simulation &);

    //sets the coalition Id
    //if coalitionId = -1, the party doesn't belong to any coalitions
    void setCoalitionId(int coalitionId);

     // returns the coalition Id
    const int getCoalitionId() const;

    void changeStateToIdle();
   

    //returns the Agent's state: Active/Idle
    AgentState &getAgentState();



private:
    void clear();

    int mAgentId; // agents' ID
    int mPartyId; // agents' party ID
    SelectionPolicy *mSelectionPolicy; // agent's selection policy
    int coalitionId; // the Index of the coalition the agent belongs to
    AgentState mState; // agents Active/Idle State
};
#endif