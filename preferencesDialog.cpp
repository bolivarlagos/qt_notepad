#include "preferencesDialog.h"

ViewTab::ViewTab(QWidget *parent)
    : QWidget(parent)
{
    QCheckBox *lineCheckbox = new QCheckBox;
    lineCheckbox->setText("Display line numbers");
    lineCheckbox->setChecked(true);

    QCheckBox *marginCheckbox = new QCheckBox;
    marginCheckbox->setText("Display right margin");

    QCheckBox *statusCheckbox = new QCheckBox;
    statusCheckbox->setText("Display statusbar");
    statusCheckbox->setChecked(true);

    QCheckBox *overviewCheckbox = new QCheckBox;
    overviewCheckbox->setText("Display overview map");

    QCheckBox *gridCheckbox = new QCheckBox;
    gridCheckbox->setText("Display grid pattern");

    QVBoxLayout *viewLayout = new QVBoxLayout;
    viewLayout->addWidget(lineCheckbox);
    viewLayout->addWidget(marginCheckbox);
    viewLayout->addWidget(statusCheckbox);
    viewLayout->addWidget(overviewCheckbox);
    viewLayout->addWidget(gridCheckbox);

    setLayout(viewLayout);
}

EditorTab::EditorTab(QWidget *parent)
    : QWidget(parent)
{
    QLabel *test = new QLabel;
    test->setText("ok");

    QVBoxLayout *viewLayout = new QVBoxLayout;
    viewLayout->addWidget(test);

    setLayout(viewLayout);
}

FontTab::FontTab(QWidget *parent)
    : QWidget(parent)
{
    QLabel *test = new QLabel;
    test->setText("ok");

    QVBoxLayout *viewLayout = new QVBoxLayout;
    viewLayout->addWidget(test);

    setLayout(viewLayout);
}

PluginsTab::PluginsTab(QWidget *parent)
    : QWidget(parent)
{
    QLabel *test = new QLabel;
    test->setText("ok");

    QVBoxLayout *viewLayout = new QVBoxLayout;
    viewLayout->addWidget(test);

    setLayout(viewLayout);
}

PreferencesDialog::PreferencesDialog(QWidget *parent)
    : QDialog(parent)
{
    ViewTab *viewtab = new ViewTab;
    EditorTab *editorTab = new EditorTab;
    FontTab *fontTab = new FontTab;
    PluginsTab *pluginsTab = new PluginsTab;

    QTabWidget *tabWidget = new QTabWidget;
    tabWidget->addTab(viewtab, "View");
    tabWidget->addTab(editorTab, "Editor");
    tabWidget->addTab(fontTab, "Fonts");
    tabWidget->addTab(pluginsTab, "Plugins");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->addWidget(tabWidget);
    
    setLayout(mainLayout);

    setMinimumWidth(300);
    setMinimumHeight(350);
    setWindowTitle("Preferences");
}