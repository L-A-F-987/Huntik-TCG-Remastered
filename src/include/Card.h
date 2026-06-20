#ifndef Card_H_
#define Card_H_
#include <iostream>
#include <string>
#include <stdexcept>
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
    // Base values
    int Base_Attack = 0;
    int Base_Defence = 0;
    int Base_Movement_Speed = Default_Speed;

    // Current values
    int Attack = 0;
    int Defence = 0;
    int Movement_Speed = Default_Speed;
};

class Card{

    public:

    // Constructor
    Card(Type card_type, std::string name, std::string initial_cardID,
        std::string initial_playerID, bool alignment, int attack = 0,
        int defence = 0, int movement_speed = Default_Speed,
        bool unblockable = false, bool ready = true
        );

    // Anchoring Virtual Destructor
    virtual ~Card() = default;

    // Virtual Methods
    virtual int ExhaustAction();
    virtual int FreeAction();
    virtual int CombatAction();

    // Equality Operator
    bool operator==(const Card& other) const {
        return
            name == other.name &&
            type.primary_type == other.type.primary_type &&
            type.sub_type == other.type.sub_type &&
            attributes.Base_Attack == other.attributes.Base_Attack &&
            attributes.Base_Defence == other.attributes.Base_Defence &&
            attributes.Base_Movement_Speed == other.attributes.Base_Movement_Speed;
    }

    // Getters current
    int GetCurrentAttack();
    int GetCurrentDefence();

    //Getters base
    int GetAttack();
    int GetDefence();
    std::string GetName();

    // Getters IDs
    std::string GetAssociatedPlayerID();
    std::string GetCardID();

    // Public Variables
    bool has_ability = false;

    // Setting type to default to -1 to identify unset types
    Type type = {-1, 0};

    private:

    // Private Variables
    std::string name = "";
    bool allignment;
    Attributes attributes;
    Conditions conditions;

    // IDs associated to this card
    std::string cardID = "";
    std::string playerID = "";

};


#endif
