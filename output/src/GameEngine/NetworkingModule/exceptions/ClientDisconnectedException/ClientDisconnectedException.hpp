/*
** EPITECH PROJECT, 2023
** output
** File description:
** ClientDisconnectedException
*/

#ifndef CLIENTDISCONNECTEDEXCEPTION_HPP_
#define CLIENTDISCONNECTEDEXCEPTION_HPP_

#include <exception>

namespace Engine
{
namespace Network
{
class ClientDisconnectedException : public std::exception {
   public:
    ClientDisconnectedException();
    ~ClientDisconnectedException();

    const char* what() const noexcept override;
};
};  // namespace Network
};  // namespace Engine

#endif /* !CLIENTDISCONNECTEDEXCEPTION_HPP_ */
