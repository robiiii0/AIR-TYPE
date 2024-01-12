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

#define MAX_PLAYERS  4
#define MAX_MISSILES 200
#define MAX_ENEMIES 20

namespace Engine {
    namespace Network {
        namespace Serializer {

            typedef struct entity_s {
                    int   id;
                    bool  direction;
                    float x;
                    float y;
            } entity_t;

            typedef struct game_objects_s {
                    entity_t players[MAX_PLAYERS];
                    int      nb_players;
                    entity_t missiles[MAX_MISSILES];
                    int      nb_missiles;
            } game_objects_t;

            typedef struct serialized_data_s {
                    // game_objects_t to_add;
                    // game_objects_t to_update;
                    entity_t players[MAX_PLAYERS];
                    entity_t missiles[MAX_MISSILES];
                    entity_t enemies[MAX_ENEMIES];
            } serialized_data_t;

            class Serializer {
                public:
                    Serializer();
                    ~Serializer();

                    static std::vector<std::string> split(
                        const std::string& str);

                    serialized_data_t serialize(std::vector<std::string> args);

                    std::string structToBinaryString(
                        const serialized_data_t& data);

                    serialized_data_t binaryStringToStruct(
                        const std::string& data);

                    std::string serializeToPacket(
                        std::vector<std::string> args);

                protected:
                    serialized_data_t initSerializedData();

                private:
            };
        }  // namespace Serializer
    }      // namespace Network
}  // namespace Engine

#endif /* !SERIALIZER_HPP_ */
