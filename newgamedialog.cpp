#include "newgamedialog.h"
#include "ui_newgamedialog.h"

NewGameDialog::NewGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameDialog)
{
    qDebug() << "NewGameDialog constructor";
    ui->setupUi(this);
    ui->moreButton->setChecked(true);
    ui->jokerCheckBox->hide();
    ui->jokerLabel->hide();
    ui->cameleonCheckBox->hide();
    ui->cameleonLabel->hide();
    ui->doubleFunCheckBox->hide();
    ui->doubleFunLabel->hide();
    ui->clepsydraCheckBox->hide();
    ui->clepsydraLabel->hide();
    ui->skullCheckBox->hide();
    ui->skullLabel->hide();
    ui->cameleonCheckBox->setChecked(true);
    ui->jokerCheckBox->setChecked(true);
    ui->doubleFunCheckBox->setChecked(true);
    ui->skullCheckBox->setChecked(true);
    ui->clepsydraCheckBox->setChecked(true);
    ui->cameleonLabel->setPixmap(BallKameleon::kameleonPixmap->scaledToHeight(RKULKI*2));
    ui->jokerLabel->setPixmap(BallJoker::jokerPixmap->scaledToHeight(RKULKI*2));
    ui->doubleFunLabel->setPixmap(BallBonus::bonusPixmap->scaledToHeight(RKULKI*2));
    ui->skullLabel->setPixmap(BallSkull::skullPixmap->scaledToHeight(RKULKI*2));
    ui->clepsydraLabel->setPixmap(BallClepsydra::pixmaps[0]->scaledToHeight(RKULKI*2));
    ui->sizeSpinBox->setMaximum(DiagramScene::maximumSizeOfDiagramScene);
    hiddenSize=this->minimumSize();
    this->resize(this->minimumSize());
    connect(ui->moreButton,SIGNAL(toggled(bool)),this,SLOT(myResize(bool)));

    QButtonGroup *buttonGroup1 = new QButtonGroup(this);
    buttonGroup1->addButton(ui->computerButton1);
    buttonGroup1->addButton(ui->humanButton1);
    ui->humanButton1->setChecked(true);
    QButtonGroup *buttonGroup2 = new QButtonGroup(this);
    buttonGroup2->addButton(ui->computerButton2);
    buttonGroup2->addButton(ui->humanButton2);
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}

int NewGameDialog::returnSize() {return ui->sizeSpinBox->value();}
int NewGameDialog::returnColors() {return ui->colorsSpinBox->value();}
int NewGameDialog::returnPercentBonusBalls() {
    if(ui->jokerCheckBox->isChecked()==false &&
            ui->cameleonCheckBox->isChecked()==false &&
            ui->doubleFunCheckBox->isChecked()==false &&
            ui->skullCheckBox->isChecked()==false &&
            ui->clepsydraCheckBox->isChecked()==false) return 0;
    if(ui->bonusBallComboBox->currentText()=="Few") return FEW;
    if(ui->bonusBallComboBox->currentText()=="Normal") return NORMAL;
    if(ui->bonusBallComboBox->currentText()=="Lot") return LOT;
    if(ui->bonusBallComboBox->currentText()=="Enormous") return ENORMOUS;
}
QString NewGameDialog::returnPlayer1Name() {return ui->player1Name->text();}
QString NewGameDialog::returnPlayer2Name() {return ui->player2Name->text();}
Player::type NewGameDialog::returnPlayer1Type() {
    if(ui->computerButton1->isChecked()) return Player::COMPUTER;
    if(ui->humanButton1->isChecked()) return Player::HUMAN;
    return Player::HUMAN;
}
Player::type NewGameDialog::returnPlayer2Type() {
    if(ui->computerButton2->isChecked()) return Player::COMPUTER;
    if(ui->humanButton2->isChecked()) return Player::HUMAN;
    return Player::HUMAN;
}

bool NewGameDialog::isBallType(int type) {
    switch(type) {
    case JOKER_BALL:
        return ui->jokerCheckBox->isChecked();
    case CAMELEON_BALL:
        return ui->cameleonCheckBox->isChecked();
    case SKULL_BALL:
        return ui->skullCheckBox->isChecked();
    case BONUS_BALL:
        return ui->doubleFunCheckBox->isChecked();
    case CLEPSYDRA_BALL:
        return ui->clepsydraCheckBox->isChecked();
    }
}
bool NewGameDialog::isAloneMode() {return ui->aloneModeCheckBox->isChecked();}

void NewGameDialog::myResize(bool bol)
{
    if(bol==false) return;
    this->setMinimumSize(hiddenSize);
    this->resize(this->minimumSize());
}
