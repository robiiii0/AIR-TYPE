/*
** EPITECH PROJECT, 2023
** output
** File description:
** LocalStorageModule
*/

#ifndef LOCALSTORAGEMODULE_HPP_
#define LOCALSTORAGEMODULE_HPP_

#include <fstream>
#include <string>
#include "exceptions/CouldNotOpenFileException/CouldNotOpenFileException.hpp"

namespace Engine
{
namespace LocalStorage
{
class LocalStorageModule {
   public:
    LocalStorageModule();
    ~LocalStorageModule();

    /*
    * @brief Write content to a file
    * @param filename The name of the file to write to
    * @param content The content to write to the file
    */
    void writeToFile(const std::string& filename, const std::string& content);

    /*
    * @brief Read content from a file
    * @param filename The name of the file to read from
    * @return The content of the file
    */
    std::string readFromFile(const std::string& filename);

    /*
    * @brief Read content from a file
    * @param filename The name of the file to read from
    * @param contains The string that the lines should contain
    * @return The lines of the file that contain the string or an empty string
    * if no line contains the string
    */
    std::string readFromFile(const std::string& filename,
                             const std::string& contains);

    /*
    * @brief Get the first line of a file
    * @param filename The name of the file to read from
    * @return The first line of the file
    */
    std::string getFirstLineFromFile(const std::string& filename);

    /*
    * @brief Get a specific line of a file
    * @param filename The name of the file to read from
    * @param line The line to get
    * @return The line of the file
    */
    std::string getLineFromFile(const std::string& filename, int line);

    /*
    * @brief Get a specific line of a file
    * @param filename The name of the file to read from
    * @param contains The string that the line should contain
    * @return The first line of the file that contains the string or an empty
    * string if no line contains the string
    */
    std::string getLineFromFile(const std::string& filename,
                                const std::string& contains);

   protected:
   private:
};
}  // namespace LocalStorage
}  // namespace Engine

#endif /* !LOCALSTORAGEMODULE_HPP_ */
