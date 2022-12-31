#include <string>
#include <vector>
#include "Party.h"

class Coalition{

public:
Coalition(int id);

    //copy Constructor
    Coalition(const Coalition &other);

    //copy assignment operator
    Coalition &operator=(const Coalition &other);

    //destructor
    ~Coalition();

// returns the num of mandates the coalition has
const int getMandates() const;

// returns the coalition parties vector
std::vector<int> &getParties();

// adds a new Party to the coalition using party reference
void addPartyToCoalition(Party &party);

int getId() const;

private:
int mId; // represents the id of the coalition and also it's placement in the main coalition vector(added to improve search time)
int mandates;
std::vector<int> parties;
};