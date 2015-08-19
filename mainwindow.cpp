#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboTextAlign->addItem(QLatin1String("Qt::AlignLeft"),     (int)Qt::AlignLeft);
    ui->comboTextAlign->addItem(QLatin1String("Qt::AlignLeading"),  (int)Qt::AlignLeading);
    ui->comboTextAlign->addItem(QLatin1String("Qt::AlignRight"),    (int)Qt::AlignRight);
    ui->comboTextAlign->addItem(QLatin1String("Qt::AlignTrailing"), (int)Qt::AlignTrailing);
    ui->comboTextAlign->addItem(QLatin1String("Qt::AlignHCenter"),  (int)Qt::AlignHCenter);
    ui->comboTextAlign->addItem(QLatin1String("Qt::AlignJustify"),  (int)Qt::AlignJustify);
    ui->comboTextAlign->addItem(QLatin1String("Qt::AlignAbsolute"), (int)Qt::AlignAbsolute);
    ui->comboTextAlign->addItem(QLatin1String("Qt::AlignTop"),      (int)Qt::AlignTop);
    ui->comboTextAlign->addItem(QLatin1String("Qt::AlignBottom"),   (int)Qt::AlignBottom);
    ui->comboTextAlign->addItem(QLatin1String("Qt::AlignVCenter"),  (int)Qt::AlignVCenter);
    ui->comboTextAlign->addItem(QLatin1String("Qt::AlignBaseline"), (int)Qt::AlignBaseline);
    ui->comboTextAlign->addItem(QLatin1String("Qt::AlignCenter"),   (int)Qt::AlignCenter);
    ui->comboTextAlign->setCurrentIndex(ui->comboTextAlign->count()-1);

    //
    buildRow1();
    buildRow2();

    firstUpdateForAll();
    updateAllWithOptions();

    connect(ui->checkEnable, SIGNAL(clicked()),
            this, SLOT(updateAllWithOptions()));
    connect(ui->spinCurrentSection, SIGNAL(valueChanged(int)),
            this, SLOT(updateAllWithOptions()));
    connect(ui->comboTextAlign, SIGNAL(currentIndexChanged(int)),
            this, SLOT(updateAllWithOptions()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QList<QMultiSpinBox*> MainWindow::allMultiSpinBox() const
{
    return findChildren<QMultiSpinBox*>(QRegExp(".*"));
}

void MainWindow::firstUpdateForAll()
{
    QSizePolicy sp(QSizePolicy::Preferred, QSizePolicy::Maximum);
    foreach(QMultiSpinBox* m, allMultiSpinBox()) {
        m->setSizePolicy(sp);
    }
}

void MainWindow::updateAllWithOptions() const
{
    foreach(QMultiSpinBox* m, allMultiSpinBox()) {
        m->setEnabled(ui->checkEnable->isChecked());
        m->setTextAlignement((Qt::Alignment)ui->comboTextAlign->currentData().toInt());
        m->setCurrentSectionIndex(ui->spinCurrentSection->value());
    }
}

void MainWindow::buildRow1() const
{
    ui->qmspbR1C2->setPrefix("[");
    ui->qmspbR1C4->setPrefix("[");
}

void MainWindow::buildRow2() const
{
    ui->qmspbR2C2->setPrefix("[");
    ui->qmspbR2C4->setPrefix("[");

    ui->qmspbR2C1->insertSpinElement(0, new QMultiSpinBoxBinaryElement);
    ui->qmspbR2C2->insertSpinElement(0, new QMultiSpinBoxBinaryElement);
    ui->qmspbR2C3->insertSpinElement(0, new QMultiSpinBoxBinaryElement, QString("]"));
    ui->qmspbR2C4->insertSpinElement(0, new QMultiSpinBoxBinaryElement, QString("]"));
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}