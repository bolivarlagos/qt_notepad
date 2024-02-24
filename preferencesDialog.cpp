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

    QCheckBox *enableTextWrapping = new QCheckBox;
    enableTextWrapping->setText("Enable Text Wrapping");

    QCheckBox *splitTwoLine = new QCheckBox;
    splitTwoLine->setText("Do not split words over two lines");

    QVBoxLayout *wrappingLayout = new QVBoxLayout;
    wrappingLayout->addWidget(enableTextWrapping);
    wrappingLayout->addWidget(splitTwoLine);

    QGroupBox *textWrappingbox = new QGroupBox;
    textWrappingbox->setTitle("Text Wrapping");
    textWrappingbox->setLayout(wrappingLayout);

    QCheckBox *highlightLines = new QCheckBox;
    highlightLines->setText("Highlight Lines");

    QCheckBox *highlightBrackets = new QCheckBox;
    highlightBrackets->setText("Highlight Brackets");

    QVBoxLayout *highlightLayout = new QVBoxLayout;
    highlightLayout->addWidget(highlightLines);
    highlightLayout->addWidget(highlightBrackets);

    QGroupBox *highlightBox = new QGroupBox;
    highlightBox->setTitle("Highlighting");
    highlightBox->setLayout(highlightLayout);

    QVBoxLayout *viewLayout = new QVBoxLayout;
    viewLayout->addWidget(lineCheckbox);
    viewLayout->addWidget(marginCheckbox);
    viewLayout->addWidget(statusCheckbox);
    viewLayout->addWidget(overviewCheckbox);
    viewLayout->addWidget(gridCheckbox);
    viewLayout->addWidget(textWrappingbox);
    viewLayout->addWidget(highlightBox);

    setLayout(viewLayout);
}

EditorTab::EditorTab(QWidget *parent)
    : QWidget(parent)
{
    QLabel *tabWidth = new QLabel;
    tabWidth->setText("Tab Width");

    QLineEdit *tabLine = new QLineEdit;
    tabLine->setText("8");

    QPushButton *plusButton = new QPushButton;
    plusButton->setText("+");

    QPushButton *minusButton = new QPushButton;
    minusButton->setText("-");

    QCheckBox *insertCheck = new QCheckBox;
    insertCheck->setText("Insert spaces");

    QCheckBox *enableCheck = new QCheckBox;
    enableCheck->setText("Enable indentation");

    QHBoxLayout *horizontalTab = new QHBoxLayout;
    horizontalTab->addWidget(tabWidth);
    horizontalTab->addWidget(tabLine);
    horizontalTab->addWidget(minusButton);
    horizontalTab->addWidget(plusButton);

    QVBoxLayout *verticalTab = new QVBoxLayout;
    verticalTab->addLayout(horizontalTab);
    verticalTab->addWidget(insertCheck);
    verticalTab->addWidget(enableCheck);

    QGroupBox *tabStops = new QGroupBox;
    tabStops->setTitle("Tab Stops");
    tabStops->setLayout(verticalTab);

    QCheckBox *autoSave = new QCheckBox;
    autoSave->setText("Auto save file");

    QLineEdit *saveLine = new QLineEdit;
    saveLine->setText("10");

    QPushButton *saveMinus = new QPushButton;
    saveMinus->setText("-");

    QPushButton *savePlus = new QPushButton;
    savePlus->setText("+");

    QCheckBox *createBackup = new QCheckBox;
    createBackup->setText("Create Backup");
  
    QHBoxLayout *horizontalFile = new QHBoxLayout;
    horizontalFile->addWidget(autoSave);
    horizontalFile->addWidget(saveLine);
    horizontalFile->addWidget(saveMinus);
    horizontalFile->addWidget(savePlus);

    QVBoxLayout *fileSavingVertical = new QVBoxLayout;
    fileSavingVertical->addLayout(horizontalFile);
    fileSavingVertical->addWidget(createBackup);

    QGroupBox *fileSaving = new QGroupBox;
    fileSaving->setTitle("File Saving");
    fileSaving->setLayout(fileSavingVertical);

    QVBoxLayout *viewLayout = new QVBoxLayout;
    viewLayout->addWidget(tabStops);
    viewLayout->addWidget(fileSaving);

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