#include "tienda.h"
#include "ui_tienda.h"
#include <QDebug>

Tienda::Tienda(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tienda)
{
    ui->setupUi(this);
    // LISTA DE PRODUCOS
    cargarProductos();
    // MOSTRAR LOS PRODUCTOS EN EL COMBO
    foreach (Producto *p, m_productos) {
        ui->inProducto->addItem(p->nombre());
    }
    //CONFIGURAR LA CABECERA DE LA TABLA
    QStringList cabecera = {"Cantidad", "Producto","P. Unitario", "Subtotal"};
    ui->outDetalle->setColumnCount(4);
    ui->outDetalle->setHorizontalHeaderLabels(cabecera);

    // ESTABLECER EL SUBTOTAL A 0
    m_subtotal = 0;
}

Tienda::~Tienda()
{
    delete ui;
}
/**
 * @brief Tienda::cargarProductos CARGA LA LISTA DE PRODUCTOS A LA TIENDA
 */

void Tienda::cargarProductos()
{
    // CREAR PRODUCTOS QUEMADOS EN EL CODIGO
    m_productos.append(new Producto(1,"Leche",0.80));
    m_productos.append(new Producto(2,"Pan",0.15));
    m_productos.append(new Producto(3,"Queso",2.50));
}

void Tienda::calcular(float stProducto)
{

    // CALCULAR VALORES
    m_subtotal += stProducto;
    float iva = m_subtotal * IVA / 100;
    float total = m_subtotal + iva;

    // MOSTRAR VALORES EN GUI
    ui->outSubtotal->setText("$" + QString::number(m_subtotal,'f',2));
    ui->outIVA->setText("$" + QString::number(iva,'f',2));
    ui->outTotal->setText("$" + QString::number(total,'f',2));

}

bool Tienda::verificacion()
{


    QString cedula = ui->inCedula->text();
    QString telefono = ui->inTelefono->text();
    if(cedula.toLongLong()==9999999999){
        return true;
    }else if(cedula.toLongLong()!=9999999999){
        // VERIFICACION DE LA CEDULA
        // VARIABLES PARA CALCULAR SI LA CEDULA ES CORRECTA
        int pares,impares,total,dec=0,fib=0;
        // VARIABLES PARA LEER CADA NUMERO DE LA CEDULA
        long long uno,dos,tre,cua,qui,sei,sie,och,nue,die,vei;
        vei=cedula.toLongLong();
        uno=vei/1000000000;
        vei=vei-(uno*1000000000);
        dos=vei/100000000;
        vei=vei-(dos*100000000);
        tre=vei/10000000;
        vei=vei-(tre*10000000);
        cua=vei/1000000;
        vei=vei-(cua*1000000);
        qui=vei/100000;
        vei=vei-(qui*100000);
        sei=vei/10000;
        vei=vei-(sei*10000);
        sie=vei/1000;
        vei=vei-(sie*1000);
        och=vei/100;
        vei=vei-(och*100);
        nue=vei/10;
        vei=vei-(nue*10);
        die=vei/1;
        vei=vei-(die*1);
        if (vei>2400000000){
            QMessageBox::warning(this,"ADVERTENCIA","El numero de digitos de la cedula es Incorrecto");
            ui->inCedula->setStyleSheet("background-color: 100,58,67");
            return false;
            fib=1;
        }else{
            // CALCULO CON NUMEROS PARES
            pares=dos+cua+sei+och;
            uno=uno*2;
            if (uno>9){
                uno=uno%10+uno/10;
            }
            tre=tre*2;
            if (tre>9){
                tre=tre%10+tre/10;
            }
            qui=qui*2;
            if (qui>9){
                qui=qui%10+qui/10;
            }
            sie=sie*2;
            if (sie>9){
                sie=sie%10+sie/10;
            }
            nue=nue*2;
            if (nue>9){
                nue=nue%10+nue/10;
            }
            // CALCULO CON NUMEROS IMPARES
            impares=uno+tre+qui+sie+nue;
            total=pares+impares;
            // CALCULO PARA DETERMINAR EL ULTIMO DIGITO DE LA CEDULA
            while (dec-total!=die && dec<total+10){
                dec=dec+10;
            }
            if (dec-total==die){
                fib=0;
            }else {
                QMessageBox::warning(this,"ADVERTENCIA","Numero de cedula invalido");
                ui->inCedula->setStyleSheet("background-color: 100,58,67");
                return false;
                fib=1;
            }
        }
        while(fib==1){
            // VARIABLES PARA CALCULAR SI LA CEDULA ES CORRECTA
            int pares,impares,total,dec=0;
            // VARIABLES PARA LEER CADA NUMERO DE LA CEDULA
            long long uno,dos,tre,cua,qui,sei,sie,och,nue,die,tut;
            tut=cedula.toLongLong();
            uno=tut/1000000000;
            tut=tut-(uno*1000000000);
            dos=tut/100000000;
            tut=tut-(dos*100000000);
            tre=tut/10000000;
            tut=tut-(tre*10000000);
            cua=tut/1000000;
            tut=tut-(cua*1000000);
            qui=tut/100000;
            tut=tut-(qui*100000);
            sei=tut/10000;
            tut=tut-(sei*10000);
            sie=tut/1000;
            tut=tut-(sie*1000);
            och=tut/100;
            tut=tut-(och*100);
            nue=tut/10;
            tut=tut-(nue*10);
            die=tut/1;
            tut=tut-(die*1);
            if (tut>2400000000){
                QMessageBox::warning(this,"ADVERTENCIA","El numero de digitos de la cedula es Incorrecto");
                ui->inCedula->setStyleSheet("background-color: 100,58,67");
                return false;
                fib=0;
            }else{
                // CALCULO CON NUMEROS PARES
                pares=dos+cua+sei+och;
                uno=uno*2;
                if (uno>9){
                    uno=uno%10+uno/10;
                }
                tre=tre*2;
                if (tre>9){
                    tre=tre%10+tre/10;
                }
                qui=qui*2;
                if (qui>9){
                    qui=qui%10+qui/10;
                }
                sie=sie*2;
                if (sie>9){
                    sie=sie%10+sie/10;
                }
                nue=nue*2;
                if (nue>9){
                    nue=nue%10+nue/10;
                }
                // CALCULO CON NUMEROS IMPARES
                impares=uno+tre+qui+sie+nue;
                total=pares+impares;
                while (dec-total!=die && dec<total+10){
                    dec=dec+10;
                }
                if (dec-total==die){
                    fib=0;
                }else {
                    QMessageBox::warning(this,"ADVERTENCIA","Numero de cedula invalido");
                    ui->inCedula->setStyleSheet("background-color: 100,58,67");
                    return false;
                    fib=1;
                }
            }
        }

        // VALIDACION NUMERO DE TELEFONO
        if((telefono.toLongLong()>100000000000)||(telefono.toLongLong()<1000000000)){
            QMessageBox::warning(this,"ADVERTENCIA","Numero de telefono incorrecto");
            ui->inCedula->setStyleSheet("background-color: 100,58,67");
            return false;
        }
    }

    return true;

}

