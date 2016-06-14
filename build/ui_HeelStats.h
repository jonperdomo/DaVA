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
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
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
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer;
    QSlider *verticalSlider;
    QVTKWidget *qvtkWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HeelStats)
    {
        if (HeelStats->objectName().isEmpty())
            HeelStats->setObjectName(QString::fromUtf8("HeelStats"));
        HeelStats->resize(1251, 720);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        HeelStats->setFont(font);
        actionOpen_Data_Set = new QAction(HeelStats);
        actionOpen_Data_Set->setObjectName(QString::fromUtf8("actionOpen_Data_Set"));
        QFont font1;
        actionOpen_Data_Set->setFont(font1);
        centralwidget = new QWidget(HeelStats);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setFont(font);
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
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(pushButton);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setShowGrid(false);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider);

        qvtkWidget = new QVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout->addWidget(qvtkWidget);


        horizontalLayout_2->addLayout(horizontalLayout);

        HeelStats->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HeelStats);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1251, 21));
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
        actionOpen_Data_Set->setText(QApplication::translate("HeelStats", "Load DICOM Set", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("HeelStats", "Render Volume", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("HeelStats", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HeelStats: public Ui_HeelStats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEELSTATS_H
