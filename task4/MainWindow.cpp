#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <fstream>
#include <sstream>
#include <regex>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_selectFilesButton_clicked() {
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Select HTML Files"), "", tr("HTML Files (*.html *.htm)"));
    files.clear();
    for (const QString& fileName : fileNames) {
        files.push_back(fileName.toStdString());
    }
    ui->filesListWidget->clear();
    ui->filesListWidget->addItems(fileNames);
}

void MainWindow::on_searchUrlsButton_clicked() {
    if (files.empty()) {
        QMessageBox::warning(this, tr("No Files Selected"), tr("Please select HTML files first."));
        return;
    }

    auto results = FindUrlsInFiles(files);

    ui->resultsListWidget->clear();
    for (const auto& entry : results) {
        QString result = QString("File: %1, Line: %2, Column: %3, URL: %4")
                .arg(QString::fromStdString(entry.file))
                .arg(entry.line)
                .arg(entry.column)
                .arg(QString::fromStdString(entry.url));
        ui->resultsListWidget->addItem(result);
    }
}

std::vector<MainWindow::UrlEntry> MainWindow::FindUrlsInFiles(const std::vector<std::string>& files) {
    std::vector<UrlEntry> results;
    std::regex url_regex(R"((http|ftp|gopher|news|telnet|file)://[^\s/$.?#].[^\s]*)");

    for (const auto& file : files) {
        std::ifstream infile(file);
        if (!infile.is_open()) {
            continue;
        }

        std::string line;
        int line_number = 0;
        while (std::getline(infile, line)) {
            ++line_number;
            std::sregex_iterator iter(line.begin(), line.end(), url_regex);
            std::sregex_iterator end;
            while (iter != end) {
                results.push_back({file, line_number, iter->position(), iter->str()});
                ++iter;
            }
        }
    }

    return results;
}
