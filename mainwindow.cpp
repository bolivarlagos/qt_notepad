#include "mainwindow.h"
#include "preferencesDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createFilemenu();

    createEditmenu();

    createHelpmenu();

    configMenubar();

    createToolbar();

    createTextEdtion();

    configWindow();

    configUndoRedo();
}

MainWindow::~MainWindow() {}

void MainWindow::configWindow()
{
    setWindowTitle("Qedit");
    setMinimumWidth(800);
    setMinimumHeight(600);
}

void MainWindow::createFilemenu()
{
    filemenu = new QMenu;
    filemenu->setTitle("File");

    QAction *preferencesAction = new QAction;
    preferencesAction->setText("Preferences");

    QAction *exitAction = new QAction;
    exitAction->setText("Exit");
    exitAction->setShortcut(QKeySequence::Quit);

    connect(preferencesAction, &QAction::triggered, this, &MainWindow::preferencesDialog);
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    filemenu->addAction(preferencesAction);
    filemenu->addAction(exitAction);
}

void MainWindow::preferencesDialog()
{
    PreferencesDialog dialog;
    dialog.exec();
}

void MainWindow::createEditmenu()
{
    editmenu = new QMenu;
    editmenu->setTitle("Edit");

    QAction *someAction = new QAction;
    someAction->setText("Change Later");

    editmenu->addAction(someAction);
}

void MainWindow::createHelpmenu()
{
    helpmenu = new QMenu;
    helpmenu->setTitle("Help");

    QAction *aboutAction = new QAction;
    aboutAction->setText("About");

    connect(aboutAction, &QAction::triggered, this, &MainWindow::aboutWindow);

    helpmenu->addAction(aboutAction);
}

void MainWindow::configMenubar()
{
    menubar = new QMenuBar;
    menubar->addMenu(filemenu);
    menubar->addMenu(editmenu);
    menubar->addMenu(helpmenu);

    setMenuBar(menubar);
}

void MainWindow::aboutWindow()
{
    QMessageBox::about(this, "Qedit", "Simple text editor");
}

void MainWindow::createToolbar()
{
    toolbar = new QToolBar;

    createFileAction();
    createOpenAction();
    createSaveAction();
    createCopyAction();
    createCutAction();
    createPasteAction();
    createDoAction();
    createUndoAction();
    createBoldAction();
    createItalicAction();
    createUnderlineAction();
    createPrintAction();

    toolbar->addAction(newfileAction);
    toolbar->addAction(openAction);
    toolbar->addAction(saveAction);
    toolbar->addSeparator();
    toolbar->addAction(copyAction);
    toolbar->addAction(cutAction);
    toolbar->addAction(pasteAction);
    toolbar->addSeparator();
    toolbar->addAction(undoAction);
    toolbar->addAction(doAction);
    toolbar->addSeparator();
    toolbar->addAction(boldAction);
    toolbar->addAction(italicAction);
    toolbar->addAction(underlineAction);
    toolbar->addSeparator();
    toolbar->addAction(printAction);

    addToolBar(toolbar);
}

void MainWindow::createFileAction()
{
    const QIcon newfileIcon = QIcon::fromTheme("document-new");

    newfileAction = new QAction;
    newfileAction->setIcon(newfileIcon);

    connect(newfileAction, &QAction::triggered, this, &MainWindow::newFileSlot);
}

void MainWindow::createOpenAction()
{
    const QIcon openIcon = QIcon::fromTheme("document-open");

    openAction = new QAction;
    openAction->setIcon(openIcon);
}

void MainWindow::createSaveAction()
{
    const QIcon saveIcon = QIcon::fromTheme("document-save");

    saveAction = new QAction;
    saveAction->setIcon(saveIcon);
}

void MainWindow::createPrintAction()
{
    const QIcon printIcon = QIcon::fromTheme("document-print");

    printAction = new QAction;
    printAction->setIcon(printIcon);
}

void MainWindow::createCopyAction()
{
    const QIcon copyIcon = QIcon::fromTheme("edit-copy");

    copyAction = new QAction;
    copyAction->setIcon(copyIcon);

    connect(copyAction, &QAction::triggered, this, &MainWindow::copyHandler);
}

void MainWindow::createPasteAction()
{
    const QIcon pasteIcon = QIcon::fromTheme("edit-paste");

    pasteAction = new QAction;
    pasteAction->setIcon(pasteIcon);

    connect(pasteAction, &QAction::triggered, this, &MainWindow::pasteHandler);
}

void MainWindow::createCutAction()
{
    const QIcon cutIcon = QIcon::fromTheme("edit-cut");

    cutAction = new QAction;
    cutAction->setIcon(cutIcon);

    connect(cutAction, &QAction::triggered, this, &MainWindow::cutHandler);
}

void MainWindow::createDoAction()
{
    const QIcon doIcon = QIcon::fromTheme("edit-redo");

    doAction = new QAction;
    doAction->setIcon(doIcon);
}

void MainWindow::createUndoAction()
{
    const QIcon undoIcon = QIcon::fromTheme("edit-undo");

    undoAction = new QAction;
    undoAction->setIcon(undoIcon);
}

void MainWindow::createBoldAction()
{
    const QIcon boldIcon("./images/bold.png");

    boldAction = new QAction;
    boldAction->setIcon(boldIcon);

    connect(boldAction, &QAction::triggered, this, &MainWindow::boldHandler);
}
void MainWindow::createItalicAction()
{
    const QIcon italicIcon("./images/italic.png");

    italicAction = new QAction;
    italicAction->setIcon(italicIcon);

    connect(italicAction, &QAction::triggered, this, &MainWindow::italicHandler);
}
void MainWindow::createUnderlineAction()
{
    const QIcon underlineIcon("./images/underline.png");

    underlineAction = new QAction;
    underlineAction->setIcon(underlineIcon);

    connect(underlineAction, &QAction::triggered, this, &MainWindow::underlineHandler);
}

void MainWindow::createTextEdtion()
{
    textEdit = new QTextEdit;
    textEdit->setEnabled(false);

    setCentralWidget(textEdit);
}

void MainWindow::newFileSlot()
{
    textEdit->setEnabled(true);
    textEdit->setFontWeight(50);
}

void MainWindow::copyHandler()
{
    textEdit->copy();
}

void MainWindow::pasteHandler()
{
    textEdit->paste();
}

void MainWindow::cutHandler()
{
    textEdit->cut();
}

void MainWindow::boldHandler()
{
    if (textEdit->fontWeight() == 50)
    {
        textEdit->setFontWeight(QFont::Bold);
        return;
    }

    textEdit->setFontWeight(QFont::Normal);
}

void MainWindow::italicHandler()
{
    if (textEdit->fontItalic())
    {
        textEdit->setFontItalic(false);
        return;
    }

    textEdit->setFontItalic(true);
}

void MainWindow::underlineHandler()
{
    if (textEdit->fontUnderline())
    {
        textEdit->setFontUnderline(false);
        return;
    }

    textEdit->setFontUnderline(true);
}

void MainWindow::configUndoRedo()
{
    connect(textEdit, &QTextEdit::undoAvailable, undoAction, &QAction::setEnabled);
    connect(undoAction, &QAction::triggered, textEdit, &QTextEdit::undo);

    connect(textEdit, &QTextEdit::redoAvailable, doAction, &QAction::setEnabled);
    connect(doAction, &QAction::triggered, textEdit, &QTextEdit::redo);
}