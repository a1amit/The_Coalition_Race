#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents),coalitions() 
{
    // You can change the implementation of the constructor, but not the signature!
    int coalitionIndex = 0;
    // initializes coalition when a new simulation is created
    for(Agent &agent : mAgents){ // works on the original agents and allows modification
        Coalition *currentCoalition = new Coalition(coalitionIndex); // creates a new coalition
        currentCoalition->addPartyToCoalition(mGraph.getParty(agent.getPartyId())); // adds the party to the newly created coalition
        mGraph.getParty(agent.getPartyId()).setCoalitionId(coalitionIndex); //adds the coalition id to the party
        agent.setCoalitionId(coalitionIndex); // symbolizes that this agent now belongs to the new coalition
        coalitions.push_back(*currentCoalition); // adds the newly created coalition to the coalitions vector
        coalitionIndex++;
        delete currentCoalition; //deletes the pointer to the current coalition but the objects keeps living on the heap
    }
}

void Simulation::step()
{
    // TODO: implement this method
    for(int i = 0; i < mGraph.getNumVertices();i++){ // iterates over all the parties and performs their step
        Party &currentParty = mGraph.getParty(i); // we take the current party reference 
        if(currentParty.getState() != Joined){ // if the party hasn't joined a coalition yet, we perfroms it's step
            currentParty.step(*this);
        } 
    }
    for(Agent &agent : mAgents){ // iterates over all the agents and performs thier step 
        agent.step(*this);
    }
}

bool Simulation::shouldTerminate() const{

    for(unsigned int i=0; i < coalitions.size();i++){ // if there's a coalition with more than 61 mandates we stop
        if (coalitions.at(i).getMandates() >=61)
        {
            return true;
        }
    }
    int numOfjoined = 0;
    int numOfVertices = mGraph.getNumVertices();
    for(int i =0; i < numOfVertices; i++){
        if(mGraph.getParty(i).getState() == Joined){ 
            numOfjoined++;
        }
    }
    if(numOfjoined == numOfVertices){// if all the parites have joined a coalition we stop
        return true;
    }
    return false; // else we continue
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

Graph &Simulation::getGraph(){
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

vector<Agent> &Simulation::getAgents()
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}


//returns the coalition vector
 vector<Coalition> &Simulation::getCoalitions(){
    return coalitions;
 }

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    std::vector<std::vector<int>> returnValue;
    for(Coalition coalition : coalitions){
        returnValue.push_back(coalition.getParties());
    }

    return returnValue;
}
