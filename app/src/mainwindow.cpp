#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "Analizer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      settingsPresenter(new SettingsPresenter(settings))
{
    ui->setupUi(this);
    settingsWindow = new SettingsDialog(this, settingsPresenter);
    settingsWindow->setModal(true);

    setWindowTitle("ClusterProg");
    ui->statusbar->showMessage("TreePlusOne, 2020");

    hideMsgTextLabels();

    //CONNECTS
    QObject::connect(this->settingsWindow, &SettingsDialog::sendActualStartDirText, this, &MainWindow::setActualStartDirText);
}

MainWindow::~MainWindow()
{
    delete settingsWindow;
    delete settingsPresenter;
    delete ui;
}

void MainWindow::on_chooseDirButton_clicked()
{
    settings = settingsPresenter->setStartDirFromFileDialog();
    if (settings.startDir == Settings::DEFAULT_DIR)
        return;
    ui->chooseDirLabel->setText(settings.startDir);
}

void MainWindow::on_InfoButton_clicked()
{
    showAboutProgramInfoMsg();
}

void MainWindow::on_settingsButton_clicked()
{
    settingsWindow->show();
}

void MainWindow::on_runButton_clicked()
{
    if (!settingsPresenter->isValidSettings())
    {
        showNoSettingsWarningMsg();
        return;
    }

    bool ok;
    int clusterCount = settingsPresenter->getClusterCountFromDialog(this, ok);
    if (!ok)
        return;

    settings = settingsPresenter->setClusterCount(clusterCount);

    ui->statusbar->showMessage("Processing");

    int res = settingsPresenter->useAnalizer();
    if (res < 0)
    {
        ui->statusbar->showMessage("ERROR");
        showClusteringErrorCriticalMsg();
        ui->statusbar->showMessage("TreePlusOne, 2020");
        return;
    }
    ui->statusbar->showMessage("TreePlusOne, 2020");
    showSuccessInfoMsg();
}

void MainWindow::setActualStartDirText(const QString &dir)
{
    ui->chooseDirLabel->setText(dir);
}

void MainWindow::showNoSettingsWarningMsg()
{
    QString msg = ui->hiddenNoSettingsTextLabel->text();
    QMessageBox::warning(this, "Set settings", msg);
}

void MainWindow::showAboutProgramInfoMsg()
{
    QString msg = ui->hiddenInfoTextLabel->text();
    QMessageBox::information(this, "Info Message", msg);
}

void MainWindow::showClusteringErrorCriticalMsg()
{
    QMessageBox::critical(this, "Problems",
                          "Something goes wrong");
}

void MainWindow::showSuccessInfoMsg()
{
    QString msg = ui->hiddenSuccessTextLabel->text();
    QMessageBox::information(this, "Done", msg);
}

void MainWindow::hideMsgTextLabels()
{
    ui->hiddenInfoTextLabel->hide();
    ui->hiddenSuccessTextLabel->hide();
    ui->hiddenNoSettingsTextLabel->hide();
}