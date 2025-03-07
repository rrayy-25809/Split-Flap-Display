#include <Python.h>

void control_gpio(const char* state) {
    Py_Initialize();

    // gpio_control.py 모듈 불러오기
    PyObject* pModule = PyImport_ImportModule("gpio_control");
    if (pModule) {
        // control_gpio 함수 가져오기
        PyObject* pFunc = PyObject_GetAttrString(pModule, "control_gpio");
        if (pFunc && PyCallable_Check(pFunc)) {
            // 파라미터 전달하여 함수 호출
            PyObject* pArgs = PyTuple_Pack(1, PyUnicode_FromString(state));
            PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    } else {
        printf("Python 모듈을 불러올 수 없습니다.\n");
    }

    Py_Finalize();
}

int main() {
    control_gpio("on");
    sleep(5);
    control_gpio("off");
    return 0;
}
