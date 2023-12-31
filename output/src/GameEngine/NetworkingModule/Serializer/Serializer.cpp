/*
** EPITECH PROJECT, 2024
** output
** File description:
** Serializer
*/

#include "Serializer.hpp"

Engine::Network::Serializer::Serializer::Serializer() {}

Engine::Network::Serializer::Serializer::~Serializer() {}

std::vector<std::string> Engine::Network::Serializer::Serializer::split(
    const std::string &str) {
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

Engine::Network::Serializer::serialized_data_t
    Engine::Network::Serializer::Serializer::serialize(
        std::vector<std::string> args) {
    serialized_data_t data = initSerializedData();

    for (auto arg : args) {
        std::vector<std::string> tokens = split(arg);
        if (tokens.size() != 5) {
            std::cerr << "Serializer: Invalid argument: " << arg << std::endl;
            continue;
        }
        entity_t entity;
        entity.id = std::stoi(tokens[2]);
        entity.direction = false;
        entity.x = std::stof(tokens[3]);
        entity.y = std::stof(tokens[4]);
        if (tokens[0] == "add") {
            if (tokens[1] == "player") {
                if (data.to_add.nb_players >= MAX_PLAYERS) {
                    std::cerr << "Serializer: Too many players" << std::endl;
                    continue;
                }
                data.to_add.players[data.to_add.nb_players] = entity;
                data.to_add.nb_players++;
            } else if (tokens[1] == "missile") {
                if (data.to_add.nb_missiles >= MAX_MISSILES) {
                    std::cerr << "Serializer: Too many missiles" << std::endl;
                    continue;
                }
                data.to_add.missiles[data.to_add.nb_missiles] = entity;
                data.to_add.nb_missiles++;
            } else {
                std::cerr << "Serializer: Invalid argument: " << arg
                          << std::endl;
            }
        } else if (tokens[0] == "update") {
            if (tokens[1] == "player") {
                if (data.to_update.nb_players >= MAX_PLAYERS) {
                    std::cerr << "Serializer: Too many players" << std::endl;
                    continue;
                }
                data.to_update.players[data.to_update.nb_players] = entity;
                data.to_update.nb_players++;
            } else if (tokens[1] == "missile") {
                if (data.to_update.nb_missiles >= MAX_MISSILES) {
                    std::cerr << "Serializer: Too many missiles" << std::endl;
                    continue;
                }
                data.to_update.missiles[data.to_update.nb_missiles] = entity;
                data.to_update.nb_missiles++;
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

Engine::Network::Serializer::serialized_data_t
    Engine::Network::Serializer::Serializer::initSerializedData() {
    serialized_data_t data;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        data.to_add.players[i].id = -1;
        data.to_update.players[i].id = -1;
    }
    for (int i = 0; i < MAX_MISSILES; i++) {
        data.to_add.missiles[i].id = -1;
        data.to_update.missiles[i].id = -1;
    }
    data.to_add.nb_players = 0;
    data.to_add.nb_missiles = 0;
    data.to_update.nb_players = 0;
    data.to_update.nb_missiles = 0;
    return data;
}

std::string Engine::Network::Serializer::Serializer::structToBinaryString(
    const Engine::Network::Serializer::serialized_data_t &data) {
    std::string binaryString;
    std::copy(reinterpret_cast<const char *>(&data),
              reinterpret_cast<const char *>(&data) + sizeof(data),
              std::back_inserter(binaryString));
    return binaryString;
}

Engine::Network::Serializer::serialized_data_t
    Engine::Network::Serializer::Serializer::binaryStringToStruct(
        const std::string &data) {
    serialized_data_t serialized_data;
    std::copy(data.begin(), data.end(),
              reinterpret_cast<char *>(&serialized_data));
    return serialized_data;
}

std::string Engine::Network::Serializer::Serializer::serializeToPacket(
    std::vector<std::string> args) {
    serialized_data_t data = serialize(args);
    std::string       packet;

    packet += structToBinaryString(data);
    std::cout << "Sending " << packet.length() << " bytes" << std::endl;
    return packet;
}
