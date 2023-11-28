/*
** EPITECH PROJECT, 2023
** output
** File description:
** ClientIdOutOfRangeException
*/

#ifndef CLIENTIDOUTOFRANGEEXCEPTION_HPP_
#define CLIENTIDOUTOFRANGEEXCEPTION_HPP_

#include <exception>

namespace Engine {
    namespace Network {
        class ClientIdOutOfRangeException : public std::exception {
            public:
                ClientIdOutOfRangeException();
                ~ClientIdOutOfRangeException();

                const char *what() const throw() override;

            protected:
            private:
        };
    };  // namespace Network
};      // namespace Engine

#endif /* !CLIENTIDOUTOFRANGEEXCEPTION_HPP_ */
