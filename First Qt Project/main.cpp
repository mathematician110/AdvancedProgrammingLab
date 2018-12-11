#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication EditorApp(argc, argv);
    EditorApp.setApplicationName("Simple Editor");
    MainWindow editor;
    editor.show();
    return EditorApp.exec();
}