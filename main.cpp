#include "procapp.h"

int main()
{
    ProcApp app;
    app.procConfig.coeff = 2;
    int ret = procAppRun(app);
    return ret;
}
