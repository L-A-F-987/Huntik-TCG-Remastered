# include "Card_Manager.h"


CardManager::CardManager():
        generator(seed()),
        dist(0, 35)
{};

std::string CardManager::GenerateCardID(){
    int attempts = 0;
    std::string id;
    do{
        if (attempts++ >= max_attepts_id_generation){
            throw std::runtime_error("CardManager: failed to generate unique ID");
        }
        id = CreateRandomID();
    }
    while(usedIDs.find(id) != usedIDs.end());
    usedIDs.insert(id);
    return id;
};

std::string CardManager::CreateRandomID(){

    std::string id = "";

    for(int i =0; i<8; i++){
        id += valid_chars[static_cast<size_t>(dist(generator))];
    }

    return id;
};

int CardManager::GetNCardIds(){
    return static_cast<int>(usedIDs.size());
}