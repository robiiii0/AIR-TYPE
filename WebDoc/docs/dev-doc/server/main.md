# R-type - Server

## Description

The server is a standalone application that can be used to host a game and manage the game, and using the Networking module of game engine.

<b>What type of data is sent between the server and the client ?</b>

<i>The data sent between the server and the client is infos about the game. Go check the RFC protocol right [here](../../../rfc.txt).</i>

<b>What is the server frequency ?</b>

<i>The server frequency is 128Hz.</i>

<b>How data is encoded ?</b>

<i>Data is encoded in base64.</i>

## Dependencies

No dependencies required.

## Supported Platforms
- Linux
- Windows
- MacOS

## Build

```bash
mkdir build
cd build
cmake ..
make
```
