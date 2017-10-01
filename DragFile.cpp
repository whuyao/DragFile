#include "DragFile.h"
#include "ui_DragFile.h"
#include <QWidget>
#include <QtGui>
#include <QtCore>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Drag File");
    setWindowIcon(QIcon("./photosurface.icns"));
}

Widget::~Widget()
{
    delete ui;
}
