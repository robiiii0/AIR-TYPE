/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** main
*/

#include "../../GameEngine/GameEngine.hpp"
#include "./Game/Client.hpp"

int main() {
    Client client;
    client.setupState();
    
    client.run();
    return 0;
}
