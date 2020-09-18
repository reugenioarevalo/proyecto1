#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
///PROTOTIPOS
bool altaAlumno();
bool bajaAlumno();
bool modificarEmailAlumno();
bool listarAlumnos();


alumno cargarAlumno();
void mostrarAlumno(alumno);
void modificarAlumno();
int buscarLegajoAlumno(int legajo);
bool grabarRegistroAlumno(alumno);

alumno leerRegistroAlumno(int pos);///falta hacer
bool modificarRegistroAlumno(alumno alu, int pos);
///FIN PROTOTIPOS
bool bajaAlumno(){
    int legajo, pos;
    alumno alu;
    bool comoAnduvo=true;
    ///buscar registro
    cout<<"INGRESAR LEGAJO DEL ALUMNO A DAR DE BAJA: ";
    cin>>legajo;
    pos=buscarLegajoAlumno(legajo);
    if(pos==-1){
        return false;
    }
    ///leer el registro
    alu=leerRegistroAlumno(pos);
    ///cambiar el campo que identifica la baja
    alu.estado=false;
    ///escribir registro en el archivo
    comoAnduvo=modificarRegistroAlumno(alu, pos);

    return comoAnduvo;
}


bool altaAlumno(){
    int pos;
    bool grabo;
    alumno reg;

    reg=cargarAlumno();
    pos=buscarLegajoAlumno(reg.legajo);
    if(pos!=-1) {   cout<<"EL LEGAJO YA EXISTE"<<endl;
                    return false;
        }
    grabo=grabarRegistroAlumno(reg);
    return grabo;
}

bool grabarRegistroAlumno(alumno reg){
    FILE *p;
    bool grabo;
    p=fopen("alumnos.dat", "ab");
    if(p==NULL){
        return false;
    }
    grabo=fwrite(&reg, sizeof reg, 1,p);
    fclose(p);
    return grabo;
}

bool listarAlumnos(){
    struct alumno alu;
    FILE *p;
    //bool leyo;
    p=fopen("alumnos.dat", "rb");
    if(p==NULL){
        return false;
    }
    while(fread(&alu, sizeof alu, 1,p)==1){
        mostrarAlumno(alu);
    }
    fclose(p);
    return true;
}

struct alumno cargarAlumno(){
    alumno reg;
    cout<<"LEGAJO: ";
    cin>>reg.legajo;
    cout<<"NOMBRE: ";
    cargarCadena(reg.nombreAlumno, 30);
    cout<<"APELLIDO: ";
    cargarCadena(reg.apellidoAlumno, 30);
    cout<<"FECHA DE NACIMIENTO: "<<endl;
    reg.fechaNacimiento=cargarFecha();
    cout<<"EMAIL: ";
    cargarCadena(reg.email, 30);
    cout<<"CODIGO DE CARRERA: ";
    cin>>reg.codigoCarrera;
    reg.estado=true;
    return reg;
}

void mostrarAlumno(alumno reg){
    if(reg.estado==true){
        cout<<endl<<"LEGAJO: ";
        cout<<reg.legajo<<endl;
        cout<<"NOMBRE: ";
        cout<<reg.nombreAlumno<<endl;
        cout<<"APELLIDO: ";
        cout<<reg.apellidoAlumno<<endl;
        cout<<"FECHA DE NACIMIENTO: ";
        mostrarFecha(reg.fechaNacimiento);
        cout<<"EMAIL: ";
        cout<<reg.email<<endl;
        cout<<"CODIGO DE CARRERA: ";
        cout<<reg.codigoCarrera<<endl;
        }
}

void modificarAlumno(){}
/*
void modificarAlumno(alumno *v,int tam){
    int legajo, pos;
    cout<<"INGRESE EL LEGAJO DEL ALUMNO:";
    cin>>legajo;
    pos=buscarLegajoAlumno(legajo);
    if(pos==-1){
        cout<<"NO EXISTE EL LEGAJO"<<endl;
        return;
    }
    modificarCodigoCarrera(&v[pos]);
}

*/

alumno leerRegistroAlumno(int pos){
    FILE *p;
    alumno reg;
    reg.estado=false;
    p=fopen("alumnos.dat", "rb");
    if(p==NULL){
        return reg;
    }
    fseek(p, sizeof reg*pos,0);///SEEK_SET
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

bool modificarRegistroAlumno(alumno alu, int pos){
    FILE *p;
    bool grabo;
    p=fopen("alumnos.dat", "rb+");
    if(p==NULL){
        return false;
    }
    fseek(p, sizeof alu*pos,0);///SEEK_SET
    grabo=fwrite(&alu, sizeof alu, 1, p);
    fclose(p);
    return grabo;
}

int buscarLegajoAlumno(int legajo){
    FILE *p;
    alumno reg;
    int pos=0;
    p=fopen("alumnos.dat", "rb");
    if(p==NULL){
        return -1;
    }
    while(fread(&reg, sizeof reg, 1, p)==1){
        if(reg.legajo==legajo){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}
bool modificarEmailAlumno(){
    int legajo, pos;
    alumno alu;
    bool comoAnduvo=true;
    char email[30];
    ///buscar registro
    cout<<"INGRESAR LEGAJO DEL ALUMNO A MODIFICAR: ";
    cin>>legajo;
    pos=buscarLegajoAlumno(legajo);
    if(pos==-1){
        return false;
    }
    ///leer el registro
    alu=leerRegistroAlumno(pos);
    ///cambiar el valor del campo
    cout<<"INGRESAR EL NUEVO EMAIL: ";
    cargarCadena(email,30);
    strcpy(alu.email,email);
    ///escribir registro en el archivo
    comoAnduvo=modificarRegistroAlumno(alu, pos);

    return comoAnduvo;

    }


#endif // ALUMNO_H_INCLUDED
