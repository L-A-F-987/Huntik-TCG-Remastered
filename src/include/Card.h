#ifndef Card_H_
#define Card_H_
#include <iostream>
#include <string>
#include "definitions.h"
#include "Good_Card_def.h"

struct Conditions{
    bool Unblockable = false;
    bool Ready = true;
};

struct Type {
  int primary_type;
  int sub_type;
};

struct Attributes{
    int Movement_Speed = Default_Speed;
    int Attack = 0;
    int Defence = 0;
};

class Card{

    public:

    // Constructor
    Card(Type card_type, std::string name, bool alignment, int attack = 0,
        int defence = 0, int movement_speed = Default_Speed,
        bool unblockable = false, bool ready = true
        );

    // Anchoring Virtual Destructor
    virtual ~Card() = default;

    // Virtual Methods
    virtual int ExhaustAction();
    virtual int FreeAction();
    virtual int CombatAction();

    // Getters
    int GetAttack();
    int GetDefence();
    std::string GetName();

    // Public Variables
    bool has_ability = false;
    // Setting type to by default be 1 larger than highest value
    // card type by default
    Type type = {*(VALID_CARD_TYPES.end()) + 1, 0};

    private:

    // Private Variables
    std::string name = "";
    bool allignment;
    Attributes attributes;
    Conditions conditions;

};


#endif
