#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_selectFilesButton_clicked();
    void on_searchUrlsButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<std::string> files;

    struct UrlEntry {
        std::string file;
        int line;
        int column;
        std::string url;
    };

    std::vector<UrlEntry> FindUrlsInFiles(const std::vector<std::string>& files);
};

#endif