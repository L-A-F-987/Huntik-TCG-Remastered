#include <set>

// Allignment
#define GOOD 0
#define EVIL 1

// Primary Card Types
#define HERO 0
#define SPELL 1
#define ACTION 2

// Hero Types
#define MINOR_HERO 0
#define MAJOR_HERO 1

// ACTION TYPES
#define EXHAUST_ACTION 0
#define FREE_ACTION 1
#define COMBAT_ACTION 2

// Set for all Card Types
std::set<int> VALID_CARD_TYPES = {HERO,SPELL,ACTION};
std::set<int> VALID_HERO_TYPES = {MINOR_HERO,MAJOR_HERO};
std::set<int> VALID_ACTION_TYPES = {EXHAUST_ACTION,FREE_ACTION,COMBAT_ACTION};
//Define Default Card values that are only excepted by specific cards
#define Default_Speed 2

