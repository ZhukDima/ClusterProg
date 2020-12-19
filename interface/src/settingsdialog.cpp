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
}

void SettingsDialog::on_SettingsDialog_rejected()
{
    qDebug() << parent();
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
    //qDebug() << choosenFiles;

    ui->choosenFiles->clear();
    ui->choosenFiles->addItems(choosenFiles);
}

void SettingsDialog::on_saveSettingsButton_clicked()
{
    emit sendChoosenFiles(choosenFiles);
    QMessageBox::information(this, "Saved", "Changes are saved");
}
