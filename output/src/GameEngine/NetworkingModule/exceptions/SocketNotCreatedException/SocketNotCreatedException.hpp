/*
** EPITECH PROJECT, 2023
** output
** File description:
** SocketNotCreatedException
*/

#ifndef SOCKETNOTCREATEDEXCEPTION_HPP_
#define SOCKETNOTCREATEDEXCEPTION_HPP_

#include <stdexcept>

namespace Engine {
    namespace Network {
        class SocketNotCreatedException : public std::exception {
            public:
                SocketNotCreatedException();
                ~SocketNotCreatedException();

                const char *what() const throw() override;

            protected:
            private:
        };
    };  // namespace Network
};      // namespace Engine

#endif /* !SOCKETNOTCREATEDEXCEPTION_HPP_ */
