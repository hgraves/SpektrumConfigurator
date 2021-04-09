#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup defaults
    ui->Acro_radioButton->setChecked(true);
    ui->AcroWingNormal_radioButton->setChecked(true);
    ui->AcroTailNormal_radioButton->setChecked(true);

    // Add items to Combo Box
    ui->Acro_Trainer_comboBox->addItem("Inhibit");

    ui->Acro_Flap_comboBox->addItem("Inhibit");
    ui->Acro_Flap_comboBox->addItem("AUX1");

    ui->Acro_Fmode_comboBox->addItem("Inhibit");
    ui->Acro_Fmode_comboBox->addItem("AUX1");

    ui->Acro_Mix_comboBox->addItem("Inhibit");
    ui->Acro_Mix_comboBox->addItem("AUX1");

    ui->Acro_Gear_comboBox->addItem("Inhibit");
    ui->Acro_Gear_comboBox->addItem("Gear");
    ui->Acro_Gear_comboBox->addItem("AUX1");

    ui->Acro_Knob_comboBox->addItem("Inhibit");
    ui->Acro_Knob_comboBox->addItem("Gear");
    ui->Acro_Knob_comboBox->addItem("AUX1");
    ui->Acro_Knob_comboBox->addItem("AUX2");

    ui->ModelNumbercomboBox->addItem("Model 1");
    ui->ModelNumbercomboBox->addItem("Model 2");
    ui->ModelNumbercomboBox->addItem("Model 3");
    ui->ModelNumbercomboBox->addItem("Model 4");
    ui->ModelNumbercomboBox->addItem("Model 5");
    ui->ModelNumbercomboBox->addItem("Model 6");
    ui->ModelNumbercomboBox->addItem("Model 7");
    ui->ModelNumbercomboBox->addItem("Model 8");
    ui->ModelNumbercomboBox->addItem("Model 9");
    ui->ModelNumbercomboBox->addItem("Model 10");
    ui->ModelNumbercomboBox->addItem("Model 11");
    ui->ModelNumbercomboBox->addItem("Model 12");
    ui->ModelNumbercomboBox->addItem("Model 13");
    ui->ModelNumbercomboBox->addItem("Model 14");
    ui->ModelNumbercomboBox->addItem("Model 15");
    ui->ModelNumbercomboBox->addItem("Model 16");
    ui->ModelNumbercomboBox->addItem("Model 17");
    ui->ModelNumbercomboBox->addItem("Model 18");
    ui->ModelNumbercomboBox->addItem("Model 19");
    ui->ModelNumbercomboBox->addItem("Model 20");

    ui->DR_AIL_SW_comboBox->addItem("Inhibit");
    ui->DR_AIL_SW_comboBox->addItem("On");
    ui->DR_AIL_SW_comboBox->addItem("Aile D/R");
    ui->DR_AIL_SW_comboBox->addItem("Elev D/R");
    ui->DR_AIL_SW_comboBox->addItem("Rudd D/R");
    ui->DR_AIL_SW_comboBox->addItem("F Mode");
    ui->DR_AIL_SW_comboBox->addItem("Gear");
    ui->DR_AIL_SW_comboBox->addItem("Mix");
    ui->DR_AIL_SW_comboBox->addItem("Flap");

    ui->DR_ELEV_SW_comboBox->addItem("Inhibit");
    ui->DR_ELEV_SW_comboBox->addItem("On");
    ui->DR_ELEV_SW_comboBox->addItem("Aile D/R");
    ui->DR_ELEV_SW_comboBox->addItem("Elev D/R");
    ui->DR_ELEV_SW_comboBox->addItem("Rudd D/R");
    ui->DR_ELEV_SW_comboBox->addItem("F Mode");
    ui->DR_ELEV_SW_comboBox->addItem("Gear");
    ui->DR_ELEV_SW_comboBox->addItem("Mix");
    ui->DR_ELEV_SW_comboBox->addItem("Flap");

    ui->DR_RUDD_SW_comboBox->addItem("Inhibit");
    ui->DR_RUDD_SW_comboBox->addItem("On");
    ui->DR_RUDD_SW_comboBox->addItem("Aile D/R");
    ui->DR_RUDD_SW_comboBox->addItem("Elev D/R");
    ui->DR_RUDD_SW_comboBox->addItem("Rudd D/R");
    ui->DR_RUDD_SW_comboBox->addItem("F Mode");
    ui->DR_RUDD_SW_comboBox->addItem("Gear");
    ui->DR_RUDD_SW_comboBox->addItem("Mix");
    ui->DR_RUDD_SW_comboBox->addItem("Flap");

    ui->Acro_Mix_Act_Inh1_radioButton->setChecked(true);
    ui->Acro_Mix_Act_Inh2_radioButton->setChecked(true);
    ui->Acro_Mix_Act_Inh3_radioButton->setChecked(true);
    ui->Acro_Mix_Act_Inh4_radioButton->setChecked(true);
    ui->Acro_Mix_Act_Inh5_radioButton->setChecked(true);
    ui->Acro_Mix_Act_Inh6_radioButton->setChecked(true);
    ui->Acro_Mix_Act_Inh7_radioButton->setChecked(true);
    ui->Acro_Mix_Act_Inh8_radioButton->setChecked(true);

    ui->Acro_Mix_EF_comboBox->addItem("Inhibit");
    ui->Acro_Mix_EF_comboBox->addItem("On");
    ui->Acro_Mix_EF_comboBox->addItem("FM1");
    ui->Acro_Mix_EF_comboBox->addItem("Gear0");
    ui->Acro_Mix_EF_comboBox->addItem("Gear1");
    ui->Acro_Mix_EF_comboBox->addItem("Ail D/R");
    ui->Acro_Mix_EF_comboBox->addItem("Ele D/R");
    ui->Acro_Mix_EF_comboBox->addItem("Rud D/R");
    ui->Acro_Mix_EF_comboBox->addItem("Mix0");
    ui->Acro_Mix_EF_comboBox->addItem("Mix1");

    ui->Acro_Mix_AR_comboBox->addItem("Inhibit");
    ui->Acro_Mix_AR_comboBox->addItem("On");
    ui->Acro_Mix_AR_comboBox->addItem("FM1");
    ui->Acro_Mix_AR_comboBox->addItem("Gear0");
    ui->Acro_Mix_AR_comboBox->addItem("Gear1");
    ui->Acro_Mix_AR_comboBox->addItem("Ail D/R");
    ui->Acro_Mix_AR_comboBox->addItem("Ele D/R");
    ui->Acro_Mix_AR_comboBox->addItem("Rud D/R");
    ui->Acro_Mix_AR_comboBox->addItem("Mix0");
    ui->Acro_Mix_AR_comboBox->addItem("Mix1");

    ui->Acro_Mix_M1_comboBox->addItem("Inhibit");
    ui->Acro_Mix_M1_comboBox->addItem("On");
    ui->Acro_Mix_M1_comboBox->addItem("FM1");
    ui->Acro_Mix_M1_comboBox->addItem("Gear0");
    ui->Acro_Mix_M1_comboBox->addItem("Gear1");
    ui->Acro_Mix_M1_comboBox->addItem("Ail D/R");
    ui->Acro_Mix_M1_comboBox->addItem("Ele D/R");
    ui->Acro_Mix_M1_comboBox->addItem("Rud D/R");
    ui->Acro_Mix_M1_comboBox->addItem("Mix0");
    ui->Acro_Mix_M1_comboBox->addItem("Mix1");

    ui->Acro_Mix_M2_comboBox->addItem("Inhibit");
    ui->Acro_Mix_M2_comboBox->addItem("On");
    ui->Acro_Mix_M2_comboBox->addItem("FM1");
    ui->Acro_Mix_M2_comboBox->addItem("Gear0");
    ui->Acro_Mix_M2_comboBox->addItem("Gear1");
    ui->Acro_Mix_M2_comboBox->addItem("Ail D/R");
    ui->Acro_Mix_M2_comboBox->addItem("Ele D/R");
    ui->Acro_Mix_M2_comboBox->addItem("Rud D/R");
    ui->Acro_Mix_M2_comboBox->addItem("Mix0");
    ui->Acro_Mix_M2_comboBox->addItem("Mix1");

    ui->Acro_Mix_M3_comboBox->addItem("Inhibit");
    ui->Acro_Mix_M3_comboBox->addItem("On");
    ui->Acro_Mix_M3_comboBox->addItem("FM1");
    ui->Acro_Mix_M3_comboBox->addItem("Gear0");
    ui->Acro_Mix_M3_comboBox->addItem("Gear1");
    ui->Acro_Mix_M3_comboBox->addItem("Ail D/R");
    ui->Acro_Mix_M3_comboBox->addItem("Ele D/R");
    ui->Acro_Mix_M3_comboBox->addItem("Rud D/R");
    ui->Acro_Mix_M3_comboBox->addItem("Mix0");
    ui->Acro_Mix_M3_comboBox->addItem("Mix1");

    ui->Acro_Mix_M4_comboBox->addItem("Inhibit");
    ui->Acro_Mix_M4_comboBox->addItem("On");
    ui->Acro_Mix_M4_comboBox->addItem("FM1");
    ui->Acro_Mix_M4_comboBox->addItem("Gear0");
    ui->Acro_Mix_M4_comboBox->addItem("Gear1");
    ui->Acro_Mix_M4_comboBox->addItem("Ail D/R");
    ui->Acro_Mix_M4_comboBox->addItem("Ele D/R");
    ui->Acro_Mix_M4_comboBox->addItem("Rud D/R");
    ui->Acro_Mix_M4_comboBox->addItem("Mix0");
    ui->Acro_Mix_M4_comboBox->addItem("Mix1");

    ui->Acro_Mix_M5_comboBox->addItem("Inhibit");
    ui->Acro_Mix_M5_comboBox->addItem("On");
    ui->Acro_Mix_M5_comboBox->addItem("FM1");
    ui->Acro_Mix_M5_comboBox->addItem("Gear0");
    ui->Acro_Mix_M5_comboBox->addItem("Gear1");
    ui->Acro_Mix_M5_comboBox->addItem("Ail D/R");
    ui->Acro_Mix_M5_comboBox->addItem("Ele D/R");
    ui->Acro_Mix_M5_comboBox->addItem("Rud D/R");
    ui->Acro_Mix_M5_comboBox->addItem("Mix0");
    ui->Acro_Mix_M5_comboBox->addItem("Mix1");

    ui->Acro_Mix_M6_comboBox->addItem("Inhibit");
    ui->Acro_Mix_M6_comboBox->addItem("On");
    ui->Acro_Mix_M6_comboBox->addItem("FM1");
    ui->Acro_Mix_M6_comboBox->addItem("Gear0");
    ui->Acro_Mix_M6_comboBox->addItem("Gear1");
    ui->Acro_Mix_M6_comboBox->addItem("Ail D/R");
    ui->Acro_Mix_M6_comboBox->addItem("Ele D/R");
    ui->Acro_Mix_M6_comboBox->addItem("Rud D/R");
    ui->Acro_Mix_M6_comboBox->addItem("Mix0");
    ui->Acro_Mix_M6_comboBox->addItem("Mix1");

    ui->Acro_Diff_comboBox->addItem("Inhibit");
    ui->Acro_Diff_comboBox->addItem("On");
    ui->Acro_Diff_comboBox->addItem("Aile D/R");
    ui->Acro_Diff_comboBox->addItem("Elev D/R");
    ui->Acro_Diff_comboBox->addItem("Rudd D/R");
    ui->Acro_Diff_comboBox->addItem("F Mode");
    ui->Acro_Diff_comboBox->addItem("Flap");
    ui->Acro_Diff_comboBox->addItem("Gear");
    ui->Acro_Diff_comboBox->addItem("Mix");

    ui->Acro_TC_Inhibit_radioButton->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveAs_pushButton_clicked()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Save As",".");

}

void MainWindow::on_loadFile_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Save As",".");


}
