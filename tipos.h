#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
struct fecha{
int dia, mes, anio;
};

struct alumno{
    int legajo;
    fecha fechaNacimiento;
    char nombreAlumno[30];///campos
    char apellidoAlumno[30];
    char email[30];
    int codigoCarrera;///(1 a 5)
    bool estado;///true si está activo; false si se le dio la baja
};


#endif // TIPOS_H_INCLUDED
