#ifndef JOUNPOLICY_H
#define JPINPOLICY_H
#include "Simulation.h"

class JoinPolicy {
    public:
    virtual ~JoinPolicy();
    virtual void join(Party& party,std::vector<Coalition> &coalitions,std::vector<Agent> &agents,
    std::vector<int> &offersCoalitionIds, std::vector<int> &offersAgentsIds) = 0;
    virtual JoinPolicy *create () const=0;
    virtual JoinPolicy *clone() const=0;  
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
    ~MandatesJoinPolicy();
    void join(Party& party,std::vector<Coalition> &coalitions,std::vector<Agent> &agents,
    std::vector<int> &offersCoalitionIds, std::vector<int> &offersAgentsIds) ;
    MandatesJoinPolicy();
    MandatesJoinPolicy(const MandatesJoinPolicy &other);
    MandatesJoinPolicy *create () const;
    MandatesJoinPolicy *clone() const;  
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
    ~LastOfferJoinPolicy();
    void join(Party& party,std::vector<Coalition> &coalitions,std::vector<Agent> &agents,
    std::vector<int> &offersCoalitionIds, std::vector<int> &offersAgentsIds) ;
    LastOfferJoinPolicy();
    LastOfferJoinPolicy(const LastOfferJoinPolicy &other);
    LastOfferJoinPolicy *create () const;
    LastOfferJoinPolicy *clone() const;  
};
#endif