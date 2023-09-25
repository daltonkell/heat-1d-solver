#ifndef ERROR_CODES_H
#define ERROR_CODES_H

namespace err {
    enum eErrorCode {
        SUCCESS             = 0,
        UNSTABLE_PARAMETERS = 1,
        INVALID_PARAMETERS  = 2,
        BAD_SOLVER_CHOICE   = 3
    };
}

#endif
