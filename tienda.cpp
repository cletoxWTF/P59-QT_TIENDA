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

