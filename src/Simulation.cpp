#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
    //init the agents in thier parties
    for(Agent agent : agents ){
        Party currentParty = getParty(agent.getPartyId()); // maybe this is not the most efficeint / right way to do that, need to check, we can also just save ids
        currentParty.addAgent(agent);
    }
}

void Simulation::step()
{
    // TODO: implement this method

    // iterates over all the parties and performs their step
    for(int i = 0; i < mGraph.getNumVertices();i++){ 
        Party currentParty = mGraph.getParty(i); // not sure about this one, maybe we will need to override the get party method
        if(currentParty.getState() != Joined){ // if the party hasn't joined a coalition yet, we perfroms it's step
            currentParty.step(*this);
        } 
    }
    
    // iterates over all the agents and performs thier step 
    for(Agent Agent : mAgents){
        Agent.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}



/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    
    std::vector<std::vector<int>> coalitions; // not sure this is the way to initialize it and delete
    for(int i = 0; i < this->getGraph().getNumVertices(); i++){ // iterates over all the vertices(parties) in the graph
        Party currentParty = getParty(i); // gets the ith party
        std::vector<Agent> currentPartyAgents = currentParty.getAgentsInParty(); // gets the current agents in party
        std::vector<int> currentCoalition; // init a new vector for the current party
        for(int j=0;j<currentPartyAgents.size();j++){
            currentCoalition.push_back(currentPartyAgents[j].getPartyId());
        }
        coalitions.push_back(currentCoalition);
    }
        return coalitions;
}

