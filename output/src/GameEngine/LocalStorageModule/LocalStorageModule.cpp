/*
** EPITECH PROJECT, 2023
** output
** File description:
** LocalStorageModule
*/

#include "LocalStorageModule.hpp"

Engine::LocalStorage::LocalStorageModule::LocalStorageModule() {}

Engine::LocalStorage::LocalStorageModule::~LocalStorageModule() {}

void Engine::LocalStorage::LocalStorageModule::writeToFile(
    const std::string& filename, const std::string& content) {
    std::string   final_filename = "./data/" + filename;
    std::ofstream file(final_filename);

    if (!file.is_open()) {
        throw CouldNotOpenFileException();
    }
    file << content << std::endl;
    file.close();
}

std::string Engine::LocalStorage::LocalStorageModule::readFromFile(
    const std::string& filename) {
    std::string   final_filename = "./data/" + filename;
    std::ifstream file(final_filename);
    std::string   content = "";
    std::string   buffer = "";

    if (!file.is_open()) {
        throw CouldNotOpenFileException();
    }
    while (std::getline(file, buffer)) {
        content += buffer + "\n";
    }
    file.close();
    return content;
}

std::string Engine::LocalStorage::LocalStorageModule::readFromFile(
    const std::string& filename, const std::string& contains) {
    std::string   final_filename = "./data/" + filename;
    std::ifstream file(final_filename);
    std::string   content = "";
    std::string   buffer = "";

    if (!file.is_open()) {
        throw CouldNotOpenFileException();
    }
    while (std::getline(file, buffer)) {
        if (buffer.find(contains) != std::string::npos) {
            content += buffer + "\n";
        }
    }
    file.close();
    return content;
}

std::string Engine::LocalStorage::LocalStorageModule::getFirstLineFromFile(
    const std::string& filename) {
    std::string   final_filename = "./data/" + filename;
    std::ifstream file(final_filename);
    std::string   content = "";

    if (!file.is_open()) {
        throw CouldNotOpenFileException();
    }
    std::getline(file, content);
    file.close();
    return content;
}

std::string Engine::LocalStorage::LocalStorageModule::getLineFromFile(
    const std::string& filename, int line) {
    std::string   final_filename = "./data/" + filename;
    std::ifstream file(final_filename);
    std::string   content = "";

    if (!file.is_open()) {
        throw CouldNotOpenFileException();
    }
    for (int i = 0; i < line; i++) {
        std::getline(file, content);
    }
    file.close();
    return content;
}

std::string Engine::LocalStorage::LocalStorageModule::getLineFromFile(
    const std::string& filename, const std::string& contains) {
    std::string   final_filename = "./data/" + filename;
    std::ifstream file(final_filename);
    std::string   content = "";

    if (!file.is_open()) {
        throw CouldNotOpenFileException();
    }
    while (std::getline(file, content)) {
        if (content.find(contains) != std::string::npos) {
            file.close();
            return content;
        }
    }
    file.close();
    return "";
}
