#ifndef HeelStats_H
#define HeelStats_H
 
#include <vtkSmartPointer.h>

#include <QMainWindow>

// Image viewer class
#include <vtkImageViewer2.h>
#include <vtkInteractorStyleImage.h>
 
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

  // Image viewer
	vtkSmartPointer<vtkImageViewer2> imageViewer;
	vtkSmartPointer<vtkInteractorStyleImage> interactorStyle;
};
 
#endif
