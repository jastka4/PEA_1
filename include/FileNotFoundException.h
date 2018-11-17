//
// Created by jskalska on 12/11/2018.
//

#pragma once
#include <stdexcept>

class FileNotFoundException :
        public std::runtime_error
{
    const char* file;
public:
    FileNotFoundException(const char* msg, const char* _file): runtime_error(msg),
                                                               file(_file) {}

    const char* getFile() const
    {
        return file;
    }
};
