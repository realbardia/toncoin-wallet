
isEmpty(TOUCH_ID_SECURE_KEY) {
    TOUCH_ID_SECURE_KEY = $$getenv(TOUCH_ID_SECURE_KEY)
    isEmpty(TOUCH_ID_SECURE_KEY) {
        TOUCH_ID_SECURE_KEY = F33A9156-1FD3-4E4D-9C9D-34123CCC437B
        warning(You use default touchId secure key. Its better to set your own and secure key using TOUCH_ID_SECURE_KEY argument.)
    }
}

DEFINES += TOUCH_ID_SECURE_KEY=\\\"$$TOUCH_ID_SECURE_KEY\\\"
include (core/core.pri)
