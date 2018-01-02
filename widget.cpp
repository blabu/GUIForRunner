#include "widget.h"

Widget::Widget(ConnectionInterface* sock, QWidget *parent) :
    QWidget(parent),
    connection(sock),
    ui(new Ui_widget) {
    ui->setupUi(this);
    ui->Search->setVisible(false);
    QObject::connect(ui->InputOutputData,SIGNAL(editTextChanged(QString)),this, SLOT(changeDataInLineEdit(QString)));
    QObject::connect(ui->InputOutputData,SIGNAL(activated(QString)), this, SLOT(enterIsPressed(QString)));
    QObject::connect(this, SIGNAL(pressEnter(QString)),connection, SLOT(writeToDeamonMsg(QString)));
    QObject::connect(this, SIGNAL(changeData(QString)),connection, SLOT(writeToDeamonMsg(QString)));
    QObject::connect(connection, SIGNAL(receiveMessageFromServer(QList<QString>)), this, SLOT(setVariants(QList<QString>)));

}

Widget::~Widget() {
    delete ui;
}

void Widget::setVariants(const QList<QString> &list){
    if(list.isEmpty()) return;
    QString userData = ui->InputOutputData->currentText();
    ui->InputOutputData->clear();
    ui->InputOutputData->addItem(userData);
    for(auto it : list) {
        ui->InputOutputData->addItem(it);
    }
    ui->InputOutputData->showPopup();
}

void Widget::changeDataInLineEdit(const QString &str) {
    if(str.size() < 3) return;
    emit changeData(str);
}

void Widget::enterIsPressed(const QString &str){
    emit pressEnter(str);
}
