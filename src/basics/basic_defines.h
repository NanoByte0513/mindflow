#pragma once

namespace mindflow {
enum class DeviceType {
    CPU = 0,
    CUDA = 1,
    OPENCL = 2,
    HUAWEI_ASCEND = 3,
};

enum class DataType {
    kINT4 = 0,
    kINT8 = 1,
    kINT16 = 2,
    kINT32 = 3,
    kINT64 = 4,
    kUINT4 = 5,
    kUINT8 = 6,
    kUINT16 = 7,
    kUINT32 = 8,
    kUINT64 = 9,
    kFLOAT16 = 10,
    kFLOAT32 = 11,
    kFLOAT64 = 12,
};

enum class DataFormat {
    kNCHW = 0,
    kNHWC = 1,
    kNC4HW4 = 2,
    kNC8HW8 = 3,
    kNCHW_VECT_C = 4,
    kNCHW_VECT_C4 = 5,
    kNCHW_VECT_C8 = 6,
};
}// namespace mindflow