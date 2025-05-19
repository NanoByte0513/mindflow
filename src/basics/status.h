#pragma once
#include <string>

#define DEF_ENUM_STATUS(name) \
    X(OK) \
    X(FAILED) \
    X(UNINITIALIZED) \
    X(INVALID_ARGUMENT) \
    X(OUT_OF_MEMORY) \
    X(NOT_SUPPORTED) \
    X(TIMEOUT) \
    X(DEVICE_ERROR)

namespace mindflow {
enum class StatusCode_t {
    #define X(name) name,
    DEF_ENUM_STATUS(name)
    #undef X
};

class Status {
public:
    Status(StatusCode_t code) : code_(code) {}

    bool isOk() const { return code_ == StatusCode_t::OK; }

    std::string toString() const {
        #define X(name) case StatusCode_t::name: return #name; // '#' is used to convert macro argument to string
        switch (code_) {
            DEF_ENUM_STATUS(X)
            default: return "UNKNOWN";
        }
        #undef X
    }

    // Operators
    Status& operator=(StatusCode_t code) {
        code_ = code;
        return *this;
    }

    Status& operator=(const Status& other) {
        code_ = other.code_;
        return *this;
    }

    bool operator==(StatusCode_t code) const {
        return code_ == code;
    }

    bool operator!=(StatusCode_t code) const {
        return code_ != code;
    }

    bool operator==(const Status& other) const {
        return code_ == other.code_;
    }

    bool operator!=(const Status& other) const {
        return code_ != other.code_;
    }

    
private:
    StatusCode_t code_;
};

} // namespace mindflow