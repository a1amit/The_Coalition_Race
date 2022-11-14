#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    //returns agents' party ID
    int getPartyId() const;

    // returns agents ID
    int getId() const;

    //Perfomrs agents' step
    void step(Simulation &);

private:
    int mAgentId; // agents' ID
    int mPartyId; // agents' party ID
    SelectionPolicy *mSelectionPolicy; // agent's selection policy
};
