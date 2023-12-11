# LocalStorageModule - Local Storage Module

## Overview

The `LocalStorageModule` is a component of the R-Type project designed to handle local storage operations, including reading from and writing to files. It uses the C++ standard library and includes functionality for basic file operations, such as writing content to a file, reading content from a file, and retrieving specific lines from a file.

## Structure Explanation

### `LocalStorageModule` Class

```cpp
class LocalStorageModule {
public:
    LocalStorageModule();
    ~LocalStorageModule();

    void writeToFile(const std::string& filename, const std::string& content);
    std::string readFromFile(const std::string& filename);
    std::string readFromFile(const std::string& filename, const std::string& contains);
    std::string getFirstLineFromFile(const std::string& filename);
    std::string getLineFromFile(const std::string& filename, int line);
    std::string getLineFromFile(const std::string& filename, const std::string& contains);

protected:
private:
};
```

#### Public Methods

- **Constructor and Destructor**:
  - `LocalStorageModule()`: Constructor for initializing the `LocalStorageModule`.
  - `~LocalStorageModule()`: Destructor for cleanup.

- `void writeToFile(const std::string& filename, const std::string& content)`: Method to write content to a file.

- `std::string readFromFile(const std::string& filename)`: Method to read content from a file.

- `std::string readFromFile(const std::string& filename, const std::string& contains)`: Method to read lines from a file that contain a specified string.

- `std::string getFirstLineFromFile(const std::string& filename)`: Method to get the first line of a file.

- `std::string getLineFromFile(const std::string& filename, int line)`: Method to get a specific line from a file.

- `std::string getLineFromFile(const std::string& filename, const std::string& contains)`: Method to get the first line from a file that contains a specified string.

## Usage

To use the `LocalStorageModule` in your R-Type project, create an instance of the class. Use the provided methods to perform local storage operations such as writing to and reading from files. These methods offer flexibility for various file-related tasks, making the module a versatile component for handling local data storage.