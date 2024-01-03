/*
** EPITECH PROJECT, 2024
** output
** File description:
** Serializer
*/

#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <stdlib.h>

#include <iostream>
#include <vector>

typedef struct entity_s {
        int id;
        float x;
        float y;
} entity_t;

typedef struct game_objects_s {
        entity_t *players;
        int nb_players;
        entity_t *missiles;
        int nb_missiles;
} game_objects_t;

typedef struct serialized_data_s {
        game_objects_t to_add;
        game_objects_t to_update;
} serialized_data_t;

class Serializer {
    public:
        Serializer();
        ~Serializer();

        static std::vector<std::string> split(const std::string& str);

        serialized_data_t serialize(std::vector<std::string> args);

        template<typename T>
        std::string structToBinaryString(const T& data);

        template<typename T>
        T binaryStringToStruct(const std::string& data);

    protected:
        serialized_data_t initSerializedData();
    private:
};

#endif /* !SERIALIZER_HPP_ */
