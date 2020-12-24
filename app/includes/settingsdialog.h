#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QMessageBox>

#include "settings.h"
#include "settingspresenter.h"

namespace Ui
{
    class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    SettingsDialog(QWidget *parent = nullptr, SettingsPresenter *presenter = nullptr);
    ~SettingsDialog();

private slots:
    void on_chooseFilesButton_clicked();

    void on_saveSettingsButton_clicked();

    void on_clearChoosenFiles_clicked();

signals:
    void sendActualStartDirText(const QString &dir);

private:
    Ui::SettingsDialog *ui;

    Settings settings;
    SettingsPresenter *settingsPresenter;
};

#endif // SETTINGSDIALOG_H
