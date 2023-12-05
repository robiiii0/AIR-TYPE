/*
** EPITECH PROJECT, 2023
** output
** File description:
** CouldNotBindAddressException
*/

#ifndef COULDNOTBINDADDRESSEXCEPTION_HPP_
#define COULDNOTBINDADDRESSEXCEPTION_HPP_

#include <exception>

namespace Engine {
    namespace Network {
        class CouldNotBindAddressException : public std::exception {
            public:
                CouldNotBindAddressException();
                ~CouldNotBindAddressException();

                const char *what() const throw() override;

            protected:
            private:
        };
    };  // namespace Network
};      // namespace Engine

#endif /* !COULDNOTBINDADDRESSEXCEPTION_HPP_ */
