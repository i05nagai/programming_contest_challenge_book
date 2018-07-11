#pragma once
#include <vector>

namespace pccb {
struct ConscriptionRelation {
    explicit ConscriptionRelation()
    : male(0),
        female(0),
        intimate(0)
    {
    }
    ConscriptionRelation(const int male0, const int female0, const int intimate0)
    : male(male0),
        female(female0),
        intimate(intimate0)
    {
    }
public:
    int male;
    int female;
    int intimate;
};


/**
 * @brief 
 *
 * @param relations
 * @param numMale
 * @param numFemale
 *
 * @return cost to hire.
 */
int conscription(
    const std::vector<ConscriptionRelation>& relations,
    const int numMale,
    const int numFemale);
} // namespace pccb
