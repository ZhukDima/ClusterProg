#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>

#include <QDebug>

#include "settingsdialog.h"
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setChoosenFiles(const QStringList& files);

private slots:
    void on_chooseDirButton_clicked();

    void on_InfoButton_clicked();

    void on_settingsButton_clicked();

    void on_runButton_clicked();

signals:
    void sendStartDir(const QString& dir);

private:
    Ui::MainWindow *ui;
    SettingsDialog* settingsWindow;
    QProgressBar* processProgress;
    Settings settings;
};
#endif // MAINWINDOW_H
