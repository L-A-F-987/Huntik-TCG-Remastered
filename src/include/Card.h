#ifndef Card_H_
#define Card_H_
#include <iostream>
#include <string>
#include <stdexcept>
#include "definitions.h"
#include "Good_Card_def.h"

/**
 * @brief Struct storing the conditions of given card
 */
struct Conditions{
    bool Unblockable = false;
    bool Ready = true;
};

/**
 * @brief Struct storing the type of given card
 */
struct Type {
  int primary_type;
  int sub_type;
};

/**
 * @brief Struct storing the attributes of given card
 */
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

/**
 * @brief Class which stores all of the card related variables/states and
 * contains functions to modify them
 */
class Card{

    public:

    // Constructor

    /**
    * @brief Card Costructor
    * @param[in] card_type Type which represents the types associated with card
    * @param[in] name std::string equal to the name of the card
    * @param[in] initial_cardID std::string equal to the cardID the object is
    * initialised with
   * @param[in] initial_PlayerID std::string equal to the PlayerID the object is
    * initialised with
    * @param[in] alignment bool representing the alignment of the card (Good/Evil)
    * @param[in] attack Integer representing the card's default attack
    * @param[in] defence Integer representing the card's default defence
    * @param[in] movement_speed Integer representing the card's default
    * movement_speed default = Default_Speed
    * @param[in] unblockable bool representing if the card is unblockable
    * default = false
    * @param[in] ready bool representing if the card is ready default = true
    */
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

    /**
     * @brief Equality operator used o check if two card objects are the same
     */
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

    /**
     * @brief Getter to get the current attack of a card
     * @return int equal to the current attack value stored in card
     */
    int GetCurrentAttack();

    /**
     * @brief Getter to get the current defence of a card
     * * @return int equal to the current defence value stored in card
     */
    int GetCurrentDefence();

    //Getters base

    /**
     * @brief Getter to get the base attack of a card
     * @return int equal to the base attack value stored in card
     */
    int GetAttack();

    /**
     * @brief Getter to get the base defence of a card
     * @return int equal to the base defence value stored in card
     */
    int GetDefence();

    /**
     * @brief Getter to get the base defence of a card
     * @return int equal to the base defence value stored in card
     */
    std::string GetName();

    // Getters IDs

    /**
     * @brief Getter to get the PlayerID of a card
     * @return std::string equal to the PlayerID stored in card
     */
    std::string GetAssociatedPlayerID();

    /**
     * @brief Getter to get the CardID of a card
     * @return std::string equal to the CardID stored in card
     */
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
