#ifndef HeelStats_H
#define HeelStats_H
 
#include <vtkSmartPointer.h>

#include <QMainWindow>
 
// Forward Qt class declarations
class Ui_HeelStats;
 
class HeelStats : public QMainWindow
{
  Q_OBJECT
public:
 
  // Constructor/Destructor
  HeelStats(); 
  ~HeelStats() {};
 
public slots:
 
  virtual void slotExit();
  virtual void pushButtonClicked();
  virtual void openDataSet();

private:
 
  // Designer form
  Ui_HeelStats *ui;
};
 
#endif
