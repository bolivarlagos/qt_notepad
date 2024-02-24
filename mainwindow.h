#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void aboutWindow();
    void newFileSlot();
    void preferencesDialog();
    void copyHandler();
    void pasteHandler();
    void cutHandler();
    void boldHandler();
    void italicHandler();
    void underlineHandler();

private:
    void createFilemenu();
    void createHelpmenu();
    void createEditmenu();
    void createToolbar();
    void createFileAction();
    void createOpenAction();
    void createSaveAction();
    void createPrintAction();
    void createCopyAction();
    void createCutAction();
    void createPasteAction();
    void createDoAction();
    void createUndoAction();

    void createBoldAction();
    void createItalicAction();
    void createUnderlineAction();

    void configWindow();
    void configMenubar();
    void createTextEdtion();
    void configUndoRedo();

    QMenuBar *menubar;
    QToolBar *toolbar;

    QMenu *filemenu;
    QMenu *editmenu;
    QMenu *helpmenu;

    QAction *newfileAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *printAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *doAction;
    QAction *undoAction;

    QAction *boldAction;
    QAction *italicAction;
    QAction *underlineAction;

    QTextEdit *textEdit;
};

#endif
