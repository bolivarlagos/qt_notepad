#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include <QtWidgets>

class ViewTab : public QWidget
{
    Q_OBJECT

public:
    ViewTab(QWidget *parent = nullptr);
};

class EditorTab : public QWidget
{
    Q_OBJECT

public:
    EditorTab(QWidget *parent = nullptr);
};

class FontTab : public QWidget
{
    Q_OBJECT

public:
    FontTab(QWidget *parent = nullptr);
};

class PluginsTab : public QWidget
{
    Q_OBJECT

public:
    PluginsTab(QWidget *parent = nullptr);
};


class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    PreferencesDialog(QWidget *parent = nullptr);
};

#endif
