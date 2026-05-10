#ifndef CardManager_H_
#define CardManager_H_
#include <set>
#include <string>
#include <random>

class CardManager{

    public:
        std::string GenerateCardID();
        int GetNCardIds();
        CardManager();

    private:
        // Function to create the 8 char string from random chars
        std::string CreateRandomID();
        std::set<std::string> usedIDs;

        // Random Numbers to create Seed
        std::random_device seed;
        std::mt19937 generator;
        std::uniform_int_distribution<> dist;

        const std::string valid_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        // Number of attempts allowed before timeout
        const int max_attepts_id_generation = 1000;

    };

#endif