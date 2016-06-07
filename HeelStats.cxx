#include "HeelStats.h"

// This is included here because it is forward declared in
// HeelStats.h
#include "ui_HeelStats.h"

#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkSmartPointer.h>
//
#include <string>
#include <iostream>
#include <QFileDialog>
#include <QString>
//
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkCommand.h>
#include <vtkObjectFactory.h>

using namespace std;
 
// Define own interaction style
class myVtkInteractorStyleImage : public vtkInteractorStyleImage
{
public:
   static myVtkInteractorStyleImage* New();
   vtkTypeMacro(myVtkInteractorStyleImage, vtkInteractorStyleImage);
 
protected:
   vtkImageViewer2* _ImageViewer;
   int _Slice;
   int _MinSlice;
   int _MaxSlice;
 
public:
   void SetImageViewer(vtkImageViewer2* imageViewer) {
      _ImageViewer = imageViewer;
      _MinSlice = imageViewer->GetSliceMin();
      _MaxSlice = imageViewer->GetSliceMax();
      _Slice = _MinSlice;
      cout << "Slicer: Min = " << _MinSlice << ", Max = " << _MaxSlice << std::endl;
   }
 
protected:
   void MoveSliceForward() {
      if(_Slice < _MaxSlice) {
         _Slice += 1;
         cout << "MoveSliceForward::Slice = " << _Slice << std::endl;
         _ImageViewer->SetSlice(_Slice);
         _ImageViewer->Render();
      }
   }
 
   void MoveSliceBackward() {
      if(_Slice > _MinSlice) {
         _Slice -= 1;
         cout << "MoveSliceBackward::Slice = " << _Slice << std::endl;
         _ImageViewer->SetSlice(_Slice);
         _ImageViewer->Render();
      }
   }
 
 
   virtual void OnKeyDown() {
      std::string key = this->GetInteractor()->GetKeySym();
      if(key.compare("Up") == 0) {
         //cout << "Up arrow key was pressed." << endl;
         MoveSliceForward();
      }
      else if(key.compare("Down") == 0) {
         //cout << "Down arrow key was pressed." << endl;
         MoveSliceBackward();
      }
      // forward event
      vtkInteractorStyleImage::OnKeyDown();
   }
 
 
   virtual void OnMouseWheelForward() {
      //std::cout << "Scrolled mouse wheel forward." << std::endl;
      MoveSliceForward();
      // don't forward events, otherwise the image will be zoomed 
      // in case another interactorstyle is used (e.g. trackballstyle, ...)
      // vtkInteractorStyleImage::OnMouseWheelForward();
   }
 
 
   virtual void OnMouseWheelBackward() {
      //std::cout << "Scrolled mouse wheel backward." << std::endl;
      if(_Slice > _MinSlice) {
         MoveSliceBackward();
      }
      // don't forward events, otherwise the image will be zoomed 
      // in case another interactorstyle is used (e.g. trackballstyle, ...)
      // vtkInteractorStyleImage::OnMouseWheelBackward();
   }
};
 
vtkStandardNewMacro(myVtkInteractorStyleImage);

// Constructor
HeelStats::HeelStats() 
{
  this->ui = new Ui_HeelStats;
  this->ui->setupUi(this);

  // Set Image Viewer, Interactor
  imageViewer = vtkSmartPointer<vtkImageViewer2>::New();
  interactorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();

  // Add renderer
  vtkSmartPointer<vtkRenderer> renderer = 
      vtkSmartPointer<vtkRenderer>::New();
  renderer->SetBackground( 0, 0, 0 );

  this->ui->qvtkWidget->GetRenderWindow()->AddRenderer( renderer );

  // Set interactor style to interactor
  vtkRenderWindowInteractor* interactor = this->ui->qvtkWidget->GetInteractor();
  interactor->SetInteractorStyle( interactorStyle );

  // Signal for opening file
  connect(this->ui->pushButton, SIGNAL( clicked() ), this, SLOT( pushButtonClicked() ) );

  connect(this->ui->actionOpen_Data_Set, SIGNAL( triggered() ), this, SLOT( openDataSet() ) );

}

void HeelStats::pushButtonClicked()
{
	cout << "Hello world" << endl;
}

void HeelStats::openDataSet()
{
  QString fileName;
  fileName = QFileDialog::getExistingDirectory( this, tr("Open Local Data Set"), "C:/Users/jperdomo", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks );
  // Convert QString to std::string
  std::string fileStd = fileName.toStdString();
  cout << "Data set opened: " << fileStd << endl;

  const char * fileChar = fileStd.c_str();
  
  // Read data set
  vtkSmartPointer<vtkDICOMImageReader> reader =
      vtkSmartPointer<vtkDICOMImageReader>::New();
  reader->SetDirectoryName( fileChar );
  reader->Update();


  // Set input to ImageViewer
  imageViewer->SetInputConnection( reader->GetOutputPort() );

  
  this->ui->qvtkWidget->SetRenderWindow( imageViewer->GetRenderWindow() );

  // Add signal to interactor for flipping slices
  vtkRenderWindowInteractor* interactor = this->ui->qvtkWidget->GetInteractor();

  // Set interactor for ImageViewer
  imageViewer->SetupInteractor( interactor );


  // Render image
  imageViewer->Render();

}

void HeelStats::slotExit()
{
  qApp->exit();
}