bool Tienda::datosCompletos()
{
    QString cedula = ui->inCedula->text();
    QString nombre = ui->inNombre->text();
    QString telefono = ui->inTelefono->text();
    QString email = ui->inEmail->text();
    QString direccion = ui->inDireccion->toPlainText();
    if(cedula.isEmpty()||nombre.isEmpty()||telefono.isEmpty()||email.isEmpty()||direccion.isEmpty()){
        // QString().isempty RETORNA TRUE EN EL CASO DE ESTAR VACIO
        if(cedula.isEmpty()){
            ui->inCedula->setStyleSheet("background-color: 100,58,67");
        }
        if(nombre.isEmpty()){
            ui->inNombre->setStyleSheet("background-color: 100,58,67");
        }
        if(telefono.isEmpty()){
            ui->inTelefono->setStyleSheet("background-color: 100,58,67");
        }
        if(email.isEmpty()){
            ui->inEmail->setStyleSheet("background-color: 100,58,67");
        }
        if(direccion.isEmpty()){
            ui->inDireccion->setStyleSheet("background-color: 100,58,67");
        }
        return false;
    }
    return true;
}

void Tienda::enviarDatos()
{
    //factura->Facturar(ui->inCedula,ui->inNombre,ui->inTelefono,ui->inEmail,ui->inDireccion,m_subtotal,m_listaP);
}

void Tienda::m_lista()
{
    int filas=ui->outDetalle->rowCount(),cont =0;
    QString productos="";
    while(cont!=filas){
        productos+="\t"+ui->outDetalle->item(cont,0)->text()+
                "\t"+ui->outDetalle->item(cont,1)->text()+
                "\t"+ui->outDetalle->item(cont,2)->text()+
                "\t"+ui->outDetalle->item(cont,3)->text()+
                cont++;
    }
    m_listaP=productos;

}


void Tienda::on_inProducto_currentIndexChanged(int index)
{
    // OBTENER EL PRECIO DEL PRODUCTO ACTUAL SELECIONADO
    float precio = m_productos.at(index)->precio();
    // MOSTRAR EL PRECIO DEL PRODUCTO EN LA ETIQUETA
    ui->outPrecio->setText("$ " + QString::number(precio, 'f',2));
    // RESETEAR EL SPIN BOX DE CANTIDAD
    ui->inCantidad->setValue(0);
}


void Tienda::on_btnAgregar_released()
{
    // VALIDAR QUE NO SE AGREGUEN PRODUCTOS CON CERO CANTIDAD
    int cantidad = ui->inCantidad->value();
    if(cantidad == 0){
        return;
    }
    // OBTENER LOS DATOS DE LA GUI
    int i = ui->inProducto->currentIndex();
    Producto *p = m_productos.at(i);

    // CALCULAR EL SUBTOTAL DEL PRODUCTO
    float subtotal = p->precio() * cantidad;

    // AGREGAR LOS DATOS A LA TABLA
    int fila = ui->outDetalle->rowCount();
    ui->outDetalle->insertRow(fila);
    ui->outDetalle->setItem(fila,0, new QTableWidgetItem(QString::number(cantidad)));
    ui->outDetalle->setItem(fila,1, new QTableWidgetItem(p->nombre()));
    ui->outDetalle->setItem(fila,2, new QTableWidgetItem(QString::number(p->precio(),'f',2)));
    ui->outDetalle->setItem(fila,3, new QTableWidgetItem(QString::number(subtotal,'f',2)));

    // LIMPIAR DATOS
    ui->inCantidad->setValue(0);
    ui->inProducto->setFocus();

    // ACTUALIZAR SUBTOTALES
    calcular(subtotal);


}


void Tienda::on_btnFacturar_released()
{
    if((verificacion()==true)&&(datosCompletos()==true)){
        //factura->m_datos.
    }else{
        return;
    }
}

