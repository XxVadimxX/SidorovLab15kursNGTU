#ifndef PROCAPP_H
#define PROCAPP_H

struct ProcConfig // струкура, опысывающая заданные параметы(по дефолту)
{
    double coeff; // коэффициент критерия допустимой резкости пика
};

struct ProcApp
{
    ProcConfig procConfig;
};

int procAppRun(ProcApp& app);

#endif // PROCAPP_H
