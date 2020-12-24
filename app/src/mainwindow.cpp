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
    processProgress = new QProgressBar;
    statusBar()->addPermanentWidget(processProgress);
    processProgress->setAlignment(Qt::AlignCenter);
    processProgress->setStyleSheet("color: #178317;"
                                   "background-color: #fff;"
                                   "selection-background-color: #94E494;");
    processProgress->hide();

    setWindowTitle("ClusterProg");
    ui->statusbar->showMessage("TreePlusOne, 2020");

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
    QString msg = "<ol><li>Choose directory</li>"
                  "<li>Choose settings if you need to</li>"
                  "<li>Push the Start button</li>"
                  "<li>Set Cluster count</li>"
                  "<li>Check the result!</li>"
                  "</ol>";
    QMessageBox::information(this, "Info Message", msg);
}

void MainWindow::on_settingsButton_clicked()
{
    settingsWindow->show();
}

void MainWindow::on_runButton_clicked()
{
    if (!settingsPresenter->isValidSettings())
    {
        QMessageBox::warning(this, "Set settings",
                             "Can't clustering home directory."
                             "\nChoose specific files or another directory."
                             "\nMaybe you just forgot to save the settings");
        return;
    }

    bool ok;
    int clusterCount = settingsPresenter->getClusterCountFromDialog(this, ok);
    if (!ok)
        return;

    settings = settingsPresenter->setClusterCount(clusterCount);

    processProgress->show();
    processProgress->setMaximum(999999999);
    for (unsigned int i = 1; i < 999999999; ++i)
    {
        if (i % 1000 == 0)
            processProgress->setValue(i);
    }
    processProgress->hide();

    Analizer analizer;
    analizer.setPathToData(settingsPresenter->getStartDirToOperate());
    analizer.setCountDirectory(settingsPresenter->getClusterCountToOperate());
    analizer.setPathToResult(settingsPresenter->getStartDirToOperate());
    analizer.analize();
}

void MainWindow::setActualStartDirText(const QString &dir)
{
    ui->chooseDirLabel->setText(dir);
}