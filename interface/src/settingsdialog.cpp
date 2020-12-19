#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QDebug>

#include "settings.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    setWindowTitle("Settings");
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::setStartDir(const QString &dir)
{
    startDir = dir;
    qDebug() << startDir;
}

void SettingsDialog::setActualChoosenFiles(const QStringList &files)
{
    choosenFiles = files;
    ui->choosenFiles->clear();
    ui->choosenFiles->addItems(choosenFiles);
    ui->choosenFiles->setStyleSheet("background: #fff;");
}

void SettingsDialog::on_chooseFilesButton_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      "Choose files",
                                                      this->startDir,
                                                      "Text files (*.txt *.md);;XML files (*.xml);; HTML files (*.html)");
    if (files.isEmpty())
        return;

    choosenFiles = files;

    ui->choosenFiles->clear();
    ui->choosenFiles->addItems(choosenFiles);
    ui->choosenFiles->setStyleSheet("background: rgba(245, 189, 189, 0.562); border: 1px solid rgb(126, 18, 18);");
}

void SettingsDialog::on_saveSettingsButton_clicked()
{
    emit sendChoosenFiles(choosenFiles);
    QMessageBox::information(this, "Saved", "Changes are saved");
    ui->choosenFiles->setStyleSheet("background: rgba(189, 245, 208, 0.562); border: 1px solid green;");
}

void SettingsDialog::on_clearChoosenFiles_clicked()
{
    QMessageBox msgBox;
    msgBox.setInformativeText("Do you really want to discard settings?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setDefaultButton(QMessageBox::No);

    int ans = msgBox.exec();

    if (ans == QMessageBox::Yes) {
        choosenFiles.clear();
        ui->choosenFiles->clear();
        ui->choosenFiles->setStyleSheet("background: #fff;");
        emit sendChoosenFiles(choosenFiles);
    }
}
