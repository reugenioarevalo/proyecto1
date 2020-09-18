#ifndef FUN_FECHA_H_INCLUDED
#define FUN_FECHA_H_INCLUDED
 ///PROTOTIPOS
fecha cargarFecha();
void mostrarFecha(fecha);

///FIN PROTOTIPOS

fecha cargarFecha(){
    fecha reg;
    cout<<"DIA: ";
    cin>>reg.dia;
    cout<<"MES: ";
    cin>>reg.mes;
    cout<<"ANIO: ";
    cin>>reg.anio;
    return reg;
}

void mostrarFecha(fecha reg){
    cout<<reg.dia<<"/"<<reg.mes<<"/"<<reg.anio<<endl;
}


#endif // FUN_FECHA_H_INCLUDED
