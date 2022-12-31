#ifndef SELECTIONPOLICY_H
#define SELECTIONPOLICY_H
#include "Simulation.h"
#include "Parser.h"

class SelectionPolicy { 
    public:
    virtual ~SelectionPolicy();
    virtual void select(Graph& graph, Agent& agent) = 0;
    virtual SelectionPolicy *create() const =0;
    virtual SelectionPolicy *clone() const=0;

};

class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
    MandatesSelectionPolicy();
    MandatesSelectionPolicy(const MandatesSelectionPolicy &other);
    ~MandatesSelectionPolicy();
    MandatesSelectionPolicy *create() const;
    MandatesSelectionPolicy *clone() const;
    void select(Graph& graph, Agent& agent);
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
    EdgeWeightSelectionPolicy();
    ~EdgeWeightSelectionPolicy();
    EdgeWeightSelectionPolicy(const EdgeWeightSelectionPolicy &other);
    EdgeWeightSelectionPolicy *create() const;
    EdgeWeightSelectionPolicy *clone() const;
    void select(Graph& graph, Agent& agent);
};
#endif