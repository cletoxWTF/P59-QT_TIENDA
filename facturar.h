#ifndef FACTURAR_H
#define FACTURAR_H

#include <QDialog>
#include "tienda.h"
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class Facturar;
}

class Facturar : public QDialog
{
    Q_OBJECT

public:
    explicit Facturar(QWidget *parent = nullptr);
    Facturar(const QString &cedula, const QString &nombre, const QString &telefono, const QString &email, const QString &direccion, const QString &subtotal, const QString &lista);
    ~Facturar();

private slots:
    void on_btnImprimir_released();

private:
    Ui::Facturar *ui;
    QString m_cedula;
    QString m_nombre;
    QString m_telefono;
    QString m_email;
    QString m_direccion;
    QString m_subtotal;
    QString m_lista;
    int m_iva=12;



};

#endif // FACTURAR_H
