#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <iostream>
#include <QDebug>
#include <QApplication>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup defaults
    ui->Acro_radioButton->setChecked(true);
    ui->AcroWingNormal_radioButton->setChecked(true);
    ui->AcroTailNormal_radioButton->setChecked(true);

    ui->Acro_TC_Inhibit_radioButton->setChecked(true);
    ui->acroTabs->show();
    ui->heliTabs->hide();

    // Add items to Combo Boxes
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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveAs_pushButton_clicked()
{
    QString suffix = ".SPM";

    if(ui->loadFilenameLine->text() == "") {
        QFileDialog d(this);
        saveFilename = d.getSaveFileName(this, tr("Save As"), ".", tr("SPM Files (*.SPM)"));

        // check if the filename has an extension.  If not, add the default
        QFileInfo file(saveFilename);
        if(file.suffix().isEmpty()) saveFilename += suffix ;

    } else {
        saveFilename = ui->loadFilenameLine->text();
    }

    QFileInfo file(saveFilename);
    if(file.exists()) {

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Save File", "Are you sure you want to overwrite this file",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
          qDebug() << "Overwritting file";
        } else {
          qDebug() << "Save Cancelled";
        }
    }

    qDebug()<< QObject::tr("Save filename ->") << saveFilename << endl;
}

void MainWindow::on_loadFile_pushButton_clicked()
{
    QFileDialog d(this);
    loadFilename = d.getOpenFileName(this,tr("Load File"),".",tr("SPM Files (*.SPM);;All Files (*.*)"));

    qDebug()<< QObject::tr("Load filename ->") << loadFilename << endl;

    ui->loadFilenameLine->setText(loadFilename);

    loadFile();
}

void MainWindow::on_Acro_radioButton_clicked()
{
    if(ui->Acro_radioButton->isChecked()) {
        ui->acroTabs->show();
        ui->heliTabs->hide();
    }
}

void MainWindow::on_Heli_radioButton_clicked()
{
    if(ui->Heli_radioButton->isChecked()) {
        ui->acroTabs->hide();
        ui->heliTabs->show();
    }
}

void MainWindow::loadFile()
{

    QFile file(loadFilename);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    // read the first line to verify the file is a Spektrum SPM file
    QString line = readLine((QFile *)&file);

    if(line != "<Spektrum>") {
        QMessageBox::information(0, "Error", "Not a Spektrum SPM file");
        qDebug() << line << endl;
    } else {
        qDebug() << "Good file (" << line << ")" << endl;
    }


//    <Spektrum>
//    Generator="DX7S"
//    VCode=" 1.03"
//    ; Originator="HH207XBg8GjzszBaoD9++ZrSV9qMN/"
//    PosIndex= 5
//    Type=Acro
//    curveIndex= 7
//    Name="Acro"
//    </Spektrum>

    while((line = readLine(&file)) != "</Spektrum>") {
        line = line.remove(QRegularExpression("[\"]"));

        QStringList lineList = line.split("=");
        lineList.replaceInStrings(QRegExp("^\\s+|\\s+$"), "");

        if(lineList.at(0) == "PosIndex") {
            QString var = lineList.at(1);
            var = var.remove(QRegularExpression("[\"]"));
            int iVar = var.toInt();
            ui->ModelNumbercomboBox->setCurrentIndex(iVar);
        }
        else if(lineList.at(0) == "Type") {
            if(lineList.at(1) == "Acro") {
                ui->Acro_radioButton->setChecked(true);
                ui->Heli_radioButton->setChecked(false);
                ui->acroTabs->show();
                ui->heliTabs->hide();
            } else if(lineList.at(1) == "Heli") {
                ui->Acro_radioButton->setChecked(false);
                ui->Heli_radioButton->setChecked(true);
                ui->acroTabs->hide();
                ui->heliTabs->show();
            }

        }
        else if(lineList.at(0) == "curveIndex") {

        }
        else if(lineList.at(0) == "Name") {
            ui->ModelName_lineEdit->setText(lineList.at(1));
        }
    }

}

QString MainWindow::readLine(QFile *file) {

    QByteArray oneLine;

    while (!file->atEnd()) {
        QByteArray readChar = file->read(1);
        if (readChar == "\r") {
            break;
        } else {
            oneLine.append(readChar);
        }
    }
    return(oneLine);

}
