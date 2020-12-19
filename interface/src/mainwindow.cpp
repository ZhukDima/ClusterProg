#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settingsWindow = new SettingsDialog(this);
    settingsWindow->setModal(true);
    processProgress = new QProgressBar;
    statusBar()->addPermanentWidget(processProgress);
    processProgress->setAlignment(Qt::AlignCenter);
    processProgress->setStyleSheet("color: #178317;"
                                   "background-color: #fff;"
                                   "selection-background-color: #94E494;");
    processProgress->hide();

    //CONNECTS
    QObject::connect(this, &MainWindow::sendStartDir, this->settingsWindow, &SettingsDialog::setStartDir);
    QObject::connect(this->settingsWindow, &SettingsDialog::sendChoosenFiles, this, &MainWindow::setChoosenFiles);

    setWindowTitle("ClusterProg");
    ui->statusbar->showMessage("TreePlusOne, 2020");
}

MainWindow::~MainWindow()
{
    delete settingsWindow;
    delete ui;
}

void MainWindow::setChoosenFiles(const QStringList &files)
{
    settings.choosenFiles = files;
    qDebug() << settings.choosenFiles;
}

void MainWindow::on_chooseDirButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    settings.startDir,
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty()) {
        ui->chooseDirLabel->setText(dir);
        settings.startDir = dir;
    }
}

void MainWindow::on_InfoButton_clicked()
{
    QString msg = "<ol><li>Choose directory</li><li>Choose options if you need</li><li>Push the Start button</li></ol>";
    QMessageBox::information(this, "Info Message", msg);
}

void MainWindow::on_settingsButton_clicked()
{
    emit sendStartDir(settings.startDir);
    settingsWindow->show();
}

void MainWindow::on_runButton_clicked()
{
    qDebug() << "START";
    processProgress->show();
    processProgress->setMaximum(999999999);
    for (unsigned int i = 1; i < 999999999; ++i)
    {
        if (i % 1000 == 0)
            processProgress->setValue(i);
    }
    processProgress->hide();
}
