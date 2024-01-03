/*
** EPITECH PROJECT, 2024
** output
** File description:
** Serializer
*/

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

std::vector<std::string> Serializer::split(const std::string &str) {
    std::vector<std::string> tokens;
    std::string              token;
    for (char c : str) {
        if (c == ' ') {
            if (!token.empty()) {
                tokens.push_back(token);
            }
            token.clear();
        } else {
            token.push_back(c);
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

serialized_data_t Serializer::serialize(std::vector<std::string> args) {
    serialized_data_t data = initSerializedData();

    for (auto arg : args) {
        std::vector<std::string> tokens = split(arg);
        if (tokens.size() != 5) {
            std::cerr << "Serializer: Invalid argument: " << arg << std::endl;
            continue;
        }
        entity_t entity;
        entity.id = std::stoi(tokens[2]);
        entity.x = std::stof(tokens[3]);
        entity.y = std::stof(tokens[4]);
        if (tokens[0] == "add") {
            if (tokens[1] == "player") {
                data.to_add.nb_players++;
                entity_t *players = new entity_t[data.to_add.nb_players];
                for (int i = 0; i < data.to_add.nb_players - 1; i++) {
                    players[i] = data.to_add.players[i];
                }
                players[data.to_add.nb_players - 1] = entity;
                delete[] data.to_add.players;
                data.to_add.players = players;
            } else if (tokens[1] == "missile") {
                data.to_add.nb_missiles++;
                entity_t *missiles = new entity_t[data.to_add.nb_missiles];
                for (int i = 0; i < data.to_add.nb_missiles - 1; i++) {
                    missiles[i] = data.to_add.missiles[i];
                }
                missiles[data.to_add.nb_missiles - 1] = entity;
                delete[] data.to_add.missiles;
                data.to_add.missiles = missiles;
            } else {
                std::cerr << "Serializer: Invalid argument: " << arg
                          << std::endl;
            }
        } else if (tokens[0] == "update") {
            if (tokens[1] == "player") {
                data.to_update.nb_players++;
                entity_t *players = new entity_t[data.to_update.nb_players];
                for (int i = 0; i < data.to_update.nb_players - 1; i++) {
                    players[i] = data.to_update.players[i];
                }
                players[data.to_update.nb_players - 1] = entity;
                delete[] data.to_update.players;
                data.to_update.players = players;
            } else if (tokens[1] == "missile") {
                data.to_update.nb_missiles++;
                entity_t *missiles = new entity_t[data.to_update.nb_missiles];
                for (int i = 0; i < data.to_update.nb_missiles - 1; i++) {
                    missiles[i] = data.to_update.missiles[i];
                }
                missiles[data.to_update.nb_missiles - 1] = entity;
                delete[] data.to_update.missiles;
                data.to_update.missiles = missiles;
            } else {
                std::cerr << "Serializer: Invalid argument: " << arg
                          << std::endl;
            }
        } else {
            std::cerr << "Serializer: Invalid argument: " << arg << std::endl;
        }
    }
    return data;
}

serialized_data_t Serializer::initSerializedData() {
    serialized_data_t data;

    data.to_add.players = new entity_t[0];
    data.to_add.nb_players = 0;
    data.to_add.missiles = new entity_t[0];
    data.to_add.nb_missiles = 0;
    data.to_update.players = new entity_t[0];
    data.to_update.nb_players = 0;
    data.to_update.missiles = new entity_t[0];
    data.to_update.nb_missiles = 0;
    return data;
}

template<typename T>
std::string struct_to_binary_string(const T &data) {
    return std::string(reinterpret_cast<const char *>(&data), sizeof(T));
}

// template<typename T>
serialized_data_t Serializer::binaryStringToStruct(const std::string &data) {
    return *reinterpret_cast<const serialized_data_t *>(data.data());
}

std::string Serializer::serializeToPacket(std::vector<std::string> args) {
    serialized_data_t data = serialize(args);
    std::string packet;

    packet += struct_to_binary_string<serialized_data_t>(data);
    delete[] data.to_add.players;
    delete[] data.to_add.missiles;
    delete[] data.to_update.players;
    delete[] data.to_update.missiles;
    return packet;
}
