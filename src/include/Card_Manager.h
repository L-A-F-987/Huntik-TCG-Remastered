#ifndef CardManager_H_
#define CardManager_H_
#include <set>
#include <string>
#include <random>
#include <stdexcept>

/**
 * @brief Manages all Card objects, adding a card ID and storing them
 *
 * CardManager is primarily used to generate and store card ids for newly
 * generated card objects. This is done to give ach card object a unique
 * identifier.
 *
 */
class CardManager{

    public:

        // Constructor
        CardManager();

        /**
         * @brief Generates a new unique character card ID of length
         * card_id_length
         * @return A unique card ID string, guaranteed not to collide
         *         with any previously generated ID.
         * @throws std::runtime_error if max_attepts_id_generation is
         *         exceeded without finding an unused ID.
         */
        std::string GenerateCardID();

        /**
         * @brief Gets the number of card IDs that are currently stored
         * @return An integer value representing the number of existing card IDs
         */
        int GetNCardIds();

    private:
        /**
         * @brief Creates a random card ID of length card_id_length
         * @return A string representing the generated card ID
         */
        std::string CreateRandomID();

        // set of all existing Ids
        std::set<std::string> usedIDs;

        // Random Numbers to create Seed
        std::random_device seed;
        std::mt19937 generator;
        std::uniform_int_distribution<> dist;

        const std::string valid_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        // Number of attempts allowed before timeout
        const int max_attepts_id_generation = 1000;
        //
        const int card_id_length = 8;

    };

#endif