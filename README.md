# Error handling in embedded software with limited resources

This repository presents my thoughts on adding error handling to embedded device applications with limited RAM, and limited display capabilities, but with the ability to communicate the device to the outside world via Bluetooth, WiFi, USB, etc.

Error handling examples are given in C with a test application in Visual Studio 2022. But they can easily be built with any other compiler for any target platform.

Error handling is divided into two parts:
* Error handling during application development.
* Error handling when the application is running for the end user.

## Error handling during application development

The main idea of error handling during development is to create convenient macros for handling critical errors that can be traced back to the moment the device with the software gets to the end user.

## Error handling when the application is running for the end user

The main idea is that all errors that occur during the operation of the application are stored in memory and, upon request, are uploaded to an external device via Bluetooth, WiFi, USB. Further display of errors is carried out on the device to which the errors were uploaded (Mobile App, PC, etc).

Detailed information on the source code can be found on the [Wiki pages](https://github.com/chipsoft/error-handling/wiki).
