/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startwindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *startwindow)
    {
        if (startwindow->objectName().isEmpty())
            startwindow->setObjectName(QStringLiteral("startwindow"));
        startwindow->resize(400, 300);
        menuBar = new QMenuBar(startwindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        startwindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(startwindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        startwindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(startwindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        startwindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(startwindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        startwindow->setStatusBar(statusBar);

        retranslateUi(startwindow);

        QMetaObject::connectSlotsByName(startwindow);
    } // setupUi

    void retranslateUi(QMainWindow *startwindow)
    {
        startwindow->setWindowTitle(QApplication::translate("startwindow", "startwindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startwindow: public Ui_startwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
