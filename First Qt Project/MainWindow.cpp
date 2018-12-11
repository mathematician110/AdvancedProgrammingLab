#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), textEdit(new QPlainTextEdit) {
    setCentralWidget(textEdit);

    drawActions();
    drawStatusBar();

    readSettings();

    currentFile = QString();
}

void MainWindow::drawActions() {
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QToolBar *fileToolBar = addToolBar(tr("File"));
    QIcon newIcon = QIcon::fromTheme("document-new");
    QAction *newAction = new QAction(newIcon, tr("&New"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setToolTip(tr("Create a new file"));
    newAction->setStatusTip((tr("Create an empty new file")));
    connect(newAction, &QAction::triggered, this, &MainWindow::newFile);
    fileMenu->addAction(newAction);
    fileToolBar->addAction(newAction);
    // TODO
}

void MainWindow::drawStatusBar() {
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::newFile() {
    // TODO
    QMessageBox msgBox;
    msgBox.setText("New File Action has not been implemented yet!");
    msgBox.setInformativeText("What do you want to do now?");
    msgBox.setStandardButtons(QMessageBox::Abort | QMessageBox::Ignore);
    msgBox.setDefaultButton(QMessageBox::Abort);
    int ret = msgBox.exec();
    switch (ret) {
        case QMessageBox::Abort:
            exit(0);
        case QMessageBox::Ignore:
            printf("%s\n", "User just ignored!");
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    // TODO: Check for unsaved changes
    writeSettings();
}

void MainWindow::writeSettings() {
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometry", saveGeometry());
}

void MainWindow::readSettings() {
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty()) {
        const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
        resize(availableGeometry.width() / 3, availableGeometry.height() / 2);
        move((availableGeometry.width() - width()) / 2, (availableGeometry.height() - height()) / 2);
    } else {
        restoreGeometry(geometry);
    }
}
