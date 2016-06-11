/********************************************************************************
** Form generated from reading UI file 'HeelStats.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEELSTATS_H
#define UI_HEELSTATS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_HeelStats
{
public:
    QAction *actionOpen_Data_Set;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QSlider *verticalSlider;
    QVTKWidget *qvtkWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HeelStats)
    {
        if (HeelStats->objectName().isEmpty())
            HeelStats->setObjectName(QString::fromUtf8("HeelStats"));
        HeelStats->resize(1180, 770);
        actionOpen_Data_Set = new QAction(HeelStats);
        actionOpen_Data_Set->setObjectName(QString::fromUtf8("actionOpen_Data_Set"));
        centralwidget = new QWidget(HeelStats);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(textEdit);


        horizontalLayout->addLayout(verticalLayout);

        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider);

        qvtkWidget = new QVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));

        horizontalLayout->addWidget(qvtkWidget);


        horizontalLayout_2->addLayout(horizontalLayout);

        HeelStats->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HeelStats);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1180, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        HeelStats->setMenuBar(menubar);
        statusbar = new QStatusBar(HeelStats);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HeelStats->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_Data_Set);

        retranslateUi(HeelStats);

        QMetaObject::connectSlotsByName(HeelStats);
    } // setupUi

    void retranslateUi(QMainWindow *HeelStats)
    {
        HeelStats->setWindowTitle(QApplication::translate("HeelStats", "HeelStats", 0, QApplication::UnicodeUTF8));
        actionOpen_Data_Set->setText(QApplication::translate("HeelStats", "Open Data Set", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("HeelStats", "Show Data Set", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("HeelStats", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HeelStats: public Ui_HeelStats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEELSTATS_H
