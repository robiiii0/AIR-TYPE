# Exceptions - Error Handling for R-Type

## Overview

The "exceptions" directory in the R-Type project contains various exception classes that handle exceptional scenarios during the execution of the program. Each exception class represents a specific error condition.

## Directory Structure

- **ClientDisconnectedException**: Exception for scenarios where a client has disconnected unexpectedly during networking operations.
- **CouldNotAcceptClientException**: Exception for scenarios where the server could not accept a client connection.
- **CouldNotReceiveException**: Exception for scenarios where a networking component could not receive data.
- **ClientIdOutOfRangeException**: Exception for scenarios where a client ID is out of the valid range.
- **CouldNotBindAddressException**: Exception for scenarios where binding an address fails.
- **CouldNotSendException**: Exception for scenarios where sending data fails.
- **SocketNotCreatedException**: Exception for scenarios where creating a socket fails.

- **Readme.md**: This documentation file providing details about the exception classes within the "exceptions" directory. It includes brief descriptions of each exception and their use cases.

## Exception Descriptions

### ClientDisconnectedException

The `ClientDisconnectedException` is thrown when a client disconnects unexpectedly during networking operations.

### CouldNotAcceptClientException

The `CouldNotAcceptClientException` is thrown when the server fails to accept a client connection.

### CouldNotReceiveException

The `CouldNotReceiveException` is thrown when a networking component is unable to receive data.

### ClientIdOutOfRangeException

The `ClientIdOutOfRangeException` is thrown when a client ID is out of the valid range.

### CouldNotBindAddressException

The `CouldNotBindAddressException` is thrown when binding an address fails during networking setup.

### CouldNotSendException

The `CouldNotSendException` is thrown when sending data fails during networking operations.

### SocketNotCreatedException

The `SocketNotCreatedException` is thrown when creating a socket fails.

## Contribution and Exploration

Feel free to explore the source code within each exception class directory and contribute to their development or improvement. If you have any questions or suggestions regarding these exceptions, please don't hesitate to reach out. Your contributions are valuable to the success of the R-Type project. Happy coding!
