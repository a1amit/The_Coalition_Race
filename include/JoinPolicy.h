#pragma once

class JoinPolicy {

public:
    virtual void join() = 0; // the abstract join operation that will be later overriden by MandatesJoinPolicy and LastOfferJoinPolicy
};

class MandatesJoinPolicy : public JoinPolicy {};

class LastOfferJoinPolicy : public JoinPolicy {};