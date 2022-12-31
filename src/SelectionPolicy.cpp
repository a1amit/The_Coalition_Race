#include "SelectionPolicy.h"
//SelectionPolicy-----------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------
SelectionPolicy::~SelectionPolicy(){}

//Mandates SelectionPolicy----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------
void MandatesSelectionPolicy::select(Graph& graph, Agent& agent) {
        int offerToIndex = -1;
        int maxMandates = 0;
        for(int i = 0; i < graph.getNumVertices();i++){// iterates over all the verticies in the graph
             if(((graph.getEdgeWeight(agent.getPartyId(),i)) !=0 && (agent.getAgentState() == Active))){//checks if there's an edge between both parties and if the agent is still active
                    if(((!graph.getParty(i).offerExists(agent.getCoalitionId())) && (graph.getParty(i).getState() != Joined))){ // checks if an offer from this coalition already exists and party is not already a part of a coalition
                        if(graph.getParty(i).getMandates() > maxMandates){
                            maxMandates = graph.getParty(i).getMandates(); // updates the current max mandates
                            offerToIndex = i; //updates the index of the party we are gonna offer to
                        }
                    }
                }
             }  
        if(maxMandates > 0 && offerToIndex != -1){
            Party &partyToOfferTo = graph.getParty(offerToIndex); // gets the party we want to make an offer to
            partyToOfferTo.addOffer(agent.getCoalitionId(),agent.getId()); // we add the coalition id to the offersByCoalition and the agentId to the offersByAgentId
            partyToOfferTo.setState(CollectingOffers);
            } else {
                agent.changeStateToIdle(); // in case we don't have anyone to offer to anymore, changes the agent state to idle
            }
    };
//Virtual constructor idiom
//---------------------------
//constructor
MandatesSelectionPolicy::MandatesSelectionPolicy(){}
//copy constructor
MandatesSelectionPolicy::MandatesSelectionPolicy(const MandatesSelectionPolicy &other){}
//destructor
MandatesSelectionPolicy::~MandatesSelectionPolicy(){}
//virtual constructor
MandatesSelectionPolicy* MandatesSelectionPolicy:: create() const{
    return new MandatesSelectionPolicy();
}
//virtual copy constructor
MandatesSelectionPolicy *MandatesSelectionPolicy:: clone() const{
    return new MandatesSelectionPolicy(*this);
}



//EdgeWeightSelectionPolicy---------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------


    void EdgeWeightSelectionPolicy::select(Graph& graph, Agent& agent) {
        int offerToIndex = -1;
        int heaviestEdge = 0;
        for(int i = 0; i < graph.getNumVertices();i++){
            int currentEdgeWeight = graph.getEdgeWeight(agent.getPartyId(),i);
            if(((currentEdgeWeight != 0) && (agent.getAgentState() == Active))){ // in case there's an edge between both verticies edge[Agents.PartyId][i_th vertex] and the agent is still active
                if(((!graph.getParty(i).offerExists(agent.getCoalitionId())) && (graph.getParty(i).getState() != Joined))){ // checks if an offer from this coalition already exists
                    if(currentEdgeWeight > heaviestEdge){ // if this potential party has more mandates then what we found so far
                        heaviestEdge = currentEdgeWeight;
                        offerToIndex = i;
                    }
                }  
            }
        }
        if(heaviestEdge > 0 && offerToIndex != -1){
            Party &partyToOfferTo = graph.getParty(offerToIndex); // gets the party we want to make an offer to
            partyToOfferTo.addOffer(agent.getCoalitionId(),agent.getId());; // we add the coalition id to the party offers vector
            partyToOfferTo.setState(CollectingOffers); // changes the party state to Collecting Offers
        } else {
            agent.changeStateToIdle();
        }
    }
    //Virtual constructor idiom
//---------------------------
//constructor
EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){}
//copy constructor
EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(const EdgeWeightSelectionPolicy &other){}
//destructor
EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy(){}
//virtual constructor
EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy:: create() const{
    return new EdgeWeightSelectionPolicy();
}
//virtual copy constructor
EdgeWeightSelectionPolicy *EdgeWeightSelectionPolicy:: clone() const{
    return new EdgeWeightSelectionPolicy(*this);
}