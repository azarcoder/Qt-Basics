#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ////////BAR CHART////////////////
    QBarSet *set0 = new QBarSet("Azar");
    QBarSet *set1 = new QBarSet("Siva");
    QBarSet *set2 = new QBarSet("Bilal");
    QBarSet *set3 = new QBarSet("Yogesh");
    QBarSet *set4 = new QBarSet("Kalai");

    *set0 << 10 << 20 << 30 << 40 << 50 << 90;
    *set1 << 80 << 20 << 50 << 10 << 50 << 60;
    *set2 << 100 << 20 << 30 << 90 << 40 << 10;
    *set3 << 90 << 100 << 10 << 50 << 100 << 20;
    *set4 << 100 << 20 << 100 << 40 << 90 << 30;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chartBar = new QChart();
    chartBar->addSeries(series);
    chartBar->setTitle("Student Performance");
    chartBar->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chartBar->createDefaultAxes();
    chartBar->setAxisX(axis);
    series->attachAxis(axis);

    chartViewBar= new QChartView(chartBar);
    chartViewBar->setRenderHint(QPainter::Antialiasing);
//    ui->verticalFrame->layout()->addWidget(chartViewBar);
    chartViewBar->setParent(ui->chart1);


    ////////////PIE CHART ///////////////

    QPieSeries *seriesPie = new QPieSeries();
    seriesPie->append("Azar", 10);
    seriesPie->append("sana", 20);
    seriesPie->append("lux", 30);
    seriesPie->append("Rookie", 40);
    seriesPie->append("Sugarna", 50);

    QPieSlice *slice = seriesPie->slices().at(1);
    slice->setExploded();
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);

    QChart *chartPie = new QChart();
    chartPie->addSeries(seriesPie);
    chartPie->setTitle("Student Performance");

    chartViewPie= new QChartView(chartPie);
    chartViewPie->setRenderHint(QPainter::Antialiasing);
    chartViewPie->setParent(ui->chart2);

    //////////LINE CHAR ////////
    QLineSeries *seriesLine = new QLineSeries();
    seriesLine->append(0, 6);
    seriesLine->append(1, 15);
    seriesLine->append(2, 9);
    seriesLine->append(3, 22);
    seriesLine->append(4, 18);
    seriesLine->append(5, 11);
    seriesLine->append(6, 25);
    seriesLine->append(7, 14);
    seriesLine->append(8, 20);

    QChart *chartLine = new QChart();
    chartLine->addSeries(seriesLine);
    chartLine->createDefaultAxes();
    chartLine->setTitle("Student Performance");

    chartViewLine= new QChartView(chartLine);
    chartViewLine->setRenderHint(QPainter::Antialiasing);
    chartViewLine->setParent(ui->chart3);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    chartViewBar->resize(chartViewBar->parentWidget()->size());
    chartViewPie->resize(chartViewPie->parentWidget()->size());
    chartViewLine->resize(chartViewLine->parentWidget()->size());
}


