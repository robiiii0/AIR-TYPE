/*
** EPITECH PROJECT, 2023
** output
** File description:
** main
*/

#include "NetworkingModule.hpp"

int main(int ac, char **av) {
    try {
        Engine::Network::NetworkingModule networkingModule(4242,
                                                           Engine::Network::UDP,
                                                           10);
        std::cout << "Server started" << std::endl;
        std::thread networkingThread(&Engine::Network::NetworkingModule::run,
                                     &networkingModule);
        int update = 0;
        while (true) {
            int nb = 0;
            nb = networkingModule.getClients().size();
            if (nb > update) {
                std::cout << "CLients update" << std::endl;
                for (auto &client : networkingModule.getClients()) {
                    std::cout << "Client " << client.getId() << std::endl;
                    std::cout << "IP: " << client.getAddress().sin_addr.s_addr << std::endl;
                    std::cout << "Port: " << client.getAddress().sin_port << std::endl;
                    std::cout << "Buffer Content: " << client.getBuffer()->read() << std::endl;
                }
                update = nb;
            }
        }
        networkingThread.join();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
