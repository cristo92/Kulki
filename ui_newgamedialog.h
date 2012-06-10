/********************************************************************************
** Form generated from reading UI file 'newgamedialog.ui'
**
** Created: Sun Jun 10 00:08:18 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAMEDIALOG_H
#define UI_NEWGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewGameDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QSpinBox *sizeSpinBox;
    QLabel *label_5;
    QSpinBox *colorsSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_4;
    QFrame *line_3;
    QCheckBox *aloneModeCheckBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *player1Name;
    QRadioButton *humanButton1;
    QRadioButton *computerButton1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *player2Name;
    QRadioButton *humanButton2;
    QRadioButton *computerButton2;
    QFrame *line;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *bonusBallComboBox;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *moreButton;
    QPushButton *cancelButton;
    QPushButton *okButton;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *jokerCheckBox;
    QLabel *jokerLabel;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *cameleonCheckBox;
    QLabel *cameleonLabel;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *doubleFunCheckBox;
    QLabel *doubleFunLabel;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *skullCheckBox;
    QLabel *skullLabel;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *clepsydraCheckBox;
    QLabel *clepsydraLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *NewGameDialog)
    {
        if (NewGameDialog->objectName().isEmpty())
            NewGameDialog->setObjectName(QString::fromUtf8("NewGameDialog"));
        NewGameDialog->setWindowModality(Qt::NonModal);
        NewGameDialog->setEnabled(true);
        NewGameDialog->resize(456, 415);
        NewGameDialog->setSizeGripEnabled(false);
        NewGameDialog->setModal(true);
        verticalLayout = new QVBoxLayout(NewGameDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_4 = new QLabel(NewGameDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_10->addWidget(label_4);

        sizeSpinBox = new QSpinBox(NewGameDialog);
        sizeSpinBox->setObjectName(QString::fromUtf8("sizeSpinBox"));
        sizeSpinBox->setMinimum(3);
        sizeSpinBox->setMaximum(15);
        sizeSpinBox->setValue(7);

        horizontalLayout_10->addWidget(sizeSpinBox);

        label_5 = new QLabel(NewGameDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_10->addWidget(label_5);

        colorsSpinBox = new QSpinBox(NewGameDialog);
        colorsSpinBox->setObjectName(QString::fromUtf8("colorsSpinBox"));
        colorsSpinBox->setMinimum(3);
        colorsSpinBox->setMaximum(7);
        colorsSpinBox->setValue(5);

        horizontalLayout_10->addWidget(colorsSpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_10);

        line_4 = new QFrame(NewGameDialog);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        line_3 = new QFrame(NewGameDialog);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        aloneModeCheckBox = new QCheckBox(NewGameDialog);
        aloneModeCheckBox->setObjectName(QString::fromUtf8("aloneModeCheckBox"));

        verticalLayout->addWidget(aloneModeCheckBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(NewGameDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        player1Name = new QLineEdit(NewGameDialog);
        player1Name->setObjectName(QString::fromUtf8("player1Name"));

        horizontalLayout->addWidget(player1Name);

        humanButton1 = new QRadioButton(NewGameDialog);
        humanButton1->setObjectName(QString::fromUtf8("humanButton1"));
        humanButton1->setChecked(true);

        horizontalLayout->addWidget(humanButton1);

        computerButton1 = new QRadioButton(NewGameDialog);
        computerButton1->setObjectName(QString::fromUtf8("computerButton1"));

        horizontalLayout->addWidget(computerButton1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(NewGameDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        player2Name = new QLineEdit(NewGameDialog);
        player2Name->setObjectName(QString::fromUtf8("player2Name"));

        horizontalLayout_2->addWidget(player2Name);

        humanButton2 = new QRadioButton(NewGameDialog);
        humanButton2->setObjectName(QString::fromUtf8("humanButton2"));
        humanButton2->setChecked(true);

        horizontalLayout_2->addWidget(humanButton2);

        computerButton2 = new QRadioButton(NewGameDialog);
        computerButton2->setObjectName(QString::fromUtf8("computerButton2"));

        horizontalLayout_2->addWidget(computerButton2);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(NewGameDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        line_2 = new QFrame(NewGameDialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(NewGameDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        bonusBallComboBox = new QComboBox(NewGameDialog);
        bonusBallComboBox->setObjectName(QString::fromUtf8("bonusBallComboBox"));

        horizontalLayout_3->addWidget(bonusBallComboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        moreButton = new QPushButton(NewGameDialog);
        moreButton->setObjectName(QString::fromUtf8("moreButton"));
        moreButton->setCheckable(true);

        horizontalLayout_4->addWidget(moreButton);

        cancelButton = new QPushButton(NewGameDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_4->addWidget(cancelButton);

        okButton = new QPushButton(NewGameDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_4->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        jokerCheckBox = new QCheckBox(NewGameDialog);
        jokerCheckBox->setObjectName(QString::fromUtf8("jokerCheckBox"));

        horizontalLayout_5->addWidget(jokerCheckBox);

        jokerLabel = new QLabel(NewGameDialog);
        jokerLabel->setObjectName(QString::fromUtf8("jokerLabel"));

        horizontalLayout_5->addWidget(jokerLabel);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        cameleonCheckBox = new QCheckBox(NewGameDialog);
        cameleonCheckBox->setObjectName(QString::fromUtf8("cameleonCheckBox"));

        horizontalLayout_6->addWidget(cameleonCheckBox);

        cameleonLabel = new QLabel(NewGameDialog);
        cameleonLabel->setObjectName(QString::fromUtf8("cameleonLabel"));

        horizontalLayout_6->addWidget(cameleonLabel);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        doubleFunCheckBox = new QCheckBox(NewGameDialog);
        doubleFunCheckBox->setObjectName(QString::fromUtf8("doubleFunCheckBox"));

        horizontalLayout_7->addWidget(doubleFunCheckBox);

        doubleFunLabel = new QLabel(NewGameDialog);
        doubleFunLabel->setObjectName(QString::fromUtf8("doubleFunLabel"));

        horizontalLayout_7->addWidget(doubleFunLabel);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        skullCheckBox = new QCheckBox(NewGameDialog);
        skullCheckBox->setObjectName(QString::fromUtf8("skullCheckBox"));

        horizontalLayout_8->addWidget(skullCheckBox);

        skullLabel = new QLabel(NewGameDialog);
        skullLabel->setObjectName(QString::fromUtf8("skullLabel"));

        horizontalLayout_8->addWidget(skullLabel);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        clepsydraCheckBox = new QCheckBox(NewGameDialog);
        clepsydraCheckBox->setObjectName(QString::fromUtf8("clepsydraCheckBox"));

        horizontalLayout_9->addWidget(clepsydraCheckBox);

        clepsydraLabel = new QLabel(NewGameDialog);
        clepsydraLabel->setObjectName(QString::fromUtf8("clepsydraLabel"));

        horizontalLayout_9->addWidget(clepsydraLabel);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(NewGameDialog);
        QObject::connect(aloneModeCheckBox, SIGNAL(toggled(bool)), player2Name, SLOT(setDisabled(bool)));
        QObject::connect(aloneModeCheckBox, SIGNAL(toggled(bool)), computerButton2, SLOT(setDisabled(bool)));
        QObject::connect(aloneModeCheckBox, SIGNAL(toggled(bool)), humanButton2, SLOT(setDisabled(bool)));
        QObject::connect(aloneModeCheckBox, SIGNAL(toggled(bool)), label_2, SLOT(setDisabled(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), jokerCheckBox, SLOT(setHidden(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), jokerLabel, SLOT(setHidden(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), cameleonCheckBox, SLOT(setHidden(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), cameleonLabel, SLOT(setHidden(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), doubleFunCheckBox, SLOT(setHidden(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), doubleFunLabel, SLOT(setHidden(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), skullCheckBox, SLOT(setHidden(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), skullLabel, SLOT(setHidden(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), clepsydraCheckBox, SLOT(setHidden(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), clepsydraLabel, SLOT(setHidden(bool)));
        QObject::connect(okButton, SIGNAL(clicked(bool)), NewGameDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked(bool)), NewGameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewGameDialog);
    } // setupUi

    void retranslateUi(QDialog *NewGameDialog)
    {
        NewGameDialog->setWindowTitle(QApplication::translate("NewGameDialog", "NewGameDialog", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NewGameDialog", "Size", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NewGameDialog", "Colors", 0, QApplication::UnicodeUTF8));
        aloneModeCheckBox->setText(QApplication::translate("NewGameDialog", "Alone Mode", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewGameDialog", "Player 1", 0, QApplication::UnicodeUTF8));
        humanButton1->setText(QApplication::translate("NewGameDialog", "Human", 0, QApplication::UnicodeUTF8));
        computerButton1->setText(QApplication::translate("NewGameDialog", "Computer", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewGameDialog", "Player 2", 0, QApplication::UnicodeUTF8));
        humanButton2->setText(QApplication::translate("NewGameDialog", "Human", 0, QApplication::UnicodeUTF8));
        computerButton2->setText(QApplication::translate("NewGameDialog", "Computer", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NewGameDialog", "Amount of Bonus Balls", 0, QApplication::UnicodeUTF8));
        bonusBallComboBox->clear();
        bonusBallComboBox->insertItems(0, QStringList()
         << QApplication::translate("NewGameDialog", "Few", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewGameDialog", "Normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewGameDialog", "Lot", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewGameDialog", "Enormous", 0, QApplication::UnicodeUTF8)
        );
        moreButton->setText(QApplication::translate("NewGameDialog", "More", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("NewGameDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("NewGameDialog", "OK", 0, QApplication::UnicodeUTF8));
        jokerCheckBox->setText(QApplication::translate("NewGameDialog", "Joker", 0, QApplication::UnicodeUTF8));
        jokerLabel->setText(QString());
        cameleonCheckBox->setText(QApplication::translate("NewGameDialog", "Cameleon", 0, QApplication::UnicodeUTF8));
        cameleonLabel->setText(QString());
        doubleFunCheckBox->setText(QApplication::translate("NewGameDialog", "Double Fun", 0, QApplication::UnicodeUTF8));
        doubleFunLabel->setText(QString());
        skullCheckBox->setText(QApplication::translate("NewGameDialog", "Skull", 0, QApplication::UnicodeUTF8));
        skullLabel->setText(QString());
        clepsydraCheckBox->setText(QApplication::translate("NewGameDialog", "Clepsydra", 0, QApplication::UnicodeUTF8));
        clepsydraLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewGameDialog: public Ui_NewGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAMEDIALOG_H
