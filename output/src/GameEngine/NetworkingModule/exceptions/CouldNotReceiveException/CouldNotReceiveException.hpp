/*
** EPITECH PROJECT, 2023
** output
** File description:
** CouldNotReceiveException
*/

#ifndef COULDNOTRECEIVEEXCEPTION_HPP_
#define COULDNOTRECEIVEEXCEPTION_HPP_

#include <exception>

namespace Engine
{
namespace Network
{
class CouldNotReceiveException : public std::exception {
   public:
    CouldNotReceiveException();
    ~CouldNotReceiveException();

    const char* what() const noexcept override;
};
};  // namespace Network
};  // namespace Engine

#endif /* !COULDNOTRECEIVEEXCEPTION_HPP_ */
