#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent, SettingsPresenter *_settingsPresenter) : QDialog(parent),
                                                                                         ui(new Ui::SettingsDialog),
                                                                                         settingsPresenter(_settingsPresenter)
{
    ui->setupUi(this);
    setWindowTitle("Settings");
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_chooseFilesButton_clicked()
{
    settings.choosenFiles = settingsPresenter->getChoosenFilesFromFileDialog();

    if (settings.choosenFiles.isEmpty())
        return;

    ui->choosenFiles->clear();
    ui->choosenFiles->addItems(settings.choosenFiles);
    ui->choosenFiles->setStyleSheet("background: rgba(245, 189, 189, 0.562);"
                                    "border: 1px solid rgb(126, 18, 18);");
}

void SettingsDialog::on_saveSettingsButton_clicked()
{
    settingsPresenter->setChoosenFiles(settings.choosenFiles);

    settings = settingsPresenter->updateStartDirIfChoosenFilesFromAnother();

    emit sendActualStartDirText(settings.startDir);

    QMessageBox::information(this, "Saved", "Changes are saved");
    ui->choosenFiles->setStyleSheet("background: rgba(189, 245, 208, 0.562);"
                                    "border: 1px solid green;");
}

void SettingsDialog::on_clearChoosenFiles_clicked()
{
    QMessageBox msgBox;
    msgBox.setInformativeText("Do you really want to discard settings?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setDefaultButton(QMessageBox::No);

    int ans = msgBox.exec();

    if (ans == QMessageBox::Yes)
    {
        settings = settingsPresenter->clearChoosenFiles();
        ui->choosenFiles->clear();
        ui->choosenFiles->setStyleSheet("background: #fff;");
        settings = settingsPresenter->clearChoosenFiles();
    }
}