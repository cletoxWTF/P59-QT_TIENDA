#include "tienda.h"
#include "ui_tienda.h"

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
    QStringList cabecera = {"Cantidad", "Producto", "Subtotal"};
    ui->outDetalle->setColumnCount(3);
    ui->outDetalle->setHorizontalHeaderLabels(cabecera);

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

