#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//-----------------------------------------------------------------------------
#include <QMainWindow>
//-----------------------------------------------------------------------------
namespace Ui {
    class MainWindow;
}

class WidgetBitmapEditor;
//-----------------------------------------------------------------------------
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QString findAvailableName(const QString &prefix);
    WidgetBitmapEditor *mEditor;
    void updateMenuState();

private slots:
    void on_tabWidget_tabCloseRequested(int index);
    void on_tabWidget_currentChanged(int index);
    void on_actionNew_Image_triggered();
    void on_actionNew_Font_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionClose_triggered();
    void on_actionQuit_triggered();
    void on_actionImageFlip_Horizontal_triggered();
    void on_actionImageFlip_Vertical_triggered();
    void on_actionImageRotate_90_Clockwise_triggered();
    void on_actionImageRotate_180_triggered();
    void on_actionImageRotate_90_Counter_Clockwise_triggered();
    void on_actionImageInverse_triggered();
    void on_actionImageResize_triggered();
    void on_actionImageImport_triggered();
    void on_actionImageExport_triggered();
    void on_actionFontChange_triggered();

    void mon_editor_dataChanged();
};
//-----------------------------------------------------------------------------
#endif // MAINWINDOW_H