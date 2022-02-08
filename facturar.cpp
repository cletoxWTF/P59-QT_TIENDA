#include "facturar.h"
#include "ui_facturar.h"

Facturar::Facturar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Facturar)
{
    ui->setupUi(this);
}

Facturar::~Facturar()
{
    delete ui;
}


void Facturar::on_btnImprimir_released()
{
    // ABRIR CUADRO DE DIALOGO PARA SELECCIONAR UBICACION Y NOMBRE DEL ARCHIVO
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                         "Guardar Archivo",
                                                         QDir::home().absolutePath(),
                                                         "Archivos de Texto(*.txt)");

    // CREAR UN OBJETO QFILE
    QFile archivo(nombreArchivo);

    //ABRIRLO PARA ESCRITURA
    if(archivo.open(QFile::WriteOnly|QFile::Truncate)){

        // CREAR UN 'STREAM' DE TEXTO
        QTextStream salida(&archivo);

        // ENVIAR LOS DATOS DEL RESULTADO A LA SALIDA
        salida <<ui->outFactura->toPlainText();

    }else{

        //MENSAJE DE ERROR SI NO SE PUEDE ABRIR EL ARCHIVO
        QMessageBox::warning(this,
                             "GUARDAR DATOS",
                             "No se pudo guardar el Archivo");
    }

    // CERRAR ARCHIVO
    archivo.close();
}



Facturar::Facturar(const QString &cedula, const QString &nombre, const QString &telefono, const QString &email, const QString &direccion, const QString &subtotal, const QString &lista) : m_cedula(cedula),
    m_nombre(nombre),
    m_telefono(telefono),
    m_email(email),
    m_direccion(direccion),
    m_subtotal(subtotal),
    m_lista(lista)
{}
