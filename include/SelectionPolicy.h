#pragma once

class SelectionPolicy { 
    virtual void select() = 0; // the abstract join operation that will be later overriden by MandatesSelectionPolicy and EdgeWeightSelectionPolicy
};

class MandatesSelectionPolicy: public SelectionPolicy{ }; // will throw an exception till implemented

class EdgeWeightSelectionPolicy: public SelectionPolicy{ }; // will throw an exception till implemented