#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QDesktopWidget>
#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QSettings>
#include <QStatusBar>
#include <QMessageBox>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent=nullptr);

private slots:
    void newFile();
    void closeEvent(QCloseEvent *event=nullptr);

private:
    void drawActions();
    void drawStatusBar();
    void readSettings();
    void writeSettings();

    QPlainTextEdit *textEdit;
    QString currentFile;
};

#endif